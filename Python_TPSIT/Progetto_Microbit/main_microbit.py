from microbit import *


def animazione():
    display.show(Image.DIAMOND_SMALL)
    sleep(50)
    display.show(Image.DIAMOND)
    sleep(50)
    display.show(Image.CHESSBOARD)
    sleep(50)
    display.clear()


inclinazione = ""
movimento = ""
pulsanteA, pulsanteB = "", ""


while True:
    asseX = accelerometer.get_x()  # neg=sx   pos=dx
    asseY = accelerometer.get_y()  # pos=giu  neg=avanti

    if asseX < -500:
        inclinazione = "sx"
    elif asseX > 500:
        inclinazione = "dx"
    else:
        inclinazione = "NO"

    if asseY > 500:
        movimento = "indietro"
    elif asseY < -500:
        movimento = "avanti"
    else:
        movimento = "NO"

    if button_a.get_presses():
        pulsanteA = "PREMUTO"

    else:
        pulsanteA = "NO"

    if button_b.get_presses():
        pulsanteB = "PREMUTO"
        animazione()
    else:
        pulsanteB = "NO"

    print(movimento, inclinazione, pulsanteA, pulsanteB)
    sleep(50)
