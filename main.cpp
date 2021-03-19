# include "pattern.cpp"
# include "patternO.cpp"
# include "printCircles.cpp"
int main(){
    
    list<int> coordenadas;               //lista donde se guardan las coordenadas de los puntos.

    cout << "Primera prueba:" << endl;
    coordenadas = pattern(40,60);        //pattern retorna una lista con las coordenadas x,y de los puntos que forman las circunferencias.      
    printCircles(coordenadas, 40, 60);   //imprime los puntos de los circulos. Debe recibir la lista de coordenadas y el alto y ancho
                                         //en el que se va a desplegar.

    cout << endl;

    cout << "Segunda prueba:" << endl;
    coordenadas = pattern(141, 115);
    printCircles(coordenadas, 141, 115);

    
    return 0;
}