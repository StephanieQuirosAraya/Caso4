# include <iostream>
# include <vector>
# include <algorithm>
# include <tgmath.h> 

# include <fstream>

using namespace std;

void txtMaker(string path, string content){
    ofstream file;
    file.open(path);
    file << content;
    file.close();
}

string pattern(double alto, double ancho){
    int radio;               //radio actual del circulo
    int desplazamX;          //desplazamiento para que se vean bonitos los circulos
    int desplazamY;
    double x, y;             //coordenadas de cada punto creado

    int aumento = 0;         //aumento de las circunferencias
    int suma = alto/4;       //para sumarle a los rangos
    int rango1I = 0;         //rangos de las filas de cada cuarto (para partir los círculos)
    int rango1F = suma;
    int rango2I = rango1F + suma;
    int rango2F = rango2I + suma;
    string coordenadas ="";



    desplazamY = alto*0.375; //--> 2     //
    desplazamX = ancho/3; //--> 2        //desplazamiento para los cuartos pares
    radio = desplazamY-20; //--> 2       //radio inicial


    for( ; aumento <= ancho ; aumento+=5 ){
        for(double angulo = 0.0 ; angulo < 6.3*10 ; angulo+=0.1 ){
            x = round(radio * cos(angulo))  + desplazamX;
            y = round(radio * sin(angulo))  + desplazamY;
            if(  (y >= rango1I && y < rango1F || y >= rango2I && y < rango2F)   &&   x < ancho && x >= 0  ){
                coordenadas+=to_string(y)+","+to_string(x)+";";
                
                
            }
            if(  ( (y+suma >= rango1I+suma && y+suma < rango1F+suma) || (y+suma >= rango2I+suma && y+suma < alto) )
                    && x+(ancho/3) >= 0 && x+(ancho/3) < ancho ){
                y += suma;
                x += (ancho/3);
                coordenadas+=to_string(y)+","+to_string(x)+";";


            }
        }
        radio += 5;//--> 2
    }


    /*for(const auto& fila : circulo){    //itera las filas de la matriz
        string linea;                   
        for(auto caracter : fila){      //va uniendo los caracteres de la fila en un solo string
            linea += caracter;    
        }
        cout << linea << endl;          //imprime una fila
    }*/
    return coordenadas;
}

int main(){
    txtMaker("C:/Users/Tefy/Desktop/Semestre 3/coordenadas.txt", pattern(120, 60));
    return 0;
}
