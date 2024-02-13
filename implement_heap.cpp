#include<iostream>
using namespace std;


class heap{

    public:
    int *arr;
    int size;
    int capacity;

    heap(int capacity){

        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size =0;

    }


    void insert(int val){


        if(size == capacity){

            cout<<"heap overflow "<<endl;
            return;
        }

        size++;
        int idx = size;
        arr[idx] = val;


        while(idx > 1){


            int parentidx = idx/2;

            if(arr[parentidx] < arr[idx]){

                swap(arr[parentidx],arr[idx]);
            }
            else{
                break;
            }
        }

    }


    void print(){


        for(int i=1;i<=size;i++){


            cout<<arr[i]<<" ";


        }
        cout<<endl;
    }

};


int main(){

    int capacity = 5;

    heap h(capacity);


        h.insert(10);
        h.insert(20);
        h.insert(90);
        h.insert(11);
        h.insert(6);

        cout<<"printing heap "<<endl;
        h.print();
        



}