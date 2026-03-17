#include <iostream>
using namespace std;

//Función que pide alto y ancho del tablero al usuario, procesa los datos a nivel binario imprimiendo en consola el tablero de juego

void tablero()
{
    //Declaración de Variables
    unsigned int alto, ancho, filas;
    //Input del usuario
    cout<<"\nIngrese el alto del tablero (Multiplo de 8): "<<endl;
    cin>>alto;

    cout<<"\nIngrese el ancho del tablero"<<endl;
    cin>>ancho;
    //Verificación de condiciones
    if ((ancho< 8 || alto< 8))
    {
        cout<<"El alto y ancho no puede ser menor a 8"<<endl;
    }
    else if (ancho % 8 != 0)
    {
        cout<<"El ancho solo puede ser multiplo de 8"<<endl;
    }
    //Impresión del tablero en consola
    else
    {
        //¿Cuantos bytes tienen las filas del tablero?
        filas = ancho / 8;
        //Variable lineal bits del tablero
        unsigned char tablero[alto*filas];

        for(unsigned int i = 0; i < alto; i++)
        {
            for(unsigned int j=0; j<filas; j++)
            {
                unsigned int indice = i*filas + j;
                tablero[indice] = 0;
            }
        }
        //Impresion del tablero bit a bit-Declaración de un indice para ubicar y manipular bits y sobreponer figuras
        for(unsigned int i=0; i< alto; i++)
        {
            for(unsigned int j=0; j<filas;j++)
            {
                unsigned int indice=i*filas+j;

                for(int b=7; b>=0; b--)
                {
                    int valor=(tablero[indice]>>b)&1;

                    if(valor==1)
                        cout<<"# ";
                    else
                        cout<<". ";
                }
            }
            cout << endl;
        }
    }
}

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

void figuras()
{
    unsigned char O[2]= {0b00011000, 0b00011000};
    unsigned char I[1]= {0b00111100};
    unsigned char T[2]= {0b00111000, 0b00001000};
    unsigned char S[2] = {0b00011000, 0b00110000};
    unsigned char Z[2]= {0b00110000, 0b00011000};
    unsigned char J[2] = {0b00001000, 0b00011100};
    unsigned char L[2] = {0b00000100, 0b00011100};

    cout << "figura O:\n";
    imprimirfigura(O, 2);
    cout << "\nfigura I:\n";
    imprimirfigura(I, 1);
    cout << "\nfigura T:\n";
    imprimirfigura(T, 2);
    cout << "\nfigura S:\n";
    imprimirfigura(S, 2);
    cout << "\nfgura Z:\n";
    imprimirfigura(Z, 2);
    cout << "\nfigura J:\n";
    imprimirfigura(J, 2);
    cout << "\nfigura L:\n";
    imprimirfigura(L, 2);
}



//Menu de control para llamado de funciones
int main()
{
    tablero();
    figuras();
    return 0;
}
