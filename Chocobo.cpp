#include "Chocobo.h"
#include <iostream>

using namespace std;

int Chocobo::getNuezAlgarrobo() {
	return nuezAlgarrobo;
}
void Chocobo::setNuezAlgarrobo(int pNuezAlgarrobo) {
	nuezAlgarrobo = pNuezAlgarrobo;
}
int Chocobo::getHabilidadEspecial() {
	return habilidadEspecial;
}
void Chocobo::setHabilidadEspecial(int pHabilidadEspecial) {
	habilidadEspecial = pHabilidadEspecial;
}
string Chocobo::getNombreHabilidadEspecial() {
	return nombreHabilidadEspecial;
}
void Chocobo::setNombreHabilidadEspecial(string pNombreHabilidadEspecial) {
	nombreHabilidadEspecial = pNombreHabilidadEspecial;
}
int Chocobo::getHabilidadSuperEspecial() {
	return habilidadSuperEspecial;
}
void Chocobo::setHabilidadSuperEspecial(int pHabilidadSuperEspecial) {
	habilidadSuperEspecial = pHabilidadSuperEspecial;
}
string Chocobo::getNombreHabilidadSuperEspecial() {
	return nombreHabilidadSuperEspecial;
}
void Chocobo::setNombreHabilidadSuperEspecial(string pNombreHabilidadSuperEspecial) {
	nombreHabilidadSuperEspecial = pNombreHabilidadSuperEspecial;
}

Chocobo::Chocobo(int pVida, int pAtaque, string pNombre, int pPosicionX, int pPosicionY, int pNuezAlgarrobo, int pHabilidadEspecial, string pNombreHabilidadEspecial,
				int pHabilidadSuperEspecial, string pNombreHabilidadSuperEspecial)
				: Personaje(pVida, pAtaque, pNombre, pPosicionX, pPosicionY) {
	nuezAlgarrobo = pNuezAlgarrobo;
	habilidadEspecial = pHabilidadEspecial;
	nombreHabilidadEspecial = pNombreHabilidadEspecial;
	habilidadSuperEspecial = pHabilidadSuperEspecial;
	nombreHabilidadSuperEspecial = pNombreHabilidadSuperEspecial;
}

