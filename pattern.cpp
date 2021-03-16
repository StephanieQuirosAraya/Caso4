# include <iostream>
# include <vector>
# include <algorithm>
# include <tgmath.h> 

using namespace std;

void pattern(double alto, double ancho){
    double radius;
    double x, y;

    if(alto > ancho){
        radius = alto/2; 
    }
    else{
        radius = ancho/2;
    }


    vector <vector<char> > circulo(alto, vector<char>(ancho,'-'));
/*
    for(int reductor = 0; reductor <= radius-10; reductor+=5){
        radius -= 5;
        for(double t = 0.0; t < (6.3)*10; t += 0.1){
            x = round(0.5*radius * sin(t) + 0.5*radius);
            y = round(radius * cos(t) + radius);
            if(x+reductor<alto && y+reductor<ancho){
                circulo[x+0.5*reductor][y+reductor] = '*';
            }
        }
    }
    */
    for(int reductor = 0; reductor <= radius; reductor+=5){ // reductor <= radius-10
        radius -= 5;
        for(double t = 0.0; t < (6.3)*10; t += 0.1){
            x = round(0.5*radius * sin(t) + 0.5*radius);
            y = round(radius * cos(t) + radius);
            if(x+0.5*reductor<alto && y+reductor<ancho){
                circulo[x+0.5*reductor][y+reductor] = '*';
            }
        }
    }

    for(const auto& row : circulo){
        bool isEmptyLine = true;
        string line;
        for(auto cell : row){
            line += cell;
            if(cell != ' '){
                isEmptyLine = false;
            }
        }
        if(!isEmptyLine){
            cout << line << endl;
        }
    }
}
