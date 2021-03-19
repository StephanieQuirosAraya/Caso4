# include <iostream>
# include <vector>
# include <algorithm>
# include <tgmath.h> 
# include <list>
# include <fstream>


using namespace std;

/*
Crea un patrón de circulos concéntricos cortados.

Entradas:
    alto:   alto del espacio donde se desplegarán los círculos.
    ancho:  ancho del espacio donde se desplegarán los círculos.

Salidas: lista con las coordenadas de los puntos que forman las circunferencias.
*/

list<int> pattern(int alto, int ancho){
    int radio;                      //radio actual del circulo
    int desplazamX;                 //desplazamiento para que se vean bonitos los circulos
    int desplazamY;
    int x, y, x2, y2;               //coordenadas de cada punto creado
    list<int> coordenadas;
    int aumento = 0;     // -->+1           //aumento de las circunferencias
    double radianes = 6.3*ancho/10; // -->+3
    int suma = alto/4;   // -->+1         //para sumarle a los rangos

    int rango1F = suma;  // -->+1           //rangos de las filas de cada cuarto (para partir los círculos)
    int rango2I = rango1F + suma; // -->+2
    int rango2F = rango2I + suma; // -->+2
    
    desplazamY = alto*0.375;  // -->+2      //desplazamiento de alto
    desplazamX = ancho/3;     // -->+2      //desplazamiento para los cuartos pares
    radio = desplazamY-(alto/4);    // -->+2      //radio inicial
    for( ; aumento <= ancho ; aumento+=5){ // -->+3
        for(double angulo = 0.0 ; angulo < radianes ; angulo+=0.1 ){ // -->+4
            x = round(radio * cos(angulo))  + desplazamX; // -->+7
            y = round(radio * sin(angulo))  + desplazamY; // -->+7
            y2 = y + suma; // -->+2
            x2 = x + desplazamX; // -->+2
            if(  ( y >= 0 && y < rango1F || y >= rango2I && y < rango2F )   &&   x < ancho && x >= 0  ){ // -->+11
                coordenadas.push_back(x); // -->+2
                coordenadas.push_back(y); // -->+2
            }
            if(  ( y2 >= rango1F && y2 < rango2I || y2 >= rango2F && y2 < alto ) && x2 >= 0 && x2 < ancho ) { // -->+11
                coordenadas.push_back(x2); // -->+2
                coordenadas.push_back(y2); // -->+2
            }
        }
        radio += 5; // --> +2
    } //f(n) = 53(n*radianes)

    return coordenadas;
} // total = 66

