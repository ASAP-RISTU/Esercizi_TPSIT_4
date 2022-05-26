import pygame
from libreria import carica_immagini, posizioneCasuale, carica_souno, cancellaLista, ramdomVector2, scriviTesto
from oggetti_gioco import Asteroide, Razzo
import time
from pygame.math import Vector2
from threading import Thread
import queue
import serial

CODA_MOVIMENTI = queue.Queue()


class Asteroids():
    DISTANZA_MINIMA = 250
    WIDTH = 1000
    HEIGHT = 800
    MAX_LEVEL = 2
    N_VITE = 3

    def __init__(self):
        pygame.init()
        pygame.display.set_caption("Space Rocks")
        self.screen = pygame.display.set_mode((self.WIDTH, self. HEIGHT))
        self.background = carica_immagini(
            "space.gif", (self.WIDTH, self.HEIGHT))
        self.asteroidi = []
        self.proiettili = []
        self.razzo = Razzo((self.WIDTH/2, self.HEIGHT/2),
                           self.proiettili.append)
        self.nLivello = 1

        self.soundTrack = carica_souno("track.mp3")
        self.soundTrack.set_volume(0.1)
        self.soundEsplosione = carica_souno("explosion.mp3")
        self.soundEsplosione.set_volume(1)
        self.clock = pygame.time.Clock()  # gestione tempo
        self.direzione, self.movimento = None, None
        self.pulsanteA, self.pulsanteB = None, None
        self.continua = True

    def creaAsteroidi(self):
        if len(self.asteroidi) < 1:
            cancellaLista()
            for _ in range(self.nLivello):  # spawn asteroidi lontani dal razzo
                while True:
                    posizione = posizioneCasuale(self.screen)
                    if posizione.distance_to(self.razzo.posizione) > self.DISTANZA_MINIMA:
                        break

                self.asteroidi.append(
                    Asteroide(posizione, self.asteroidi.append))

    def getOggetti(self):
        # passo gli oggetti dentro le liste
        oggetti = [*self.asteroidi, *self.proiettili]

        if self.razzo:
            oggetti.append(self.razzo)
        return oggetti

    def draw(self):
        self.screen.blit(self.background, (0, 0))
        for oggetto in self.getOggetti():
            oggetto.draw(self.screen)
        pygame.display.flip()
        self.clock.tick(50)

    def gestioneInput(self):  # gioco sia da tastiera che da microbit
        for event in pygame.event.get():
            if event.type == pygame.QUIT or (event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE):
                self.continua = False
            # dentro al ciclo così non si può spare all' inifito
            elif self.razzo:
                if (event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE):
                    self.razzo.spara()

        tasto = pygame.key.get_pressed()

        if self.razzo:  # verifico che esita il razzo
            if tasto[pygame.K_LEFT] or self.direzione == "sx":  # rotazione
                self.razzo.ruota("sx")
            elif tasto[pygame.K_RIGHT] or self.direzione == "dx":
                self.razzo.ruota("dx")

            if tasto[pygame.K_UP] or self.movimento == "avanti":  # movimento
                self.razzo.accellera()
            elif tasto[pygame.K_DOWN] or self.movimento == "indietro":
                self.razzo.rallenta()

            if self.pulsanteB == "PREMUTO":
                self.razzo.spara()
                self.pulsanteB = "NO"

            if self.pulsanteA == "PREMUTO":  # frenare il razzo
                self.razzo.frena()

    def gameLogic(self):
        oggetti = self.getOggetti()
        for oggetto in oggetti:
            oggetto.move(self.screen)

        # collisione razzo-asteroide
        if self.razzo:
            for asteroide in self.asteroidi:
                if self.razzo.collisione(asteroide):
                    self.ripristina()

        # collisione asteroide-asteroide
        for asteroide in self.asteroidi:
            for asteroide2 in self.asteroidi:
                if asteroide != asteroide2:
                    if asteroide.collisione(asteroide2):
                        asteroide.scontro()

        # uso i puntatori[:] poichè evito ValueError: list.remove(x): x not in list
        # modifico la lista senza modificare il puntatore alla lista

        # eliminazione proiettile
        for proiettile in self.proiettili[:]:
            if not self.screen.get_rect().collidepoint(proiettile.posizione):
                self.proiettili.remove(proiettile)

        # collisione proiettile-asteroide
        for proiettile in self.proiettili[:]:
            for asteroide in self.asteroidi[:]:
                if proiettile.collisione(asteroide):
                    self.asteroidi.remove(asteroide)
                    self.proiettili.remove(proiettile)
                    asteroide.separaAsteroide()

        # controllo fine livello/vittoria
        if len(self.asteroidi) == 0:
            self.nLivello += 1

            if self.nLivello <= self.MAX_LEVEL:
                self.creaAsteroidi()
            elif self.nLivello > self.MAX_LEVEL:
                self.win()

    def ripristina(self):  # ripristina il gioco dopo una collisione
        self.soundEsplosione.play()
        scheletro = carica_immagini("skull.png", (130, 160))
        scheletroRect = scheletro.get_rect()
        scheletroRect.center = self.razzo.posizione
        self.screen.blit(scheletro, scheletroRect)
        pygame.display.flip()
        self.N_VITE -= 1

        time.sleep(1)
        # ripristino  posizione del razzo
        self.razzo.setPosizione(self.newPosizioneRazzo())
        self.razzo.setVelocità(Vector2(0, 0))
        self.proiettili.clear()

    # gestione dello spaw del razzo dopo una collisione
    def newPosizioneRazzo(self):
        run = True
        while run:
            controllo = True
            temp = ramdomVector2(self.screen)

            for asteroide in self.asteroidi:
                # controllo distanza minima
                if temp.distance_to(asteroide.getPosizione()) < self.DISTANZA_MINIMA:
                    controllo = False
            if controllo == True:
                run = False
        return temp

    def main_loop(self):

        while self.N_VITE > 0 and self.continua == True:
            temp = []
            # prendo i dati dalla coda
            try:
                temp = CODA_MOVIMENTI.get_nowait()  # get_nowait funzione non bloccante
            except queue.Empty:
                pass
            if len(temp) == 4:
                self.movimento = temp[0]  # assegno i dati alle variabili
                self.direzione = temp[1]
                self.pulsanteA = temp[2]
                self.pulsanteB = temp[3]
            self.gestioneInput()
            self.gameLogic()
            self.draw()
        if self.N_VITE == 0:
            self.gameOver()

    def starter(self):
        logo = carica_immagini("logo.png", (516, 132))
        logoRect = logo.get_rect()
        logoRect.center = (self.WIDTH/2, self.HEIGHT/2-100)

        testo = "PRESS ANY KEY AND GET READY"
        testo = scriviTesto(
            testo, 'freesansbold.ttf', 36, (255, 255, 0))
        testoRect = testo.get_rect()
        testoRect.center = (self.WIDTH/2,  self.HEIGHT/2)
        self.screen.blit(self.background, (0, 0))
        self.screen.blit(testo, testoRect)
        self.screen.blit(logo, logoRect)

        pygame.display.flip()

        continua = True
        while continua:
            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    continua = False
                    self.soundTrack.play()

    def gameOver(self):
        imgGameOver = carica_immagini("GameOver.png", (400, 200))
        imgRect = imgGameOver.get_rect()
        imgRect.center = (self.WIDTH/2, self.HEIGHT/2-200)
        testo = "ANY KEY = RESTART / ESC = QUIT"
        testo = scriviTesto(testo, 'freesansbold.ttf', 36, (255, 255, 0))
        testoRect = testo.get_rect()
        testoRect.center = (self.WIDTH/2,  self.HEIGHT/2)
        self.screen.blit(self.background, (0, 0))
        self.screen.blit(testo, testoRect)
        self.screen.blit(imgGameOver, imgRect)
        pygame.display.flip()

        continua = True
        while continua:
            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_ESCAPE:
                        continua = False
                        self.continua = False  # quell del main loop
                    else:
                        continua = False

        # ripristino tutto
        if self.continua == True:
            self.N_VITE = 3
            self.razzo.setPosizione((self.WIDTH/2, self.HEIGHT/2))
            self.razzo.setVelocità(Vector2(0, 0))
            self.asteroidi.clear()  # pulisco la lista degli asteroidi e dei proiettili
            self.proiettili.clear()
            self.creaAsteroidi()
            self.main_loop()

    def win(self):
        imgWin = carica_immagini("win.png", (400, 200))
        imgRect = imgWin.get_rect()
        imgRect.center = (self.WIDTH/2, self.HEIGHT/2-200)
        self.screen.blit(self.background, (0, 0))
        self.screen.blit(imgWin, imgRect)
        pygame.display.flip()

        continua = True
        while continua:
            for event in pygame.event.get():
                if (event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE) or event.type == pygame.QUIT:
                    continua = False
                    self.soundTrack.stop()
                    self.continua = False
                    print("HAI VINTO")


class Read_Microbit(Thread):
    def __init__(self):
        Thread.__init__(self)
        self.running = True

    def terminate(self):
        self.running = False

    def run(self):
        port = "/dev/ttyACM0"
        s = serial.Serial(port)
        s.baudrate = 115200

        while self.running:
            data = s.readline().decode()
            data = data[0:-2]
            temp = data.split(" ")
            CODA_MOVIMENTI.put(temp)
            time.sleep(0.07)


def main():
    t1 = Read_Microbit()
    gioco = Asteroids()
    gioco.starter()
    gioco.creaAsteroidi()
    t1.start()

    gioco.main_loop()
    t1.terminate()
    t1.join()


if __name__ == "__main__":
    main()
