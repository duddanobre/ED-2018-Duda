#include <iostream>
#include <vector>
using namespace std;

struct Vetor{
    int *data;
    int size; // qts elementos estao inseridos
    int capacidade; // tam max do vetor


    Vetor(int capacidade){
        this->capacidade = capacidade;
        this->size = 0;
        this->data = new int[capacidade];
    }

    void push_back(int value){
        if(this->size == this->capacidade)
            return;
        this->data[this->size] = value;
        this->size+=1;
    }

    void pop_back(){
        if(this->size==0)
            return;
        this->size-=1;
    }

    int& at(int i){
        return this->data[i];
    }

    int& front(){
        return this->data[0];
    }

    int& back(){
        return this->data[this->size-1];
    }

    int * begin(){
        return &this->data[0];
    }

    int * end(){
        return &this->data[this->size];
    }

    int capacity(){
        return capacidade;
    }

     int Size(){
        return size;
    }

    void reserve(int n){
         int *d = new int[capacidade];
         for(int i=0;i<capacity();i++){
             d[capacidade]=data[i];
         }

         capacidade = n;
         data = new int[capacidade];
         for(int i=0;i<capacity();i++)
             data[i]=d[i];
    }


};

int main()
{
    Vetor v(5);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.reserve(7);
    std::cout<< v.capacity()<< endl;
     std::cout<< v.Size()<< endl;

    return 0;
}

