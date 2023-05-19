#include "EnemigoFinal.h"
#include <iostream>

using namespace std;

int EnemigoFinal::getAtaqueEspecial() {
	return ataqueEspecial;
}

string EnemigoFinal::getNombreAtaqueEspecial() {
	return nombreAtaqueEspecial;
}

void EnemigoFinal::setAtaqueEspecial(int pAtaqueEspecial) {
	ataqueEspecial = pAtaqueEspecial;
}

void EnemigoFinal::setNombreAtaqueEspecial(string pNombreAtaqueEspecial) {
	nombreAtaqueEspecial = pNombreAtaqueEspecial;
}

EnemigoFinal::EnemigoFinal(int pVida, int pAtaque, string pNombre, int pPosicionX, int pPosicionY, int pAtaqueEspecial, string pNombreAtaqueEspecial)
	:Personaje(pVida, pAtaque, pNombre, pPosicionX, pPosicionY) {
	ataqueEspecial = pAtaqueEspecial;
	nombreAtaqueEspecial = pNombreAtaqueEspecial;
}