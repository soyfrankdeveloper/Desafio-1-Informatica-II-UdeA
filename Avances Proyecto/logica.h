#ifndef LOGICA_H
#define LOGICA_H

void insertar(unsigned char** tablero, unsigned char figura[4], int posicionenx, int posicioneny, int ancho, int alto);
bool colision(unsigned char** tablero, unsigned char figura[4], int posicionenx, int posicioneny, int ancho, int alto);
void limpiarlineas(unsigned char** tablero, int alto, int ancho);

#endif // LOGICA_H
