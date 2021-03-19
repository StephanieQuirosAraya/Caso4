# include "pattern.cpp"
# include "patternO.cpp"
# include "printCircles.cpp"
int main(){
    
    list<int> *a;
    pattern(a, 40,60);
    //printCircles(a, 40, 60);

for(int i = 0; i < 100; i++){
    cout << a->front() << ", ";
    a->pop_front();
    cout << a->front() << endl;
    a->pop_front();
}
    
    return 0;
}