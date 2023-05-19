#include <iostream>
#include "Chocobo.h"
#include "Personaje.h"
#include <Windows.h>
#include "EnemigoFinal.h"
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
#include <conio.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

//Variables
int tablero[10][5];
int posY;
int posX;
string direccion;
bool lucha;
bool nuezAlgarrobo;
bool luchaJefe = true;
int opcion;
int ataqueRandom;
char tecla;

//Funciones
//Ruta personaje gráfico
void ruta(Chocobo& pChocobo) {
    for (size_t i = 1; i <= 5; i++)
    {
        cout << "    " << i << "    ";
    }
    for (size_t x = 0; x < 10; x++)
    {
        cout << endl;
        for (size_t y = 0; y < 5; y++)
        {
            if (tablero[x][y] == 4)
            {
                if (pChocobo.getNuezAlgarrobo() == 0)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    cout << "    C    ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else if (pChocobo.getNuezAlgarrobo() == 1)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    cout << "    C    ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else if (pChocobo.getNuezAlgarrobo() == 2)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "    C    ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else if (pChocobo.getNuezAlgarrobo() == 3)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                    cout << "    C    ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "    C    ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                
            }
            else if (tablero[x][y] == 1)
            {
                cout << "    -    ";
            }
            else if (tablero[x][y] == 2)
            {
                cout << "    -    ";
            }
            else if (tablero[x][y] == 3)
            {
                cout << "    -    ";
            }
            else
            {
                cout << "    -    ";
            }
        }
    }
}
//Random posiciones
void posicionesRandom(string pObjeto) {
    if (pObjeto == "enemigo")
    {
        posX = 1 + rand() % 8;
        posY = rand() % 5;
        if (tablero[posX][posY] == 0)
        {
            tablero[posX][posY] = 1;
        }
        else
        {
            while (tablero[posX][posY] == 1 || tablero[posX][posY] == 2 || tablero[posX][posY] == 3)
            {
                posX = 1 + rand() % 8;
                posY = rand() % 5;
            }
            tablero[posX][posY] = 1;
        }
    }
    else if (pObjeto == "nuez")
    {
        posX = 1 + rand() % 8;
        posY = rand() % 5;
        if (tablero[posX][posY] == 0)
        {
            tablero[posX][posY] = 2;
        }
        else
        {
            while (tablero[posX][posY] == 1 || tablero[posX][posY] == 2 || tablero[posX][posY] == 3)
            {
                posX = 1 + rand() % 8;
                posY = rand() % 5;
            }
            tablero[posX][posY] = 2;
        }
    }
    else
    {
        posX = 9;
        posY = rand() % 5;
        tablero[posX][posY] = 3;
    }
    
}
//Movimiento

void movimiento(Chocobo& pChocobo) {
        cout << "\nDireccion? (a/w/s/d)" << endl;
        cin >> direccion;
        if (direccion == "a")
        {
            if (pChocobo.getPosicionY() == 0)
            {
                cout << "Te sales del tablero" << endl;
            }
            else
            {
                pChocobo.setPosicionY(pChocobo.getPosicionY() - 1);
                tablero[pChocobo.getPosicionX()][pChocobo.getPosicionY()] = 4;
            }
            
        }
        else if (direccion == "w")
        {
            if (pChocobo.getPosicionX() == 0)
            {
                cout << "Te sales del tablero" << endl;
            }
            else
            {
                pChocobo.setPosicionX(pChocobo.getPosicionX() - 1);
                tablero[pChocobo.getPosicionX()][pChocobo.getPosicionY()] = 4;
            }   
        }
        else if (direccion == "s")
        {
            if (pChocobo.getPosicionX() == 9)
            {
                cout << "Te sales del tablero" << endl;
            }
            else
            {
                pChocobo.setPosicionX(pChocobo.getPosicionX() + 1);
                tablero[pChocobo.getPosicionX()][pChocobo.getPosicionY()] = 4;
            }
        }
        else if (direccion == "d")
        {
            if (pChocobo.getPosicionY() == 4)
            {
                cout << "Te sales del tablero" << endl;
            }
            else
            {
                pChocobo.setPosicionY(pChocobo.getPosicionY() + 1);
                tablero[pChocobo.getPosicionX()][pChocobo.getPosicionY()] = 4;
            }
        }
        else
        {
            cout << "El movimento se hacon con las teclas a/w/s/d" << endl;
        }
}

/*
void movimiento(Chocobo& pChocobo) {
    cout << "\nDireccion? (Utiliza las flechas de direccion!)" << endl;
    tecla = _getch();
    if (tecla == 72)
    {
        if (pChocobo.getPosicionX() == 0)
        {
            cout << "Te sales del tablero" << endl;
        }
        else
        {
            pChocobo.setPosicionX(pChocobo.getPosicionX() - 1);
            tablero[pChocobo.getPosicionX()][pChocobo.getPosicionY()] = 4;
        }
    }
    else if (tecla == 75)
    {
        if (pChocobo.getPosicionY() == 0)
        {
            cout << "Te sales del tablero" << endl;
        }
        else
        {
            pChocobo.setPosicionY(pChocobo.getPosicionY() - 1);
            tablero[pChocobo.getPosicionX()][pChocobo.getPosicionY()] = 4;
        }
    }
    else if (tecla == 77)
    {
        if (pChocobo.getPosicionY() == 4)
        {
            cout << "Te sales del tablero" << endl;
        }
        else
        {
            pChocobo.setPosicionY(pChocobo.getPosicionY() + 1);
            tablero[pChocobo.getPosicionX()][pChocobo.getPosicionY()] = 4;
        }
    }
    else if (tecla == 80)
    {
        if (pChocobo.getPosicionX() == 9)
        {
            cout << "Te sales del tablero" << endl;
        }
        else
        {
            pChocobo.setPosicionX(pChocobo.getPosicionX() + 1);
            tablero[pChocobo.getPosicionX()][pChocobo.getPosicionY()] = 4;
        }
    }
}
*/
//Reconocer casilla
void reconocerCasilla(Personaje& pPersonaje, Chocobo& pChocobo) {
    if (pPersonaje.getNombre() == "Cazador")
    {
        if (pChocobo.getPosicionX() == pPersonaje.getPosicionX() && pChocobo.getPosicionY() == pPersonaje.getPosicionY())
        {
            lucha = true;
            cout << "\nUn cazador al acecho! Acaba con el!" << endl;
            pPersonaje.setPosicionX(0);
            pPersonaje.setPosicionY(0);
            Sleep(1500);
        }
        else if (((pChocobo.getPosicionX() == pPersonaje.getPosicionX() - 1) && (pChocobo.getPosicionY() == pPersonaje.getPosicionY()))
            || ((pChocobo.getPosicionX() == pPersonaje.getPosicionX()) && (pChocobo.getPosicionY() == pPersonaje.getPosicionY() - 1))
            || ((pChocobo.getPosicionX() == pPersonaje.getPosicionX()) && (pChocobo.getPosicionY() == pPersonaje.getPosicionY() + 1))
            || (pChocobo.getPosicionX() == pPersonaje.getPosicionX() + 1) && (pChocobo.getPosicionY() == pPersonaje.getPosicionY()))
        {
            PlaySound(TEXT("escopeta.wav"), NULL, SND_SYNC);
            Sleep(1500);
            cout << "\nSnifff Snifff.... huele a polvora cerca de aqui!" << endl;
        }
        else
        {
            lucha = false;
        }
    }
    else if (pPersonaje.getNombre() == "Nuez Algarrobo")
    {
        if (pChocobo.getPosicionX() == pPersonaje.getPosicionX() && pChocobo.getPosicionY() == pPersonaje.getPosicionY())
        {
            nuezAlgarrobo = true;
            pChocobo.setNuezAlgarrobo(pChocobo.getNuezAlgarrobo() + 1);
            cout << "\nUna nuez Algarrobo! Te la comes y..." << endl;
            pPersonaje.setPosicionX(0);
            pPersonaje.setPosicionY(0);
            Sleep(1500);
            PlaySound(TEXT("evolucion.wav"), NULL, SND_SYNC);
            if (pChocobo.getNuezAlgarrobo() == 1)
            {
                pChocobo.setHabilidadEspecial(1000);
                pChocobo.setNombreHabilidadEspecial("Plumas del Fenix");
                pChocobo.setNombre("Chocobo Verde");
                pChocobo.setAtaque(750);
                cout << "Te has transformado en un " << pChocobo.getNombre() << "." << endl;
            }
            else if (pChocobo.getNuezAlgarrobo() == 2)
            {
                pChocobo.setHabilidadEspecial(3000);
                pChocobo.setNombreHabilidadEspecial("Lluvia de plumas afiladas");
                pChocobo.setNombre("Chocobo Rojo");
                pChocobo.setAtaque(1500);
                cout << "Te has transformado en un " << pChocobo.getNombre() << "." << endl;
            }
            else if (pChocobo.getNuezAlgarrobo() == 3)
            {
                pChocobo.setHabilidadSuperEspecial(2000);
                pChocobo.setNombreHabilidadSuperEspecial("Plumas oscuras del Fenix");
                pChocobo.setHabilidadEspecial(3500);
                pChocobo.setNombreHabilidadEspecial("Tormenta de plumas oscuras afiladas");
                pChocobo.setNombre("Chocobo Negro");
                pChocobo.setAtaque(2000);
                cout << "Te has transformado en un " << pChocobo.getNombre() << "." << endl;
            }
            else
            {
                pChocobo.setHabilidadSuperEspecial(10000);
                pChocobo.setNombreHabilidadSuperEspecial("Devastacion plumifera");
                pChocobo.setHabilidadEspecial(5000);
                pChocobo.setNombreHabilidadEspecial("Arco iris de plumas del Fenix");
                pChocobo.setNombre("Chocobo Dorado");
                pChocobo.setAtaque(3000);
                cout << "Te has transformado en un " << pChocobo.getNombre() << "." << endl;
            }

        }
        else if (((pChocobo.getPosicionX() == pPersonaje.getPosicionX() - 1) && (pChocobo.getPosicionY() == pPersonaje.getPosicionY()))
                    || ((pChocobo.getPosicionX() == pPersonaje.getPosicionX()) && (pChocobo.getPosicionY() == pPersonaje.getPosicionY() - 1))
                    || ((pChocobo.getPosicionX() == pPersonaje.getPosicionX()) && (pChocobo.getPosicionY() == pPersonaje.getPosicionY() + 1))
                    || (pChocobo.getPosicionX() == pPersonaje.getPosicionX() + 1) && (pChocobo.getPosicionY() == pPersonaje.getPosicionY()))
        {
            PlaySound(TEXT("wark.wav"), NULL, SND_SYNC);
            Sleep(1500);
            cout << "\nSnifff Snifff.... huele a nuez cerca de aqui!" << endl;
        }
        else
        {
            nuezAlgarrobo = false;
        }
    }
}
//Reconocer casilla Enemigo Final
void reconocerCasillaEnemigoFinal(EnemigoFinal& pEnemigoFinal, Chocobo& pChocobo) {
    if (pChocobo.getPosicionX() == pEnemigoFinal.getPosicionX() && pChocobo.getPosicionY() == pEnemigoFinal.getPosicionY())
    {
        //Cerrar archivo de audio
        const char* commandClose = "close audioFile";
        wchar_t wCommandClose[MAX_PATH];
        MultiByteToWideChar(CP_ACP, 0, commandClose, -1, wCommandClose, MAX_PATH);
        mciSendStringW(wCommandClose, NULL, 0, NULL);
        //Abrir audio
        const char* commandOpen = "open batallaFinal.wav type waveaudio alias audioFile";
        wchar_t wCommandOpen[MAX_PATH];
        MultiByteToWideChar(CP_ACP, 0, commandOpen, -1, wCommandOpen, MAX_PATH);
        mciSendStringW(wCommandOpen, NULL, 0, NULL);
        //Reproducir escape.wav
        const char* commandPlay = "play audioFile";
        wchar_t wCommandPlay[MAX_PATH];
        MultiByteToWideChar(CP_ACP, 0, commandPlay, -1, wCommandPlay, MAX_PATH);
        mciSendStringW(wCommandPlay, NULL, 0, NULL);

        luchaJefe = true;
        cout << "\nUn COMECHOCOBOS esta protegiendo la salida!!!! Debes derrotarlo para escapar." << endl;
        Sleep(1500);
    }
    else if (((pChocobo.getPosicionX() == pEnemigoFinal.getPosicionX() - 1) && (pChocobo.getPosicionY() == pEnemigoFinal.getPosicionY())) 
                || ((pChocobo.getPosicionX() == pEnemigoFinal.getPosicionX()) && (pChocobo.getPosicionY() == pEnemigoFinal.getPosicionY() - 1)) 
                || ((pChocobo.getPosicionX() == pEnemigoFinal.getPosicionX()) && (pChocobo.getPosicionY() == pEnemigoFinal.getPosicionY() + 1)))
    {
        PlaySound(TEXT("comechocobos.wav"), NULL, SND_SYNC);
        Sleep(1500);
        cout << "\nSe te han puesto las plumas de gallina!" << endl;
    }
    else
    {
        luchaJefe = false;
    }

}
//Pelea
void ataqueNormal(Personaje& pEnemigo, Chocobo& pChocobo) {
    cout << pChocobo.getNombre() << " ataca a " << pEnemigo.getNombre() << "." << endl;
    pEnemigo.setVida(pEnemigo.getVida() - pChocobo.getAtaque());
}
void ataquesChocobosEnemigo(Personaje& pEnemigo, Chocobo& pChocobo ) {
        if (pChocobo.getNuezAlgarrobo() == 0)
        {
            ataqueNormal(pEnemigo, pChocobo);
            Sleep(1500);
        }
        else if (pChocobo.getNuezAlgarrobo() == 1)
        {
            do
            {
                cout << "Escoge como actuar." << endl;
                cout << "[1] - Atacar" << endl;
                cout << "[2] - " << pChocobo.getNombreHabilidadEspecial() << endl;
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                    ataqueNormal(pEnemigo, pChocobo);
                    Sleep(1500);
                    break;
                case 2:
                    cout << pChocobo.getNombre() << " ha utilizado " << pChocobo.getNombreHabilidadEspecial() << "." << endl;
                    pChocobo.setVida(pChocobo.getVida() + pChocobo.getHabilidadEspecial());
                    cout << pChocobo.getNombre() << " ha recuperado " << pChocobo.getHabilidadEspecial() << " HP." << endl;
                    Sleep(1500);
                    break;
                default:
                    cout << "Debes seleccionar 1 o 2.";
                    Sleep(1500);
                }
            } while (opcion != 1 && opcion != 2);
        }
        else if (pChocobo.getNuezAlgarrobo() == 2)
        {
            do
            {
                cout << "Escoge como actuar." << endl;
                cout << "[1] - Atacar" << endl;
                cout << "[2] - " << pChocobo.getNombreHabilidadEspecial() << endl;
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                    ataqueNormal(pEnemigo, pChocobo);
                    Sleep(1500);
                    break;
                case 2:
                    ataqueRandom = rand() % 3;
                    if (ataqueRandom == 0)
                    {
                        cout << pChocobo.getNombre() << " ha utilizado " << pChocobo.getNombreHabilidadEspecial() << "." << endl;
                        pEnemigo.setVida(pEnemigo.getVida() - pChocobo.getHabilidadEspecial());
                        Sleep(1500);
                    }
                    else
                    {
                        cout << pChocobo.getNombreHabilidadEspecial() << " no ha funcionado esta vez!" << endl;
                        Sleep(1500);
                    }
                    break;
                default:
                    cout << "Debes seleccionar 1 o 2.";
                    Sleep(1500);
                }
            } while (opcion != 1 && opcion != 2);
        }
        else if (pChocobo.getNuezAlgarrobo() == 3)
        {
            do
            {
                cout << "Escoge como actuar." << endl;
                cout << "[1] - Atacar" << endl;
                cout << "[2] - " << pChocobo.getNombreHabilidadEspecial() << endl;
                cout << "[3] - " << pChocobo.getNombreHabilidadSuperEspecial() << endl;
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                    ataqueNormal(pEnemigo, pChocobo);
                    Sleep(1500);
                    break;
                case 2:
                    ataqueRandom = rand() % 2;
                    if (ataqueRandom == 0)
                    {
                        cout << pChocobo.getNombre() << " ha utilizado " << pChocobo.getNombreHabilidadEspecial() << "." << endl;
                        pEnemigo.setVida(pEnemigo.getVida() - pChocobo.getHabilidadEspecial());
                        Sleep(1500);
                    }
                    else
                    {
                        cout << pChocobo.getNombreHabilidadEspecial() << " no ha funcionado esta vez!" << endl;
                        Sleep(1500);
                    }
                    break;
                case 3:
                    cout << pChocobo.getNombre() << " ha utilizado " << pChocobo.getNombreHabilidadSuperEspecial() << "." << endl;
                    pChocobo.setVida(pChocobo.getVida() + pChocobo.getHabilidadSuperEspecial());
                    cout << pChocobo.getNombre() << " ha recuperado " << pChocobo.getHabilidadSuperEspecial() << " HP." << endl;
                    Sleep(1500);
                    break;
                default:
                    cout << "Debes seleccionar 1, 2 o 3.";
                    Sleep(1500);
                }
            } while (opcion != 1 && opcion != 2 && opcion != 3);
        }
        else
        {
            do
            {
                cout << "Escoge como actuar." << endl;
                cout << "[1] - Atacar" << endl;
                cout << "[2] - " << pChocobo.getNombreHabilidadSuperEspecial() << endl;
                cout << "[3] - " << pChocobo.getNombreHabilidadEspecial() << endl;
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                    ataqueNormal(pEnemigo, pChocobo);
                    Sleep(1500);
                    break;
                case 2:
                    ataqueRandom = rand() % 4;
                    if (ataqueRandom == 3)
                    {
                        cout << pChocobo.getNombre() << " ha utilizado " << pChocobo.getNombreHabilidadSuperEspecial() << "." << endl;
                        pEnemigo.setVida(pEnemigo.getVida() - pChocobo.getHabilidadSuperEspecial());
                        Sleep(1500);
                    }
                    else
                    {
                        cout << pChocobo.getNombreHabilidadSuperEspecial() << " no ha funcionado esta vez!" << endl;
                        Sleep(1500);
                    }
                    break;
                case 3:
                    cout << pChocobo.getNombre() << " ha utilizado " << pChocobo.getNombreHabilidadEspecial() << "." << endl;
                    pChocobo.setVida(pChocobo.getVida() + pChocobo.getHabilidadEspecial());
                    cout << pChocobo.getNombre() << " ha recuperado " << pChocobo.getHabilidadEspecial() << " HP." << endl;
                    Sleep(1500);
                    break;
                default:
                    cout << "Debes seleccionar 1, 2 o 3.";
                    Sleep(1500);
                }
            } while (opcion != 1 && opcion != 2 && opcion != 3);
        }
}
void ataquesChocobosEnemigoFinal(EnemigoFinal& pEnemigoFinal, Chocobo& pChocobo) {
    if (pChocobo.getNuezAlgarrobo() == 0)
    {
        ataqueNormal(pEnemigoFinal, pChocobo);
        Sleep(1500);
    }
    else if (pChocobo.getNuezAlgarrobo() == 1)
    {
        do
        {
            cout << "Escoge como actuar." << endl;
            cout << "[1] - Atacar" << endl;
            cout << "[2] - " << pChocobo.getNombreHabilidadEspecial() << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                ataqueNormal(pEnemigoFinal, pChocobo);
                Sleep(1500);
                break;
            case 2:
                cout << pChocobo.getNombre() << " ha utilizado " << pChocobo.getNombreHabilidadEspecial() << "." << endl;
                pChocobo.setVida(pChocobo.getVida() + pChocobo.getHabilidadEspecial());
                cout << pChocobo.getNombre() << " ha recuperado " << pChocobo.getHabilidadEspecial() << " HP." << endl;
                Sleep(1500);
                break;
            default:
                cout << "Debes seleccionar 1 o 2.";
                Sleep(1500);
            }
        } while (opcion != 1 && opcion != 2);
    }
    else if (pChocobo.getNuezAlgarrobo() == 2)
    {
        do
        {
            cout << "Escoge como actuar." << endl;
            cout << "[1] - Atacar" << endl;
            cout << "[2] - " << pChocobo.getNombreHabilidadEspecial() << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                ataqueNormal(pEnemigoFinal, pChocobo);
                Sleep(1500);
                break;
            case 2:
                ataqueRandom = rand() % 3;
                if (ataqueRandom == 0)
                {
                    cout << pChocobo.getNombre() << " ha utilizado " << pChocobo.getNombreHabilidadEspecial() << "." << endl;
                    pEnemigoFinal.setVida(pEnemigoFinal.getVida() - pChocobo.getHabilidadEspecial());
                    Sleep(1500);
                }
                else
                {
                    cout << pChocobo.getNombreHabilidadEspecial() << " no ha funcionado esta vez!" << endl;
                    Sleep(1500);
                }
                break;
            default:
                cout << "Debes seleccionar 1 o 2.";
                Sleep(1500);
            }
        } while (opcion != 1 && opcion != 2);
    }
    else if (pChocobo.getNuezAlgarrobo() == 3)
    {
        do
        {
            cout << "Escoge como actuar." << endl;
            cout << "[1] - Atacar" << endl;
            cout << "[2] - " << pChocobo.getNombreHabilidadEspecial() << endl;
            cout << "[3] - " << pChocobo.getNombreHabilidadSuperEspecial() << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                ataqueNormal(pEnemigoFinal, pChocobo);
                Sleep(1500);
                break;
            case 2:
                ataqueRandom = rand() % 2;
                if (ataqueRandom == 0)
                {
                    cout << pChocobo.getNombre() << " ha utilizado " << pChocobo.getNombreHabilidadEspecial() << "." << endl;
                    pEnemigoFinal.setVida(pEnemigoFinal.getVida() - pChocobo.getHabilidadEspecial());
                    Sleep(1500);
                }
                else
                {
                    cout << pChocobo.getNombreHabilidadEspecial() << " no ha funcionado esta vez!" << endl;
                    Sleep(1500);
                }
                break;
            case 3:
                cout << pChocobo.getNombre() << " ha utilizado " << pChocobo.getNombreHabilidadSuperEspecial() << "." << endl;
                pChocobo.setVida(pChocobo.getVida() + pChocobo.getHabilidadSuperEspecial());
                cout << pChocobo.getNombre() << " ha recuperado " << pChocobo.getHabilidadSuperEspecial() << " HP." << endl;
                Sleep(1500);
                break;
            default:
                cout << "Debes seleccionar 1, 2 o 3.";
                Sleep(1500);
            }
        } while (opcion != 1 && opcion != 2 && opcion != 3);
    }
    else
    {
        do
        {
            cout << "Escoge como actuar." << endl;
            cout << "[1] - Atacar" << endl;
            cout << "[2] - " << pChocobo.getNombreHabilidadSuperEspecial() << endl;
            cout << "[3] - " << pChocobo.getNombreHabilidadEspecial() << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                ataqueNormal(pEnemigoFinal, pChocobo);
                Sleep(1500);
                break;
            case 2:
                ataqueRandom = rand() % 4;
                if (ataqueRandom == 3)
                {
                    cout << pChocobo.getNombre() << " ha utilizado " << pChocobo.getNombreHabilidadSuperEspecial() << "." << endl;
                    pEnemigoFinal.setVida(pEnemigoFinal.getVida() - pChocobo.getHabilidadSuperEspecial());
                    Sleep(1500);
                }
                else
                {
                    cout << pChocobo.getNombreHabilidadSuperEspecial() << " no ha funcionado esta vez!" << endl;
                    Sleep(1500);
                }
                break;
            case 3:
                cout << pChocobo.getNombre() << " ha utilizado " << pChocobo.getNombreHabilidadEspecial() << "." << endl;
                pChocobo.setVida(pChocobo.getVida() + pChocobo.getHabilidadEspecial());
                cout << pChocobo.getNombre() << " ha recuperado " << pChocobo.getHabilidadEspecial() << " HP." << endl;
                Sleep(1500);
                break;
            default:
                cout << "Debes seleccionar 1, 2 o 3.";
                Sleep(1500);
            }
        } while (opcion != 1 && opcion != 2 && opcion != 3);
    }
}
void batalla(bool pLuchaEnemigo, Personaje& pEnemigo, Chocobo& pChocobo) {
    if (pLuchaEnemigo == true)
    {
        while (pLuchaEnemigo == true && pChocobo.getVida() > 0)
        {
            ataquesChocobosEnemigo(pEnemigo, pChocobo);
            if (pEnemigo.getVida() <= 0)
            {
                cout << "A " << pEnemigo.getNombre() << " le quedan 0 puntos de vida." << endl;
                pLuchaEnemigo = false;
                lucha = false;
                pEnemigo.setPosicionX(0);
                pEnemigo.setPosicionY(0);
                Sleep(1500);
            }
            else
            {
                cout << "A " << pEnemigo.getNombre() << " le quedan " << pEnemigo.getVida() << " puntos de vida." << endl;
                cout << pEnemigo.getNombre() << " ataca a " << pChocobo.getNombre() << "." << endl;
                pChocobo.setVida(pChocobo.getVida() - pEnemigo.getAtaque());
                Sleep(1500);
            }
            if (pChocobo.getVida() < 0)
            {
                cout << "A " << pChocobo.getNombre() << " le quedan 0 puntos de vida." << endl;
                Sleep(1500);
            }
            else
            {
                cout << "A " << pChocobo.getNombre() << " le quedan " << pChocobo.getVida() << " puntos de vida." << endl;
                Sleep(1500);
            }
        }
    }
}
void batallaJefe(bool pLuchaJefe, EnemigoFinal& pEnemigoFinal, Chocobo& pChocobo){
    if (pLuchaJefe == true)
    {
        while (pLuchaJefe == true && pChocobo.getVida() > 0)
        {
            ataquesChocobosEnemigoFinal(pEnemigoFinal, pChocobo);
            if (pEnemigoFinal.getVida() <= 0)
            {
                cout << "A " << pEnemigoFinal.getNombre() << " le quedan 0 puntos de vida." << endl;
                pLuchaJefe = false;
                luchaJefe = false;
                Sleep(1500);
            }
            else
            {
                cout << "A " << pEnemigoFinal.getNombre() << " le quedan " << pEnemigoFinal.getVida() << " puntos de vida." << endl;
                Sleep(1500);
                int randomAtaque = rand() % 2;

                if (randomAtaque == 0)
                {
                    cout << pEnemigoFinal.getNombre() << " ataca a " << pChocobo.getNombre() << "." << endl;
                    pChocobo.setVida(pChocobo.getVida() - pEnemigoFinal.getAtaque());
                    Sleep(1500);
                }
                else
                {
                    cout << pEnemigoFinal.getNombre() << " ataca a " << pChocobo.getNombre() << " usando su habilidad " << pEnemigoFinal.getNombreAtaqueEspecial() << "." << endl;
                    pChocobo.setVida(pChocobo.getVida() - pEnemigoFinal.getAtaqueEspecial());
                    Sleep(1500);
                }
                if (pChocobo.getVida() < 0)
                {
                    cout << "A " << pChocobo.getNombre() << " le quedan 0 puntos de vida." << endl;
                    Sleep(1500);
                }
                else
                {
                    cout << "A " << pChocobo.getNombre() << " le quedan " << pChocobo.getVida() << " puntos de vida." << endl;
                    Sleep(1500);
                }
            }
        }
    }
}
//Intro
void intro() {
    PlaySound(TEXT("ronquido.wav"), NULL, SND_SYNC);
    cout << "Eh!!! Despierta!!!" << endl;
    Sleep(1000);
    PlaySound(TEXT("ronquido.wav"), NULL, SND_SYNC);
    PlaySound(TEXT("golpePuerta.wav"), NULL, SND_SYNC);
    cout << "Despierta Chocobo!!!" << endl;
    PlaySound(TEXT("wark.wav"), NULL, SND_SYNC);
    cout << "Tienes que salir de aqui cuanto antes! Shinra Corp quiere destruir el pueblo chocobo. Debes huir del laboratorio \ny ayudarlos." << endl;
    Sleep(3000);
    PlaySound(TEXT("wark.wav"), NULL, SND_SYNC);
    cout << "Que como vas a salir? He preparado tu huida. Debes escoger una de las 5 puertas de ahi delante y cruzar los tuneles \nhasta encontrar la salida!!" << endl;
    Sleep(4000);
    cout << "Ten cuidado! En el momento que abra tu camara saltara la alarma. Habra cazadores por el camino que \nquerran acabar contigo, pero no te preocupes." << endl;
    Sleep(4000);
    cout << "He dejado 4 NUECES ALGARROBO por los tuneles. Si las encuentras podras conseguir nuevas habilidades que te ayudaran \na escapar. Preparado?" << endl;
    Sleep(4000);
    PlaySound(TEXT("wark.wav"), NULL, SND_SYNC);
    Sleep(1000);
    cout << "Alejate! Voy a abrir tu camara." << endl;
    Sleep(3000);
    PlaySound(TEXT("puerta.wav"), NULL, SND_SYNC);
    cout << "Buena suerte Chocobo!!!" << endl;
    Sleep(3000);
    
}

int main()
{
    srand(time(NULL));
    //iniciar tablero
    for (size_t x = 0; x < 10 ; x++)
    {
        for (size_t y = 0; y < 5; y++)
        {
            tablero[x][y] = 0;
        }
    }
    //Intro
    intro();
    //Posicion inicio de personaje
    Chocobo chocobo(9999, 250, "Chocobo", 0, 0, 0, 0, "sin nombre", 0, "sin nombre");
    while (posY > 5 || posY < 1)
    {
        cout << "Por que puerta quieres empezar tu escapada? (1, 2 ,3 , 4 o 5)?" << endl;
        cin >> posY;
    }
    chocobo.setPosicionY(posY - 1);
    tablero[0][posY - 1] = 4;
    PlaySound(TEXT("alarma.wav"), NULL, SND_SYNC);
    //Creación de enemigos
    posicionesRandom("enemigo");
    Personaje enemigo1(500, 200, "Cazador", posX, posY);
    posicionesRandom("enemigo");
    Personaje enemigo2(500, 200, "Cazador", posX, posY);
    posicionesRandom("enemigo");
    Personaje enemigo3(500, 200, "Cazador", posX, posY);
    posicionesRandom("enemigo");
    Personaje enemigo4(500, 200, "Cazador", posX, posY);
    posicionesRandom("enemigoFinal");
    EnemigoFinal enemigoFinal(9999, 2000, "Comechocobos", posX, posY, 4000, "Carne Carne Carne");
    //Creacion de nueces algarrobo
    posicionesRandom("nuez");
    Personaje nuez1(0, 0, "Nuez Algarrobo", posX, posY);
    posicionesRandom("nuez");
    Personaje nuez2(0, 0, "Nuez Algarrobo", posX, posY);
    posicionesRandom("nuez");
    Personaje nuez3(0, 0, "Nuez Algarrobo", posX, posY);
    posicionesRandom("nuez");
    Personaje nuez4(0, 0, "Nuez Algarrobo", posX, posY);
    
    //Abrir archivo escape.wav
    const char* commandOpen = "open escape.wav type waveaudio alias audioFile"; 
    wchar_t wCommandOpen[MAX_PATH]; 
    MultiByteToWideChar(CP_ACP, 0, commandOpen, -1, wCommandOpen, MAX_PATH); 
    mciSendStringW(wCommandOpen, NULL, 0, NULL);
    //Reproducir escape.wav
    const char* commandPlay = "play audioFile"; 
    wchar_t wCommandPlay[MAX_PATH]; 
    MultiByteToWideChar(CP_ACP, 0, commandPlay, -1, wCommandPlay, MAX_PATH); 
    mciSendStringW(wCommandPlay, NULL, 0, NULL);

    while (enemigoFinal.getVida() > 0 && chocobo.getVida() > 0)
    {
        //PlaySound(TEXT("escape.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        ruta(chocobo);
        movimiento(chocobo);
        cout << endl;
        reconocerCasilla(enemigo1, chocobo);
        batalla(lucha, enemigo1, chocobo);
        reconocerCasilla(enemigo2, chocobo);
        batalla(lucha, enemigo2, chocobo);
        reconocerCasilla(enemigo3, chocobo);
        batalla(lucha, enemigo3, chocobo);
        reconocerCasilla(enemigo4, chocobo);
        batalla(lucha, enemigo4, chocobo);
        reconocerCasilla(nuez1, chocobo);
        reconocerCasilla(nuez2, chocobo);
        reconocerCasilla(nuez3, chocobo);
        reconocerCasilla(nuez4, chocobo);
        reconocerCasillaEnemigoFinal(enemigoFinal, chocobo);
        batallaJefe(luchaJefe, enemigoFinal, chocobo);
        system("pause");
        system("cls");
    }
    if (enemigoFinal.getVida() <= 0)
    {
        //Cerrar archivo de audio
        const char* commandClose = "close audioFile";
        wchar_t wCommandClose[MAX_PATH];
        MultiByteToWideChar(CP_ACP, 0, commandClose, -1, wCommandClose, MAX_PATH);
        mciSendStringW(wCommandClose, NULL, 0, NULL);

        PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC);
        cout << "Has ganado contra " << enemigoFinal.getNombre() << ". La salida esta justo delante de ti." << endl;
        Sleep(1000);
        cout << "Gracias a tu proeza podras avisar a la raza chocobo del ataque inminente." << endl;
        Sleep(1000);
        cout << "Ademas, gracias a tu aventura has conseguido nuevas habilidades y experiencias para hacer frente a lo que venga!!" << endl;
        Sleep(1000);
        system("pause");
    }
    else
    {
        //Cerrar archivo de audio
        const char* commandClose = "close audioFile"; 
        wchar_t wCommandClose[MAX_PATH]; 
        MultiByteToWideChar(CP_ACP, 0, commandClose, -1, wCommandClose, MAX_PATH); 
        mciSendStringW(wCommandClose, NULL, 0, NULL);

        cout << "No has sobrevivido a tu escapada. La raza chocobo corre un grave peligro!!!\n" << endl;
        cout << "------------------- GAME OVER -------------------" << endl;
        PlaySound(TEXT("gameover.wav"), NULL, SND_SYNC);
    }
}