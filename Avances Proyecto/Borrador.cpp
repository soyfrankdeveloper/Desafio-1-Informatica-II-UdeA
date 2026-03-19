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

void aleatorio(unsigned char figuras[7][4], unsigned char actual[4])
{
    static int referencia=0;
    for(int i=0;i<4;i++)
    {
        actual[i]=figuras[referencia][i];
    }
    referencia++;
    if(referencia==7)
        referencia=0;
}

void insertar(unsigned char tablero[100][100], unsigned char figura[4], int x, int y)
{
    for(int i=0;i<4;i++)
    {
        int byte=x/8;
        int desplazamiento=x%8;

        unsigned char parte=figura[i] >> desplazamiento;
        tablero[y+i][byte]|=parte;
        if(desplazamiento!=0)
        {
            unsigned char sobrante=figura[i] << (8-desplazamiento);
            tablero[y+i][byte+1]|=sobrante;
        }
    }
}

void rotar(unsigned char figura[4],int &estado,int tipo)
{
    estado=(estado+1)%4;

    if(tipo==0)
    {
        figura[0]=0;figura[1]=0b00110000;figura[2]=0b00110000;figura[3]=0;
    }
    if(tipo==1)
    {
        if(estado==0){figura[0]=0;figura[1]=0b00111100;figura[2]=0;figura[3]=0;}
        if(estado==1){figura[0]=0b00100000;figura[1]=0b00100000;figura[2]=0b00100000;figura[3]=0b00100000;}
        if(estado==2){figura[0]=0;figura[1]=0b00111100;figura[2]=0;figura[3]=0;}
        if(estado==3){figura[0]=0b00100000;figura[1]=0b00100000;figura[2]=0b00100000;figura[3]=0b00100000;}
    }
    if(tipo==2)
    {
        if(estado==0){figura[0]=0;figura[1]=0b00111000;figura[2]=0b00010000;figura[3]=0;}
        if(estado==1){figura[0]=0b00010000;figura[1]=0b00110000;figura[2]=0b00010000;figura[3]=0;}
        if(estado==2){figura[0]=0b00010000;figura[1]=0b00111000;figura[2]=0;figura[3]=0;}
        if(estado==3){figura[0]=0b00010000;figura[1]=0b00011000;figura[2]=0b00010000;figura[3]=0;}
    }
    if(tipo==3)
    {
        if(estado==0){figura[0]=0;figura[1]=0b00011000;figura[2]=0b00110000;figura[3]=0;}
        if(estado==1){figura[0]=0b00100000;figura[1]=0b00110000;figura[2]=0b00010000;figura[3]=0;}
        if(estado==2){figura[0]=0;figura[1]=0b00011000;figura[2]=0b00110000;figura[3]=0;}
        if(estado==3){figura[0]=0b00100000;figura[1]=0b00110000;figura[2]=0b00010000;figura[3]=0;}
    }
    if(tipo==4)
    {
        if(estado==0){figura[0]=0;figura[1]=0b00110000;figura[2]=0b00011000;figura[3]=0;}
        if(estado==1){figura[0]=0b00010000;figura[1]=0b00110000;figura[2]=0b00100000;figura[3]=0;}
        if(estado==2){figura[0]=0;figura[1]=0b00110000;figura[2]=0b00011000;figura[3]=0;}
        if(estado==3){figura[0]=0b00010000;figura[1]=0b00110000;figura[2]=0b00100000;figura[3]=0;}
    }
    if(tipo==5)
    {
        if(estado==0){figura[0]=0;figura[1]=0b00100000;figura[2]=0b00111000;figura[3]=0;}
        if(estado==1){figura[0]=0b00110000;figura[1]=0b00100000;figura[2]=0b00100000;figura[3]=0;}
        if(estado==2){figura[0]=0;figura[1]=0b00111000;figura[2]=0b00001000;figura[3]=0;}
        if(estado==3){figura[0]=0b00010000;figura[1]=0b00010000;figura[2]=0b00110000;figura[3]=0;}
    }
    if(tipo==6)
    {
        if(estado==0){figura[0]=0;figura[1]=0b00010000;figura[2]=0b00111000;figura[3]=0;}
        if(estado==1){figura[0]=0b00100000;figura[1]=0b00100000;figura[2]=0b00110000;figura[3]=0;}
        if(estado==2){figura[0]=0;figura[1]=0b00111000;figura[2]=0b00100000;figura[3]=0;}
        if(estado==3){figura[0]=0b00110000;figura[1]=0b00010000;figura[2]=0b00010000;figura[3]=0;}
    }
}

void moverfiguras()
{
    unsigned char figura[4]={0,0b00011000,0b00011000,0};

    int posicionenx= 0;
    int posicioneny= 0;
    int estado=0;
    int tipo=0;

    char input;

    while(true)
    {
        cout << "\nPosicion: " << posicionenx << "," << posicioneny << endl;

        for(int i = 0; i < 4; i++)
        {
            int byte= posicionenx / 8;
            int desplazamiento = posicionenx % 8;

            unsigned char parte =figura[i] >> desplazamiento;

            unsigned char sobrante= 0;
            if(desplazamiento != 0)
                sobrante = figura[i] << (8-desplazamiento);
            for(int b = 7; b >= 0; b--)
            {
                int bit = (parte >> b) & 1;
                if(bit) cout << "#";
                else cout << ".";
            }
            if(desplazamiento != 0)
            {
                for(int b=7; b>=0; b--)
                {
                    int bit = (sobrante>>b) & 1;
                    if(bit) cout << "#";
                    else cout << ".";
                }
            }
        }
        cout<<endl;

        cout << "\na=izq d=der s=abajo w=rotar q=salir: ";
        cin >> input;

        if(input == 'q')
            break;
        if(input == 'a' && posicionenx > 0)
            posicionenx--;
        if(input == 'd')
            posicionenx++;
        if(input=='w')
            rotar(figura,estado,tipo);
        if(input == 's')
            posicioneny++;
    }
}

bool colision(unsigned char tablero[100][100], unsigned char figura[4], int posicionenx, int posicioneny, int ancho, int alto)
{
    int filas= ancho/8;
    int byte= posicionenx / 8;
    int desplazamiento= posicionenx % 8;

    for(int i=0; i<4; i++)
    {
        if(posicioneny+i>=alto)
            return true;
        if(byte>=filas)
            return true;
        unsigned char parte= figura[i]>>desplazamiento;
        if(tablero[posicioneny+i][byte]&parte)
            return true;
        if(desplazamiento!=0&&byte+1<filas)
        {
            unsigned char sobrante=figura[i]<<(8 - desplazamiento);

            if(tablero[posicioneny+i][byte+1]&sobrante)
                return true;
        }
    }
    return false;
}

void limpiarlineas(unsigned char tablero[100][100], int alto, int ancho)
{
    int filas = ancho/8;

    for(int i=0;i<alto; i++)
    {
        bool completa=true;

        for(int j=0; j<filas; j++)
        {
            if(tablero[i][j]!=0b11111111)
            {
                completa=false;
                break;
            }
        }
        if(completa)
        {
            for(int k=i; k>0; k--)
            {
                for(int j=0; j<filas; j++)
                {
                    tablero[k][j]=tablero[k-1][j];
                }
            }

            for(int j=0; j<filas; j++)
            {
                tablero[0][j]=0;
            }
            i--;
        }
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

        unsigned char figuras [7][4]=
            {
                {0,0b00011000,0b00011000,0},
                {0,0b00111100,0b00000000,0},
                {0,0b00111000,0b00001000,0},
                {0,0b00011000,0b00110000,0},
                {0,0b00110000,0b00011000,0},
                {0,0b00001000,0b00011100,0},
                {0,0b00000100,0b00011100,0}
            };

        unsigned char actual[4];

        aleatorio(figuras, actual);

        imprimirfigura(actual,4);

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
