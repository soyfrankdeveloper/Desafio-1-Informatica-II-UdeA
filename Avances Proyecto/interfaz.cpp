#include <iostream>
#include "interfaz.h"
using namespace std;

void imprimirfigura(unsigned char figura[], int filas)
{
    for(int i=0; i < filas; i++)

    {
        for(int b = 7; b>= 0; b--)

        {
            int bit = (figura[i] >>b) & 1;
            if(bit)
                cout<< "# ";
            else
                cout <<". ";
        }

        cout <<endl;
    }
}

void imprimirconfigura(unsigned char** tablero, unsigned char figura[4], int posicionenx, int posicioneny, int alto, int ancho)
{
    int bytes = ancho / 8;

    for(int i = 0; i< alto; i++)

    {
        for(int j = 0; j< bytes; j++)

        {
            unsigned char imprimir = tablero[i][j];

            if(i >= posicioneny && i < posicioneny + 4)

            {
                int fila_relativa = i - posicioneny;

                if(posicionenx < 0)

                {
                    if(j == 0)

                    {
                        imprimir |= (unsigned char)(figura[fila_relativa] << (-posicionenx));
                    }
                }

                else
                {
                    int byte_f= posicionenx / 8;
                    int desplazamiento = posicionenx % 8;

                    if(j == byte_f)

                    {
                        imprimir |= (unsigned char)(figura[fila_relativa] >> desplazamiento);
                    }

                    else if(j == byte_f + 1 && desplazamiento != 0)

                    {
                        imprimir |= (unsigned char)(figura[fila_relativa] << (8 - desplazamiento));
                    }
                }
            }

            for(int b = 7; b >= 0; b--)

            {
                if((imprimir>> b) & 1)
                    cout << "# ";

                else
                    cout << ". ";
            }
        }
        cout << endl;
    }
}
