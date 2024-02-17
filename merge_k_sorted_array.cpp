#include<iostream>
#include<queue>
using namespace std;


class info{
    
    public:
    int data;
    int rowidx;
    int colidx;

    info(int a,int b,int c){
        this->data = a;
        this->rowidx = b;
        this->colidx = c;
    }

};

class compare{

    public:

    bool operator()(info *a,info* b){

        return a->data > b->data; 
    }
};

void merge_k_sorted_array(int arr[][4],int n,int k,vector<int> &ans){

    priority_queue<info* ,vector<info*>,compare> pq;



    for(int row=0;row<k;row++){

        int ele = arr[row][0];
        info* temp = new info(ele,row,0);
        pq.push(temp);
    }


    while(!pq.empty()){

        info* temp = pq.top();
        pq.pop();

        int topdata = temp->data;
        int toprow = temp->rowidx;
        int topcol = temp->colidx;


        //store in ans 
          ans.push_back(topdata);

          //next ele for the same row jisme se just abhi pop kia h
        // use insert bhi to karna hai

        if(topcol+1 <n){


            //iska matlab abhi ele hai array me 

            info* newinfo = new info(arr[toprow][topcol+1],toprow,topcol+1);

            pq.push(newinfo);


        }


    }
}

int main(){

    int arr[3][4] = {

        {1,4,8,11},
        {2,3,6,10},
        {5,7,12,14}
    };


    int n = 4;
    int k=3;

    vector<int> ans;


    merge_k_sorted_array(arr,n,k,ans);

    cout<<"printing ans array "<<endl;

    for(int i=0;i<ans.size();i++){

        cout<<ans[i]<<" ";
    }


        return 0;

}