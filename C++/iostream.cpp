#include <iostream>
#include <cstdlib>

using namespace std;

int isFeet(string instr);

class Distance{
int feet;
float inch;
public:
    Distance() : feet(0), inch(0.0){}
    Distance(int f, float i) : feet(f), inch(i){}
    void showDis(){
        cout << "Distance is " << feet << "feets and " << inch << "inches." <<endl;
    }
    void getDis();
};

void Distance::getDis(){
string temp;
while(true){//feet
    cout <<"Enter feet: " <<endl;
    cin.unsetf(ios::skipws);//not to skip(ignore) white spaces
    cin >> temp;
    if(isFeet(temp)){
        cin.ignore(10, '\n');
        feet = atoi(temp.c_str());
        break;

    }
    cin.ignore(10, '\n');
    cout << "Incorrect value.";
    }

while(true){//inch
    cout <<"Enter an inch: \n";
    cin.unsetf(ios::skipws);
    cin >> inch;
    if((inch < 0.0 || inch > 11.99)){
        cout << "inch must be between 0.0 and 11.99.\n";
        cin.clear(ios::failbit);
    }
    if(cin.good())
        cin.ignore(10, '\n');
        break;
    }
    cin.clear();
    cin.ignore(10, '\n');
    cout << "Incorrect number \n";
    

}

int isFeet(string instr){
    int num = instr.size();
    if(num == 0 || num > 5){
        return 0;
    }
    for(int j = 0; j < num; j++){
        if((instr[j] < '0' || instr[j] > '9') && instr[j] != '-')
            return 0;
    }
    double x = atof(instr.c_str());
    if(x < -999.0 || x > 999.0){
        return 0;
    }
    return 1;

}
int main(){
    Distance f;
    char s;
    do{
        f.getDis();
        cout << "The distance is: \n";
        f.showDis();
        cout << "wanna add another data?(y/n)";
        cin >> s;
        cin.ignore(10, '\n');

    }while(s != 'n');

    return 0;
}