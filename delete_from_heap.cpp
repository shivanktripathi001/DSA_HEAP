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



    int delete_from_heap(){


    int answer = arr[1];

    //replacement
    arr[1] = arr[size];

 //last element ko delete uski original position se
      size--;
      int index = 1;


      while(index < size ) {
          int leftIndex = 2*index;
          int rightIndex = 2*index+1;

          //find out karna h , sabse bada kon
          int largestKaIndex = index;
          //check left child
          if(leftIndex <= size && arr[largestKaIndex] < arr[leftIndex]) {
            largestKaIndex = leftIndex;
          }
          if(rightIndex <= size && arr[largestKaIndex] < arr[rightIndex]) {
            largestKaIndex = rightIndex;
          }
          //no change
          if(index == largestKaIndex) {
            break;
          }
          else {
            swap(arr[index], arr[largestKaIndex]);
            index = largestKaIndex;
          }
      
      
      }
      return answer;


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

        int ans = h.delete_from_heap();
        cout<<"deleted node "<<ans<<endl;

        cout << "Printing the content of heap: " << endl;
        h.print();




        



}