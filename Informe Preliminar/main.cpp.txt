#include <iostream>
//#include <bitset>
using namespace std;
int main(){
    unsigned short a=0x0622 ;//Podria utilizar unhex para una figura, hex y una tablero 4*4 es creo que conveniente, a ver como se utilizza
    for (int i=15; i>=0; i--){//for para recorrer 16 'bits' empezando desde la derecha
        //cout<<((a>>i)&1);
        if (((a>>i)&1)==1)// Aqui a mi bit en la posicion 'i' hago una condicion con un operador logico AND
        {cout<<"[]";
        }//Si la condicion anterior se cumple y mi bit es 1 entoces reemplaza ese 1  por []
        else
        {cout<<"  ";
        }//Si mi bit es 0 imprime "  "espacios dobles

        if ((i)%4==0)
        {cout<<endl; //este if salta linea cada 4 bits para darle forma a la figura solo con un entero o hex o tira de bits, como mejor se pueda visualizar relativamente
            //if (cout<<((a>>i)&1)){//lineas de 'pruebas'
            //cout<<((a>>i)&1) <<endl;//lineas de 'pruebas'

            //}
        }
    }

    //Desde esta linea hacia abajo hay un 'tablero' preliminar del cual partir par mejorar o cambiar de acuerdo al desarrollo del desafio

    /*bool tablero[24][32]={};//El 'tablero' es una prueba en un tamaño fijo (por ahora) de como se podria representar el tablero, siendo el el tablero un arreglo bidimencional con un tipo de dato booleano para un uso 'eficiente' de los tipos de datos
for (int i=0; i<24; i++){//Un bucle que recorra cada 'fila' del arreglo empezando desde arriba
  for (int j=0; j<32; j++){//Ente bucle recorre cada 'columna' dandome una 'posicion' en la cual estaria operanmdo
    tablero[i][j]=false;// aqui solo le estoy asignando a cada uno de mis espacios de mi arreglo bidimensioal un valor de false=0
  }
}

for (int i=0; i<24; i++){//Estas lineas me imprimen el arreglo bidimensional
  for (int j=0; j<32; j++){
if (tablero[i][j]==false){
cout<<". ";
}
else{
cout<<'[]';}
}
cout<<endl;

TODO LO COMENTADO ES SOLO UNA 'EXPLORACION' PARA LA POSIBLE MANIPULACION DE DATOS A NIVEL BIT


}*/



    return 0;
}

//
