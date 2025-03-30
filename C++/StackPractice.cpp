#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

enum {MAX = 80};

struct Stack{
    char* arr[MAX];
    int top;
    Stack() : top(-1){}
};

class Expression{
private:
    Stack s;
public:
    Expression(){
    }
    void prase();
    void exp();
};

int main(){

    return 0;
}