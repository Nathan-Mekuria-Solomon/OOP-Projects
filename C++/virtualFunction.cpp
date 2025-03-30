#include <iostream>
#include <string>
#include <array>

using namespace std;

class Person{
protected:
    string name;
public:
    void getName(){
        cout <<"Enter name: \n";
        cin >> name;
    }
    void putName(){
        cout <<"Name: " <<name <<endl;
    }
    virtual void getData() = 0;
    virtual bool isOutstanding()= 0;
};

class Student : public Person{
public:
    float gpa;
    void getData(){
        Person::getName();
        cout <<"Enter GPA: \n"; cin >> gpa;
    }
    bool isOutstanding(){
        return(gpa > 3.5) ? true : false;
    }
};

class Professor : public Person{
    int numPub;
public:
    void getData(){
        Person::getName();
        cout <<"Enter number of publication: \n"; cin >> numPub;
    }
    bool isOutstanding(){
        return (numPub > 100) ? true : false;
    }
};
int main(){
    Person* pers[100];
    int tracker;
    char choice;
    do{
        cout << "Are you a student or professor? "; cin >> choice;
        if(choice == 's')
            pers[tracker] = new Student;
        else
            pers[tracker] = new Professor;
        pers[tracker]->getData();
        tracker ++;
        cout << "do u wanna add new dataset? "; cin >> choice;
    } while(choice != 'n');

    for(int i = 0; i < tracker; i++){
        pers[i]->putName();
        if(pers[i] ->isOutstanding())
            cout << "this person is outstanding.";

    }
    
    return 0;
}