# include <iostream>
# include <vector>
# include <algorithm>
# include <tgmath.h> 

using namespace std;

void pattern(double alto, double ancho){
    double radius;
    double radiusO;
    double desplAlto;
    double desplAncho;
    double x, y;
    int suma = alto/4;      //para sumarle a los rangos
    int rango1I = 0;         //rangos de las filas de cada cuarto (para partir los círculos)
    int rango1F = suma;
    int rango2I = rango1F + suma;
    int rango2F = rango2I + suma;
    vector <vector<char> > circulo(alto, vector<char>(ancho,'-'));

    /*
    if(alto > ancho){
        radius = alto/2; 
    }
    else{
        radius = ancho/2;
    }
    
    radiusO = radius;
    radius = alto/2;
    radius += 5;
    for(int reductor = 0;reductor <= radius-10; reductor+=5){
        radius -= 5;
        for(double t = 0.0; t < (6.3)*10; t += 0.1){
            x = round(radius * sin(t) + radius);
            y = round(radius * cos(t) + radius + 1);
            if(x+reductor<alto && y+reductor<ancho){
                circulo[x+reductor][y+reductor] = '*';
            }

        }
    }
    */
    radius = alto*0.375;  //el +5 es por el comienzo del ciclo, que se resta 5, entonces para que el radio quede bien de igual forma
    radiusO = radius;
    radius += 5;
    for(int reductor = 0;reductor <= radius; reductor+=5){ //reductor <= radius-10
        radius -= 5;
        for(double t = 0.0; t < (6.3)*10; t += 0.1){
            x = round(radius * sin(t) + radius);
            y = round(radius * cos(t) + radius);
            if(x+reductor<alto && y+reductor<ancho){
                if(x+reductor >= rango1I && x+reductor < rango1F ||
                   x+reductor >= rango2I && x+reductor < rango2F){
                    circulo[x+reductor][y+reductor] = '*';
                }
            }
        }
    }
    radius = radiusO;
    rango1I += suma;
    rango1F += suma;
    rango2I += suma;
    rango2F += suma;
    desplAlto = alto * 0.25;
    desplAncho = ancho/2 - radius;
    radius += 5;
    for(int reductor = 0;reductor <= radius; reductor+=5){ //reductor <= radius-10
        radius -= 5;
        for(double t = 0.0; t < (6.3)*10; t += 0.1){
            x = round(radius * sin(t) + radius) + desplAlto;
            y = round(radius * cos(t) + radius) + desplAncho;
            if(x+reductor<alto && y+reductor<ancho){
                if(x+reductor >= rango1I && x+reductor < rango1F ||
                   x+reductor >= rango2I && x+reductor < rango2F){
                    circulo[x+reductor][y+reductor] = '*';
                }
            }
        }
    }

    
    



    for(const auto& row : circulo){
        string line;
        for(auto cell : row){
            line += cell;
        }
        cout << line << endl;
    }
}
