#include <iostream>
using namespace std;


void tablero()
{
    unsigned int alto, ancho, filas;
    cout<<"\nIngrese el alto del tablero(8,16,24): "<<endl;
    cin>>alto;
    cout<<"\nIngrese el ancho del tablero"<<endl;
    cin>>ancho;
    
    if ((ancho<8 || alto<8))
    {
        cout<<"El alto y ancho no puede ser menor a 8"<<endl;
    }
    else if (ancho%8!=0)
    {
        cout<<"El ancho solo puede ser multiplo de 8"<<endl;
    }
    else
    {
        filas=ancho/8;
        unsigned char tablero[alto][filas];
        for(int i = 0; i < alto; i++)
        {
            for(int j = 0; j < filas; j++)
            {
            tablero[i][j] = 0;
            }
        }
        
        for(int i = 0; i < alto; i++)
        {
            for(int j = 0; j < filas; j++)
            {
                for(int b = 7; b >= 0; b--)
                {
                     int valor = (tablero[i][j] >> b) & 1;
                     if(valor == 1)
                     cout << "# ";
                     else
                     cout << ". ";
                }   
            }
        cout << endl;
        }
    }
}

int main()
{
    tablero();
    return 0;
}