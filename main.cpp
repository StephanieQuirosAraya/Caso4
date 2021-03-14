# include <iostream>
# include <vector>
# include <algorithm>
# include <tgmath.h> 
using namespace std;

int main(){
    double alto = 30;
    double ancho = 30;
    double radius;
    if(alto > ancho){
        radius = alto/2;
    }
    else{
        radius = ancho/2;
    }
    radius = 30;
    //double radius = 30;
    double x, y;

    vector <vector<char>> circulo(alto, vector<char>(ancho,'-'));
    
    /*for(double t = 0.0; t < (6.3)*10; t += 0.1){
        x = round(0.5*radius * sin(t) + radius + 1);
        y = round(radius * cos(t) + radius + 1);
        circulo[x][y] = '*';
    }*/
    for(int reductor = 0;reductor <= radius-10; reductor+=5){
        radius -= 5;
        for(double t = 0.0; t < (6.3)*10; t += 0.1){
            x = round(0.5*radius * sin(t) + radius + 1);
            y = round(radius * cos(t) + radius + 1);
            if(x+reductor<alto && y+reductor<ancho){
                circulo[x+reductor][y+reductor] = '*';
            }
            
        }
    }
    
    /*radius -=5;
    for(double t2 = 0.0; t2 < 6.3*10; t2 += 0.1){
        x = round(0.5 * radius * sin(t2) + radius + 1);
        y = round(radius * cos(t2) + radius + 1);
        circulo[x+5][y+5] = '-';

    }

    radius -=5;
    for(double t2 = 0.0; t2 < 6.3*10; t2 += 0.1){
        x = round(0.5 * radius * sin(t2) + radius + 1);
        y = round(radius * cos(t2) + radius + 1);
        circulo[x+10][y+10] = '-';

    }*/

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