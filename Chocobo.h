#pragma once
#include "Personaje.h"
#include <iostream>

//Si come una nuez algarrobo el chocobo evoluciona
class Chocobo : public Personaje
{
private:
	int nuezAlgarrobo;
	int habilidadEspecial;//verde, rojo, negro
	string nombreHabilidadEspecial;//verde, rojo, negro
	int habilidadSuperEspecial;
	string nombreHabilidadSuperEspecial;
public:
	int getNuezAlgarrobo();
	void setNuezAlgarrobo(int pNuez);
	int getHabilidadEspecial();
	void setHabilidadEspecial(int pHabilidadEspecial);
	string getNombreHabilidadEspecial();
	void setNombreHabilidadEspecial(string pNombreHabilidadEspecial);
	int getHabilidadSuperEspecial();
	void setHabilidadSuperEspecial(int pHabilidadSuperEspecial);
	string getNombreHabilidadSuperEspecial();
	void setNombreHabilidadSuperEspecial(string pNombreHabilidadSuperEspecial);

	Chocobo(int pVida, int pAtaque, string pNombre, int pPosicionX, int pPosicionY, int pNuezAlgarrobo, int pHabilidadEspecial, string pNombreHabilidadEspecial,
			int pHabilidadSuperEspecial, string pNombreHabilidadSuperEspecial);
	
};

