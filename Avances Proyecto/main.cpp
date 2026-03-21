#include <iostream>
#include "piezas.h"
#include "logica.h"
#include "interfaz.h"

using namespace std;

int main()
{
    unsigned int alto, ancho, filas;

    cout << "\nIngrese el alto del tablero: ";
    cin >> alto;

    cout << "\nIngrese el ancho del tablero (Multiplo de 8): ";
    cin >> ancho;

    if (ancho < 8 || alto < 8)

    {
        cout << "El alto y ancho no puede ser menor a 8" << endl;
        return 0;
    }

    else if (ancho % 8 != 0)
    {
        cout << "El ancho solo puede ser multiplo de 8" << endl;
        return 0;
    }

    filas = ancho / 8;
    unsigned char** tablero = new unsigned char*[alto];
    for(unsigned int i = 0; i < alto; i++)
    {
        tablero[i] = new unsigned char[filas];
        for(int j = 0; j < filas; j++) tablero[i][j] = 0;
    };


    for(unsigned int i = 0; i < alto; i++)

    {
        for(unsigned int j = 0; j < filas; j++)

        {
            tablero[i][j] = 0;
        }
    }

    unsigned char figuras[7][4] =
    {
        {0b00011000, 0b00011000, 0, 0},
        {0b00011110, 0, 0, 0},
        {0b00011100, 0b00010000, 0, 0},
        {0b00001100, 0b00011000, 0, 0},
        {0b00011000, 0b00001100, 0, 0},
        {0b00010000, 0b00011100, 0, 0},
        {0b00001000, 0b00011100, 0, 0}
    };

    bool gameover = false;

    while(!gameover)

    {
        unsigned char figura[4];
        int posicioneny = 0;
        int posicionenx = (ancho / 2) - 4;
        int estado = 0;
        int tipo = 0;

        aleatorio(figuras, figura, tipo);

        if(colision(tablero, figura, posicionenx, posicioneny, ancho, alto))

        {
            cout << "\n¡GAME OVER!" << endl;
            gameover = true;
            break;
        }

        bool fijada = false;

        while(!fijada)

        {

            for(int k = 0; k < 5; k++)
            cout << endl;

            imprimirconfigura(tablero, figura, posicionenx, posicioneny, alto, ancho);

            cout << "\nControles: a(izq) d(der) s(abajo) w(rotar) q(salir): ";

            char input;
            cin >> input;

            if(input == 'q')

            {
                gameover = true;
                break;
            }

            int nuevax = posicionenx;

            if(input == 'a')

            {
                nuevax--;
            }

            if(input == 'd')

            {
                nuevax++;
            }

            if(input == 'w')
            {
                unsigned char copia[4];

                for(int i=0; i<4; i++)

                {
                    copia[i] = figura[i];
                }

                int temporal = estado;

                rotar(copia, temporal, tipo);

                if(!colision(tablero, copia, posicionenx, posicioneny, ancho, alto))

                {
                    for(int i=0; i<4; i++)
                    {
                        figura[i] = copia[i];
                        estado = temporal;
                    }
                }
            }

            if(!colision(tablero, figura, nuevax, posicioneny, ancho, alto))

            {
                posicionenx = nuevax;
            }

            int incremento;

            if (input == 's')

            {
                incremento = 2;
            }

            else
            {
                incremento = 1;
            }

            if(!colision(tablero, figura, posicionenx, posicioneny + incremento, ancho, alto))

            {
                posicioneny += incremento;
            }

            else

            {
                if(incremento == 2 && !colision(tablero, figura, posicionenx, posicioneny + 1, ancho, alto))
                {
                    posicioneny += 1;
                }

                else
                {
                    fijada = true;
                }
            }
        }
        if(!gameover)
        {
            insertar(tablero, figura, posicionenx, posicioneny, ancho, alto);
            limpiarlineas(tablero, alto, ancho);
        }
        else
        {
            break;
        }
    }

    for(unsigned int i = 0; i < alto; i++)

    {
        delete[] tablero[i];
    }

    delete[] tablero;
    return 0;
}


