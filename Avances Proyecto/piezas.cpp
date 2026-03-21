#include "piezas.h"

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
