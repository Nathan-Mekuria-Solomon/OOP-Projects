#include <iostream>
#include <string.h>
#include <array>

using namespace std;

class Publication{
protected:
    string title;
    float price;
public:
    void getData(){
        cout << "Enter title:" << endl;
        cin >> title;
        cout << "Enter price: " <<endl;
        cin >> price;
    }
    void putData(){
        cout << title <<endl;
        cout << price <<endl;
    }

};
class Sales{
    float sale [3];
public:
    void getData(){
        cout <<"first month sales: "; cin >> sale[0];
        cout <<"second month sales: "; cin >> sale[1];
        cout <<"third month sales: "; cin >> sale[2];
    }
    void putData(){
        for(float i : sale){
            cout << i <<endl;

        }
    }
};
class Book: public Publication, public Sales{
    int pageCount;
public:
    void getData(){
        Publication::getData();
        cout << "Enter page count: " <<endl;
        cin >> pageCount;
        Sales::getData();
    }
    void putData(){
        Publication::putData();
        cout << pageCount <<endl;
        Sales::putData();
    }
};

class Tape: public Publication, public Sales{
    float playingTime;
public:
    void getData(){
        Publication::getData();
        cout << "Enter played time in minutes: ";
        cin >> playingTime;
        Sales::getData();
    }
    void putData(){
        Publication::putData();
        cout << playingTime <<endl;
        Sales::putData();
    }
};

class Time{
public:
    int hr;
    int min;
    int sec;
    Time(): hr(0), min(0), sec(0){}
    Time(int h, int m, int s): hr(h), min(m), sec(s){}
    void getTime(){
        cout << "Time is: " << hr << ":" << min << ":" <<sec <<endl;
    }
    Time operator+(Time& t) const;
};
Time Time::operator+(Time& t) const {
    int h = hr + t.hr;
    int m = min + t.min;
    int s = sec + t.sec;
    if(s > 59){
        s-=60;
        m += 1;
    }
    if(m > 59){
        m -=60;
        h += 1;
    }
    return Time(h, m, s);
}
int main(){
    Book one;
    one.getData();
    one.putData();
    

    return 0;
}