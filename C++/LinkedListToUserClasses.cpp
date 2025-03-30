#include <iostream>
using namespace std;
template <class T>
struct Node{
    Node* next;
    T data;
};

template <class T>
class LinkedList{
Node<T>* first;
public:
    LinkedList(){
        first = NULL;
    }
    void addTo(T t);
    void putData();
};

template <class T>
void LinkedList<T>::addTo(T t){
    Node<T>* newNode = new Node<T>;
    newNode->data = t;
    newNode->next = first;
    first = newNode;
}

template <class T>
void LinkedList<T>::putData(){
    Node<T>* current = first;
    while(current != NULL){
        cout << current->data <<endl;
        current = current->next;
    }
}



int main(){
    LinkedList<int> a;
    a.addTo(1);
    a.addTo(2);
    a.addTo(3);
    a.addTo(4);
    a.putData();

    return 0;
}