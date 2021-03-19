# include <iostream>
# include <vector>
# include <string>
# include <sstream>
using namespace std;

void printCircles(string pCoord, int alto, int ancho){
    vector <vector<char> > circulo(alto, vector<char>(ancho,'-'));
    int len = pCoord.size();
    string a, b;
    int a2, b2;
    bool isY = false;
    for(int i = 0; i < len; i++){
        cout << pCoord[i] << endl;
        /*
        if(pCoord[i] == ';') {   //se coloca un asterisco en esa posición
            a2 = stoi(a);
            b2 = stoi(b);
            circulo[b2][a2] = '*';
            a = "";
            b = "";
            isY = false;
        } else if(pCoord[i] == ','){    //se guarda la x
            isY = true;
        } else if(isY){
            b += pCoord[i];
        }
        else{
            a += pCoord[i];
        }*/
    }
    for(const auto& fila : circulo){    //itera las filas de la matriz
        string linea;                   
        for(auto caracter : fila){      //va uniendo los caracteres de la fila en un solo string
            linea += caracter;    
        }
        cout << linea << endl;          //imprime una fila
    }
}



/*
# include "pattern.cpp"
# include "patternO.cpp"
# include "printCircles.cpp"
int main(){
    
    string a = pattern(40,60);
    //cout << a << endl;
    printCircles(a, 40, 60);

    //patternO(60,120);

    
    return 0;
}


string pattern(int alto, int ancho){

*/