#pragma once
#include "Personaje.h"
#include <iostream>

using namespace std;

class EnemigoFinal : public Personaje
{
private:
	int ataqueEspecial;
	string nombreAtaqueEspecial;

public:
	int getAtaqueEspecial();
	string getNombreAtaqueEspecial();

	void setAtaqueEspecial(int pAtaqueEspecial);
	void setNombreAtaqueEspecial(string pNombreAtaqueEspecial);

	EnemigoFinal(int pVida, int pAtaque, string pNombre, int pPosicionX, int pPosicionY, int pAtaqueEspecial, string pNombreAtaqueEspecial);
};

