#include <iostream>
#include <fstream>
#include <cstdlib>
#include <array>
using namespace std;

class Person{
protected:
    int age;
    string name;
public:
    Person(): age(0), name(""){}
    void getData(){
    cout <<" Enter name:" <<endl;
    cin >> name;
    cout <<"Enter age: \n";
    cin >> age;
    }
    void showData(){
        cout << name <<endl;
        cout << age << endl;
    }
};

int main(){
    Person p;
    p.getData();
    ofstream f("file2.dat", ios::binary);
    f.write(reinterpret_cast<char*>(&p), sizeof(p));
    f.close();

    ifstream i("file2.dat", ios::binary);
    i.read(reinterpret_cast<char*>(&p), sizeof(p));
    p.showData();
    return 0;
}