# include <iostream>
# include <vector>
# include <string>
# include <sstream>
using namespace std;

/*
Imprime una lista de enteros que determina los puntos de un patrón.

Entradas:
    pCoord: lista con enteros que representan las coordenadas donde hay puntos.
    alto:   alto del espacio donde se desplegarán los puntos.
    ancho:  ancho del espacio donde se desplegarán los puntos.

Salidas: impresión en consola del patrón.
*/

void printCircles(list<int> * pCoord, int alto, int ancho){
    vector <vector<char> > circulo(alto, vector<char>(ancho,'-'));
    int x, y;
    int len = pCoord->size();
    for(int i = 0; i < len; i+=2){
        x = pCoord->front();
        pCoord->pop_front();
        y = pCoord->front();
        pCoord->pop_front();
        circulo[y][x] = '*';
    }
    for(const auto& fila : circulo){    //itera las filas de la matriz
        string linea;                   
        for(auto caracter : fila){      //va uniendo los caracteres de la fila en un solo string
            linea += caracter;    
        }
        cout << linea << endl;          //imprime una fila
    }
}