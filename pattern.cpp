# include <iostream>
# include <vector>
# include <algorithm>
# include <tgmath.h> 

using namespace std;

void pattern(double alto, double ancho){
    int radio;               //radio actual del circulo
    int desplazamX;           //desplazamiento para que se vean bonitos los circulos
    int desplazamY;
    double x, y;             //coordenadas de cada punto creado
    int aumento = 0;         //aumento de las circunferencias
    int suma = alto/4;       //para sumarle a los rangos
    int rango1I = 0;         //rangos de las filas de cada cuarto (para partir los círculos)
    int rango1F = suma;
    int rango2I = rango1F + suma;
    int rango2F = rango2I + suma;
    vector <vector<char> > circulo(alto, vector<char>(ancho,'-'));

    desplazamY = alto*0.375;    //-10 para que haga dos circulos mas al centro
    desplazamX = ancho/3;
    radio = desplazamY - 20;     //radio inicial

    for( ; aumento <= ancho ; aumento+=5 ){
        for(double angulo = 0.0 ; angulo < 6.3*10 ; angulo+=0.1 ){
            x = round(radio * cos(angulo))  + desplazamX;
            y = round(radio * sin(angulo))  + desplazamY;
            if(  (y >= rango1I && y < rango1F || y >= rango2I && y < rango2F)   &&   x < ancho && x >= 0  ){
                circulo[y][x] = '*';
                
            }
            if(  ( (y+suma >= rango1I+suma && y+suma < rango1F+suma) || (y+suma >= rango2I+suma && y+suma < alto) )
                    && x+(ancho/3) >= 0 && x+(ancho/3) < ancho ){
                y += suma;
                x += (ancho/3);
                circulo[y][x] = '*';
            }
        }
        radio += 5;
    }


    for(const auto& fila : circulo){    //itera las filas de la matriz
        string linea;                   
        for(auto caracter : fila){      //va uniendo los caracteres de la fila en un solo string
            linea += caracter;    
        }
        cout << linea << endl;          //imprime una fila
    }
}
