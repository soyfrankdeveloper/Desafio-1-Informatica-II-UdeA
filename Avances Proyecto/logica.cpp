#include "logica.h".

void insertar(unsigned char** tablero, unsigned char figura[4], int posicionenx, int posicioneny, int ancho, int alto)
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

bool colision(unsigned char** tablero, unsigned char figura[4], int posicionenx, int posicioneny, int ancho, int alto)
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

void limpiarlineas(unsigned char** tablero, int alto, int ancho)
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
