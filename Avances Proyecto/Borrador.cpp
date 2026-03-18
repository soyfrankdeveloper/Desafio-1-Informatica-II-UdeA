#include <iostream>
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

void aleatorio(unsigned char figuras[7][2], unsigned char actual[2])
{
    static int referencia=0;
    for(int i=0;i<2;i++)
    {
        actual[i]=figuras[referencia][i];
    }
    referencia++;
    if(referencia==7)
        referencia=0;
}

void insertar(unsigned char tablero [100][100],unsigned char figura[2], int x, int y)
{
    tablero[y][x]|=figura[0];
    tablero[y+1][x] |=figura[1];
}

void moverfiguras()
{
    unsigned char figura[2]={0b00011000,0b00011000};

    int posicionenx=0;
    int posicioneny=0;
    char input;
    while(true)
    {
        cout<<posicionenx<<","<<posicioneny<<endl;
        for(int i=0; i<2; i++)
        for (int b=7;b>=0;b--)
        {
            int bit=((figura[i] >> posicionenx) >> b) & 1;
            if(bit)
                cout<<"#";
            else
                cout<<".";
        }

        cout<<"Mover a=izquiera d=derecha s=abajo q=salir: "<<endl;
        cin>>input;
        if(input=='q')
            break;
        if(input=='a')
            posicionenx--;
        if (input=='d')
            posicionenx++;
        if (input=='s')
           posicioneny++;
    }
}

int main()
{
    //Declaración de Variables
    unsigned int alto, ancho, filas;

    //Input del usuario
    cout<<"\nIngrese el alto del tablero: "<<endl;
    cin>>alto;

    cout<<"\nIngrese el ancho del tablero (Multiplo de 8): "<<endl;
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
        //Variable matricial bits del tablero
        unsigned char tablero[100][100];

        for(unsigned int i = 0; i < alto; i++)
        {
            for(unsigned int j = 0; j < filas; j++)
            {
                tablero[i][j] = 0;
            }
        }

        unsigned char figuras [7][2]=
            {
                {0b00011000,0b00011000},
                {0b00111100,0b00000000},
                {0b00111000,0b00001000},
                {0b00011000,0b00110000},
                {0b00110000,0b00011000},
                {0b00001000,0b00011100},
                {0b00000100,0b00011100}
            };

        unsigned char actual[2];

        aleatorio(figuras, actual);

        imprimirfigura(actual,2);

        insertar(tablero, actual, 0, 0);

        for(unsigned int i=0; i< alto; i++)
        {
            for(unsigned int j=0; j<filas;j++)
            {
                for(int b=7; b>=0; b--)
                {
                    int valor=(tablero[i][j]>>b)&1;

                    if(valor==1)
                        cout<<"# ";
                    else
                        cout<<". ";
                }
            }
            cout << endl;
        }
    }

    moverfiguras();

    return 0;
}
