#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <process.h>

using namespace std;
//////////////////////////////////////////////////////////////////////////// count class and unary ++ operator
class Count{
unsigned int count;
public:
    Count() : count(0){}
    Count(int a) : count(a){}
    int getCount(){
        return count;
    }
    Count operator ++ (){
        return Count(++count);

    }
    Count operator ++(int){
        return Count(count++);
    }
};

//////////////////////////////////////////////////////////////////////////// english length class and + operator 

class EngL{
    int feet;
    double inch;
public:
    EngL() : feet(0), inch(0.0){}
    EngL(int f, double i) : feet(f), inch(i){}
    EngL operator + (EngL e){
        int f = feet + e.feet;
        double i = inch + e.inch;
        while(i >= 12){
            f++;
            i -= 12;
        }
        EngL e2(f, i);
        return e2;
    }
    void getL(){
        cout << "Feet: " <<feet << " inch: " << inch <<endl;
    }
};

int main(){
    EngL e3(1, 7);
    EngL e4(2, 4);
    EngL e5(3, 10.1);
    EngL e6 = e3 + e4 + e5;
    e6.getL();

    return 0;
}

//////////////////////////////////////////////////////////////////////////// + operator in concatinating a string

class String{
private:
    enum {sz = 80};
    char str[sz];
public:
    String(){
        strcpy(str, "");
    }
    String(char s[]){
        if(strlen(s) < sz){
            strcpy(str, s);
        }
    }
    String operator + (String ss) const {
        String temp;
        if((strlen(str) + strlen(ss.str)) < sz){
            strcpy(temp.str, str);
            strcat(temp.str, ss.str);
        }else{
            cout << "String overflow.\n"; exit(1);
        }
        return temp;

    }
    void getStr(){
        cout << str;
    }

};

int main(){
    String s1 = " \nabebe ";
    String s2 = " Has A Name";
    String s3;
    s3 = s1 + s2;
    s3.getStr();
    return 0;
}
///////////////////////////////////////////////////////////////// safe array with separate get and put funciton

unsigned const int LIMIT = 80;

class SafeArray{
private:
    int safearray[LIMIT];
public:
    void put(int ind, int el){
        if(ind < 0 || ind > LIMIT - 1){
            cout << "index out of bound\n"; exit(1);
        }
        safearray[ind] = el;
    }
    void get(int ind){
        if(ind < 0 || ind > LIMIT - 1){
            cout << "index out of bound\n"; exit(1);
        }
        cout << safearray[ind] <<endl;
    }

};

int main(){
    SafeArray a;
    for(int i = 0; i < LIMIT; i++){
        a.put(i, i*10);
    }
    for(int j = 0; j < LIMIT; j++){
        a.get(j);
    }
    return 0;
}

////////////////////////////////////////////////////////////////////// safe array with one function with return type of reference
const int LIMIT = 80;
class SafeArray{
    int safearray[LIMIT];
public:
    int& access(int n){
        if(n < 0 || n > LIMIT - 1){
          cout << "index out of bound\n"; exit(1);
         }
        return safearray[n];
    }
};
int main(){
    SafeArray s;
    for(int i = 0; i < LIMIT; i++){
        s.access(i) = i *2;
    }
    for(int j = LIMIT - 1; j >= 0; j--){
        int temp = s.access(j);
        cout << temp <<endl;

    }
    return 0;
}

////////////////////////////////////////////////////////////////////// subscription operator overloading

const int LIMIT = 80;

class SafeArray{
    int safearray [LIMIT];
public:
    int& operator [] (int n){
        if(n < 0 || n > LIMIT - 1){
            cout << "index out of bound\n"; exit(1);
        }
        return safearray[n];
    }
};

int main(){
    SafeArray s1;
    for(int i = 0; i < 20; i ++){
        s1[i] = i * i;
    }
    for(int i = 0; i < 20; i++){
        int temp = s1[i];
        cout << temp << endl;
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////// coversion between primitive datatype and user-defined datatype

class EngL{
    int feet;
    double inch;
    const float MTE = 3.6;    
public:
    EngL() : feet(0), inch(0.0){}
    EngL(int f, double i) : feet(f), inch(i){}
    EngL(float meter){
        float ftfraction;
        ftfraction = meter * MTE;
        feet = int(ftfraction);
        inch = (ftfraction - feet) * 12;
    }
    EngL operator + (EngL e){
        int f = feet + e.feet;
        double i = inch + e.inch;
        while(i >= 12){
            f++;
            i -= 12;
        }
        EngL e2(f, i);
        return e2;
    }
    void getL(){
        cout << "Feet: " <<feet << " inch: " << inch <<endl;
    }
    operator float(){
        float ftfraction = (feet + (inch / 12)) / MTE;
        return ftfraction;
    }
};

int main(){
    EngL e1 = 12.1;
    float meter1 = e1;
    cout << meter1 << endl;
    float meter2 = static_cast<float> (e1);
    cout << meter2 << endl;

    return 0;
}
/////////////////////////////////////////////////////////////////////////////////// conversion between user-defined datatypes
////////////////////////////////////////////////////////////////////////// with overloaded operator
class Time12{
    int hr;
    int min;
    bool pm;
public:
    Time12() : hr(0), min(0), pm(true){
    }
    Time12(int h, int m, bool p) : hr(h), min(m), pm(p){}
    void display() const{
        if(hr < 10){
            cout << '0';
        }cout << hr << ":";
        if(min < 10){
            cout << '0';
        }cout << min <<" ";
        string s = pm ? "pm" : "am";
        cout << s << endl;
    }

};

class Time24{
    int hr;
    int min;
    int sec;
public:
    Time24() : hr(0) , min(0), sec(0) {}
    Time24(int h, int m, int s) : hr(h) , min (m), sec(s){}
    void display() const{
        if(hr < 10){
            cout << '0';
        }cout << hr << ":";
        if(min < 10) {
            cout << '0';

        }cout << min << ":" ;
        if(sec < 10){
            cout << "0";
        }cout << sec;
    }
    operator Time12() const;
};

Time24::operator Time12() const {
    int hours;
    bool ampm;
    if(hr > 12){
        hours = hr -12;
        ampm = true;
    }else{
        hours = hr;
        ampm = false;
    }
    if(hours == 0 ) hours = 12;
    Time12 t1(hours, min, ampm);
    return t1;
}

int main(){
    Time24 t2(13, 30, 2);
    t2.display();
    Time12 t3 = t2;
    t3.display();

    return 0;
}
/////////////////////////////////////////////////////////////////////// conservation between user-defined datatypes with constructor

class Time24{
    int hr;
    int min;
    int sec;
public:
    Time24() : hr(0) , min(0), sec(0) {}
    Time24(int h, int m, int s) : hr(h) , min (m), sec(s){}
    void display() const{
        if(hr < 10){
            cout << '0';
        }cout << hr << ":";
        if(min < 10) {
            cout << '0';

        }cout << min << ":" ;
        if(sec < 10){
            cout << "0";
        }cout << sec;
    }
    int gethr() const {
        return hr;
    }
    int getmin() const {return min;}
};

class Time12{
    int hr;
    int min;
    bool pm;
public:
    Time12() : hr(0), min(0), pm(true){
    }
    Time12(Time24);
    Time12(int h, int m, bool p) : hr(h), min(m), pm(p){}
    void display() const{
        if(hr < 10){
            cout << '0';
        }cout << hr << ":";
        if(min < 10){
            cout << '0';
        }cout << min <<" ";
        string s = pm ? "pm" : "am";
        cout << s << endl;
    }

};
Time12::Time12(Time24 t24) {
    hr = t24.gethr() > 12 ? t24.gethr()-12 : t24.gethr();
    pm = hr < 12 ? false : true;
    min = t24.getmin();
    if(t24.gethr() == 0) 
    {
        hr = 12;
        pm = false;
    }
}

int main(){
    Time24 t4(13, 30, 30);
    Time12 t111 = t4;
    t111.display();
    return 0;
}

/////////////////////////////////////////////////////////// Exercise

////////////////////////////////////////////////////////// Question 1

class EngL{
    int feet;
    double inch;
public:
    EngL() : feet(0), inch(0.0){}
    EngL(int f, double i) : feet(f), inch(i){}
    EngL operator + (EngL e){
        int f = feet + e.feet;
        double i = inch + e.inch;
        while(i >= 12){
            f++;
            i -= 12;
        }
        EngL e2(f, i);
        return e2;
    }
    EngL operator - (EngL);
    void getL(){
        cout << "Feet: " <<feet << " inch: " << inch <<endl;
    }
};

EngL EngL::operator - (EngL e1){
    int f = feet - e1.feet;    
    double i = inch - e1.inch;
    if(i < 0){
        i += 12;
        f -= 1;
    }else if(i > 12){
        i -= 12;
        f += 1;
    }
    if(f < 0){
        cout << "Subtracting lesser number from the bigger one is not permitable.\n"; exit(1);
    } 
    EngL temp(f, i);
    return temp;
}

int main(){
    EngL ee1(10, 1);
    EngL ee2(10, 0);
    EngL ee3 (9, 3);
    EngL ee4 = ee1 - ee2;
    EngL ee5 = ee1 - ee3;
    ee4.getL();
    ee5.getL();
    return 0;
}

//////////////////////////////////////////////////////////////////////// Question 2 : overloaded operation of + and += in string concatination
class Strplus{
    enum { MAX = 100};
    char ch[MAX];
public:
    Strplus() : ch("\0"){}
    Strplus(char a[]){
        strcpy(ch, a);
    } 
    Strplus operator + (Strplus a){
        char temp[MAX];
        strcpy(temp, ch);
        strcat(temp, a.ch);
        return Strplus(temp);
    }
    Strplus operator += (Strplus a){
        char temp[MAX];
        strcpy(temp, ch);
        strcat(temp, a.ch);
        for(int i = 0; i < MAX; i++){
            ch[i] = temp[i];
        }
        return Strplus(temp);
    }
    void display() const {
        cout << ch <<endl;
    }
};

int main(){
    Strplus s = "Abebe";
    Strplus s1 = " kebede";
    s1 += s;// KebedeAbebe
    Strplus s2 = s1 + s;// KebedeAbebeAbebe
    s1.display();
    s2.display();

    return 0;
}

