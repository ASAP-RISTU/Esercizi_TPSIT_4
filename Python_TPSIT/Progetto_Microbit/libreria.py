# libreria con funzioni per il gioco
from pygame.image import load
from pygame.math import Vector2
from pygame.mixer import Sound
import pygame
import random

listaPosizioni = []


def carica_immagini(nome, dimensioni):  # carica immagini dalla cartella
    path = f"img/{nome}"
    sprite = load(path)
    sprite = pygame.transform.scale(sprite, dimensioni)
    return sprite


def carica_souno(nome):  # carica suoni dalla cartella
    path = f"sounds/{nome}"
    return Sound(path)


# specchia la posizione se si supera il bordo
def specchiaPosizione(posizione, schermo):
    x, y = posizione
    w, h = schermo.get_size()
    return Vector2(x % w, y % h)


# rimavalza la posizione se si tocca il bordo
def rimbalzaPosizione(posizione, velocità, raggio, schermo):
    aggiuntaX = random.uniform(-0.3, 0.3)
    aggiuntaY = random.uniform(-0.3, 0.3)
    Vx, Vy = velocità
    x, y = posizione
    w, h = schermo.get_size()
    if x < 0+raggio or x > w-raggio:
        Vx = -Vx+aggiuntaX
    if y < 0+raggio or y > h-raggio:
        Vy = -Vy+aggiuntaY
    return Vector2(Vx, Vy)


def rimbalza(velocità):
    Vx, Vy = velocità
    Vx = -Vx
    Vy = -Vy
    return Vector2(Vx, Vy)


"""def posizioneCasuale(schermo):  # crash per troppe ricursioni
    posX = random.randrange(50, schermo.get_width()-50)
    posY = random.randrange(50, schermo.get_height()-50)
    pos = Vector2(posX, posY)
    controllo = True

    for posizione in listaPosizioni:
        if pos.distance_to(posizione) < 150:
            controllo = False
            break
    if controllo:
        listaPosizioni.append(pos)
        return pos
    else:
        return posizioneCasuale(schermo)"""


def posizioneCasuale(schermo):
    run = True
    while run:
        controllo = True

        pos = Vector2(random.randrange(50, schermo.get_width()-50),
                      random.randrange(50, schermo.get_height()-50))
        for posizione in listaPosizioni:
            if pos.distance_to(posizione) < 150:
                controllo = False
        if controllo:
            listaPosizioni.append(pos)
            run = False
    return pos


def ramdomVector2(schermo):
    posX = random.randrange(50, schermo.get_width()-50)
    posY = random.randrange(50, schermo.get_height()-50)
    return Vector2(posX, posY)


def cancellaLista():
    listaPosizioni = []


def velocitàCasuale(minV, maxV):
    # casualizzare la velocità e la direzione
    vel = random.randrange(minV, maxV)
    angolo = random.randrange(0, 360)
    return Vector2(vel, vel).rotate(angolo)


def scriviTesto(testo, font, dim, color):
    caratteristiche = pygame.font.Font(font, dim)
    testo = caratteristiche.render(testo, True, color)
    return testo
