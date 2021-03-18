# include <iostream>
# include <vector>
# include <algorithm>
# include <tgmath.h> 

using namespace std;

void pattern(double alto, double ancho){
    int radio;               //radio actual del circulo
    int desplazamX;          //desplazamiento para que se vean bonitos los circulos
    int desplazamY;
    double x, y;             //coordenadas de cada punto creado
    int x2, y2;
    int aumento = 0; //--> 1        //aumento de las circunferencias
    int suma = alto/4; //--> 2       //para sumarle a los rangos
    //rangos de las filas de cada cuarto (para partir los círculos)
    int rango1F = suma; //--> 1
    int rango2I = rango1F + suma; //--> 2
    int rango2F = rango2I + suma; //--> 2
    vector <vector<char> > circulo(alto, vector<char>(ancho,' ')); //--> 2 ó 3

    desplazamY = alto*0.375; //--> 2     //
    desplazamX = ancho/3; //--> 2        //desplazamiento para los cuartos pares
    radio = desplazamY-20; //--> 2       //radio inicial

    for( ; aumento <= ancho ; aumento+=5 ){  //--> 2+2    
        for(double angulo = 0.0 ; angulo < 6.3*10 ; angulo+=0.1 ){//--> 5
            x = round(radio * cos(angulo))  + desplazamX;//--> 7
            y = round(radio * sin(angulo))  + desplazamY;//--> 7
            y2 = y + suma;//--> 2
            x2 = x + desplazamX;//--> 2
            if(  ( y >= 0 && y < rango1F || y >= rango2I && y < rango2F )   &&   x < ancho && x >= 0  ){//--> 2+1+1 +1 +2+1+1  +1   +1+1+2 =14
                circulo[y][x] = '*';//--> 3
            }
            if(  ( y2 >= rango1F && y2 < rango2I || y2 >= rango2F && y2 < alto ) && x2 >= 0 && x2 < ancho ){ //14
                y += suma;//--> 2
                x += (ancho/3);//--> 3
                circulo[y][x] = '*';//--> 3
            }
        }
        radio += 5;//--> 2
    }


    for(const auto& fila : circulo){    //itera las filas de la matriz
        string linea;                   
        for(auto caracter : fila){      //va uniendo los caracteres de la fila en un solo string
            linea += caracter;    
        }
        cout << linea << endl;          //imprime una fila
    }
}
