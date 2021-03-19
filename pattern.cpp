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
    int radio;                      //radio actual del circulo
    int desplazamX;                 //desplazamiento para que se vean bonitos los circulos
    int desplazamY;
    int x, y, x2, y2;               //coordenadas de cada punto creado
    int aumento = 0;                //aumento de las circunferencias
    double radianes = 6.3*ancho/10;
    int suma = alto/4;              //para sumarle a los rangos

    int rango1F = suma;             //rangos de las filas de cada cuarto (para partir los círculos)
    int rango2I = rango1F + suma;
    int rango2F = rango2I + suma;
    string coordenadas ="";

    desplazamY = alto*0.375;        //desplazamiento de alto
    desplazamX = ancho/3;           //desplazamiento para los cuartos pares
    radio = desplazamY-20;          //radio inicial

    for( ; aumento <= ancho ; aumento+=5 ){
        for(double angulo = 0.0 ; angulo < radianes ; angulo+=0.1 ){
            x = round(radio * cos(angulo))  + desplazamX;
            y = round(radio * sin(angulo))  + desplazamY;
            y2 = y + suma;
            x2 = x + desplazamX;
            if(  ( y >= 0 && y < rango1F || y >= rango2I && y < rango2F )   &&   x < ancho && x >= 0  ){
                coordenadas+=to_string(y)+","+to_string(x)+";";
            }
            if(  ( y2 >= rango1F && y2 < rango2I || y2 >= rango2F && y2 < alto ) && x2 >= 0 && x2 < ancho ) {
                coordenadas+=to_string(y2)+","+to_string(x2)+";";
            }
        }
        radio += 5;
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
/*
int main(){
    txtMaker("C:/Users/Tefy/Desktop/Semestre 3/coordenadas.txt", pattern(120, 60));
    return 0;
}*/
