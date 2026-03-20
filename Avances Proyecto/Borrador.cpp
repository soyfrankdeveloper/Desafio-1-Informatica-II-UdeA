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

void aleatorio(unsigned char figuras[7][4], unsigned char actual[4], int &tipo)
{
    static int referencia=0;

    for(int i=0;i<4;i++)

    {
        actual[i]=figuras[referencia][i];
    }

    tipo = referencia;

    referencia++;

    if(referencia==7)
    {
        referencia=0;
    }
}

void insertar(unsigned char tablero[100][100], unsigned char figura[4], int posicionenx, int posicioneny, int ancho, int alto)
{
    int bytes = ancho / 8;

    for (int i = 0; i < 4; i++)

    {
        int y = posicioneny + i;

        if (y >= alto || y < 0 || figura[i] == 0)
        {
            continue;
        }

        if (posicionenx < 0)
        {
            tablero[y][0] |= (unsigned char)(figura[i] << (-posicionenx));
        }

        else
        {
            int actual = posicionenx / 8;
            int desplazamiento = posicionenx % 8;

            if (actual < bytes)
            {
                tablero[y][actual] |= (unsigned char)(figura[i] >> desplazamiento);
            }

            if (desplazamiento != 0 && (actual + 1) < bytes)
            {
                tablero[y][actual + 1] |= (unsigned char)(figura[i] << (8 - desplazamiento));
            }
        }
    }
}

void rotar(unsigned char figura[4], int &estado, int tipo)
{
    estado = (estado + 1) % 4;

    switch(tipo)
    {

    case 0:
        figura[0] = 0b00011000;
        figura[1] = 0b00011000;
        figura[2] = 0;
        figura[3] = 0;
        break;

    case 1:
        if(estado % 2 == 0)
        {
            figura[0] = 0b00011110;
            figura[1] = 0;
            figura[2] = 0;
            figura[3] = 0;
        }
        else
        {
            figura[0] = 0b00010000;
            figura[1] = 0b00010000;
            figura[2] = 0b00010000;
            figura[3] = 0b00010000;
        }
        break;

    case 2:
        if(estado == 0){ figura[0]=0b00011100; figura[1]=0b00010000; figura[2]=0; figura[3]=0; }
        if(estado == 1){ figura[0]=0b00011000; figura[1]=0b00001000; figura[2]=0b00001000; figura[3]=0; }
        if(estado == 2){ figura[0]=0b00000100; figura[1]=0b00011100; figura[2]=0; figura[3]=0; }
        if(estado == 3){ figura[0]=0b00010000; figura[1]=0b00010000; figura[2]=0b00011000; figura[3]=0; }
        break;

    case 3:
        if(estado % 2 == 0){ figura[0]=0b00001100; figura[1]=0b00011000; figura[2]=0; figura[3]=0; }
        else{ figura[0]=0b00010000; figura[1]=0b00011000; figura[2]=0b00001000; figura[3]=0; }
        break;

    case 4:
        if(estado % 2 == 0){ figura[0]=0b00011000; figura[1]=0b00001100; figura[2]=0; figura[3]=0; }
        else{ figura[0]=0b00001000; figura[1]=0b00011000; figura[2]=0b00010000; figura[3]=0; }
        break;

    case 5:
        if(estado == 0){ figura[0]=0b00010000; figura[1]=0b00011100; figura[2]=0; figura[3]=0; }
        if(estado == 1){ figura[0]=0b00011000; figura[1]=0b00010000; figura[2]=0b00010000; figura[3]=0; }
        if(estado == 2){ figura[0]=0b00011100; figura[1]=0b00000100; figura[2]=0; figura[3]=0; }
        if(estado == 3){ figura[0]=0b00010000; figura[1]=0b00010000; figura[2]=0b00011000; figura[3]=0; }
        break;

    case 6:
        if(estado == 0){ figura[0]=0b00001000; figura[1]=0b00011100; figura[2]=0; figura[3]=0; }
        if(estado == 1){ figura[0]=0b00010000; figura[1]=0b00011000; figura[2]=0b00010000; figura[3]=0; }
        if(estado == 2){ figura[0]=0b00011100; figura[1]=0b00001000; figura[2]=0; figura[3]=0; }
        if(estado == 3){ figura[0]=0b00001000; figura[1]=0b00011000; figura[2]=0b00001000; figura[3]=0; }
        break;
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

            {
                sobrante = figura[i] << (8-desplazamiento);
            }

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

        cout << "\na=izq d=der s=abajo w=rotar q=salir: "<<endl;
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
    int bytes = ancho / 8;

    for(int i = 0; i < 4; i++)

    {
        if(figura[i]== 0)

        {
            continue;
        }

        int y = posicioneny+ i;

        if(y >= alto)

        {
            return true;
        }

        if(posicionenx< 0)

        {
            int izquierda= -posicionenx;

            if(izquierda > 7)

            {
                return true;
            }

            unsigned char fuera = 0;

            for(int b = 0; b <izquierda; b++)

            {
                fuera |= (1<< (7 - b));
            }

            if(figura[i] & fuera)

            {
                return true;
            }

            unsigned char parte = figura[i] << izquierda;

            if(y >= 0 && (tablero[y][0] & parte))

            {
                return true;
            }
        }

        else
        {
            int actual = posicionenx / 8;
            int desplazamiento = posicionenx % 8;

            unsigned char parte_izq = figura[i] >> desplazamiento;

            if(actual <bytes && (tablero[y][actual] & parte_izq))

            {
                return true;
            }

            if(desplazamiento != 0)

            {
                unsigned char parte_der = (unsigned char)(figura[i] << (8 - desplazamiento));

                if(actual + 1 >= bytes && parte_der != 0)

                {
                    return true;
                }

                if(actual + 1 < bytes && (tablero[y][actual + 1] & parte_der))

                {
                    return true;
                }
            }
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

void imprimirconfigura(unsigned char tablero[100][100], unsigned char figura[4], int posicionenx, int posicioneny, int alto, int ancho)
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
    unsigned char tablero[100][100];


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

        if(gameover)
        break;


        insertar(tablero, figura, posicionenx, posicioneny, ancho, alto);
        limpiarlineas(tablero, alto, ancho);
    }

    return 0;
}


