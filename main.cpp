# include "pattern.cpp"
# include "patternO.cpp"
# include "printCircles.cpp"
int main(){
    
    list<int> coordenadas;               //lista donde se guardan las coordenadas de los puntos.

    cout << "Primera prueba:" << endl;
    coordenadas = pattern(60,40);        //pattern retorna una lista con las coordenadas x,y de los puntos que forman las circunferencias.      
    printCircles(coordenadas, 60, 40);   //imprime los puntos de los circulos. Debe recibir la lista de coordenadas y el alto y ancho
                                         //en el que se va a desplegar.

    cout << endl;

    cout << "Segunda prueba:" << endl;
    coordenadas = pattern(73, 143);
    printCircles(coordenadas, 73, 143);

    
    return 0;
}