#include <iostream>
using namespace std;

template <class T>
T abs(T n){
    return (n < 0) ? -n : n;
}

int main(){
    cout << abs(-9) <<endl;
    cout << abs(-9.01) <<endl;
    return 0;
}