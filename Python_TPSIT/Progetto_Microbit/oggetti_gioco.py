from random import random
from pygame.math import Vector2  # gestione cordinate
from libreria import carica_immagini, posizioneCasuale, rimbalza, rimbalzaPosizione, specchiaPosizione, velocitàCasuale, carica_souno
from pygame.transform import rotozoom

UP = Vector2(0, -1)  # manda gli oggetti verso l'alto


class GameObject:  # classe con i metodi in comune per tutti gli oggetti
    def __init__(self, posizione, sprite, vel):
        self.posizione = Vector2(posizione)
        self.sprite = sprite
        self.raggio = sprite.get_width() / 2  # gestione collisione
        self.vel = Vector2(vel)

    def draw(self, schermo):  # disegna l'oggetto
        blit_posizione = self.posizione - Vector2(self.raggio)
        schermo.blit(self.sprite, blit_posizione)

    def move(self, shermo):  # sposta l'oggetto
        self.posizione += self.vel

    def collisione(self, asteroide):  # gestione collisione
        distanza = self.posizione.distance_to(asteroide.posizione)
        return distanza < self.raggio + asteroide.raggio

    def setPosizione(self, posizione):
        self.posizione = posizione

    def getPosizione(self):
        return self.posizione

    def setVelocità(self, velocità):
        self.vel = velocità


class Razzo(GameObject):  # classe derivata da GameObject
    ROTAZIONE = 3
    ACCELERAZIONE = 0.1
    VEL_PROIETTILE = 3

    def __init__(self, posizione, creaProiettile):
        self.creaProiettile = creaProiettile
        self.suono = carica_souno("laser.wav")
        self.suono.set_volume(0.3)
        self.direzione = Vector2(UP)

        super().__init__(posizione, carica_immagini(
            "rocket.png", (70, 120)), Vector2(0, 0))

    def ruota(self, senso):  # gestione rotazione
        segno = 1 if senso == "dx" else -1
        angolo = self.ROTAZIONE * segno
        self.direzione = self.direzione.rotate(angolo)

    def accellera(self):
        self.vel += self.direzione * self.ACCELERAZIONE

    def rallenta(self):
        self.vel -= self.direzione * self.ACCELERAZIONE

    def frena(self):
        self.vel *= 0.7

    def spara(self):  # creo proiettile
        vel_proiettile = self.direzione * self.VEL_PROIETTILE + self.vel
        proiettile = Proiettile(self.posizione, vel_proiettile)
        self.creaProiettile(proiettile)
        self.suono.set_volume(0.1)
        self.suono.play()

    def draw(self, schermo):
        angolo = self.direzione.angle_to(UP)
        spirte_ruotato = rotozoom(self.sprite, angolo, 1)
        rotated_surface_size = Vector2(spirte_ruotato.get_size())
        # ruotare il razzo in modo da centrato
        blit_position = self.posizione - rotated_surface_size / 2
        schermo.blit(spirte_ruotato, blit_position)

    def move(self, schermo):  # gestione movimento
        self.posizione = specchiaPosizione(
            self.posizione + self.vel, schermo)


class Asteroide(GameObject):
    def __init__(self, posizione, creaAsteoide, dimensione=3):

        self.dimensione = dimensione
        self.creaAsteroide = creaAsteoide
        dimensioni = {3: 1, 2: 0.5, 1: 0.25}
        scala = 100*dimensioni[dimensione]

        super().__init__(posizione, carica_immagini(
            "rock.png", (scala, scala)), velocitàCasuale(1, 2))

    def separaAsteroide(self):  # separo l'asteroide
        aggiuntaPos = [Vector2(30, 30), Vector2(-30, -30)]

        if self.dimensione > 1:  # creo asteroidi con velocià diverse
            for i in range(2):

                asteroide = Asteroide(
                    self.posizione+aggiuntaPos[i], self.creaAsteroide, self.dimensione-1)
                #asteroide.vel = velocitàCasuale(1, 2)
                self.creaAsteroide(asteroide)
                #asteroide.vel = rimbalza(self.vel)
                asteroide.vel = velocitàCasuale(1, 2)

    def move(self, schermo):
        self.vel = rimbalzaPosizione(
            self.posizione, self.vel, self.raggio, schermo)
        self.posizione += self.vel

    def scontro(self):  # gestione scontro tra asteroidi
        self.vel = rimbalza(self.vel)


class Proiettile(GameObject):
    def __init__(self, posizione, vel):
        super().__init__(posizione, carica_immagini("bullet.png", (10, 10)), vel)
