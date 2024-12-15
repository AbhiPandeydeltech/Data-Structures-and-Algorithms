#include <iostream>
using namespace std;

class heap
{
    int arr[100];
    int size;

public:
    heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insert(int val){
        //size = variable gives information about the size of the array 
        //size will point the last element inserted into the array 
        size = size+1;

        //index will be used to push the data into the array also will be used for putting the values in their correct places 
        int index = size;
        arr[index] = val;
 
        //for creating the max heap 
        while(index > 1){
            int parent = index/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }

    //our array is starting from 0th index but we need only index 1 to size where our actual data is stored, we have done this 
    // /for our own convenience 
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deletefromArray(){
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }

        //step 1:
        swap(arr[1],arr[size]);
        // arr[1]=arr[size]; write either this or the above line of code , work is same

        //step 2: removal of last object 
        size--;
       
        // step 3: taking root node to its correct position
        int i=1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[leftIndex]>arr[i]){
                swap(arr[leftIndex],arr[i]);
                i=leftIndex;
            }
            else if(rightIndex < size && arr[rightIndex]>arr[i]) {
                swap(arr[rightIndex],arr[i]);
                i=rightIndex;
            }
            else{
                return ;
            }
        }

    }
};

void heapify(int *arr,int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest]<arr[left]){
       largest = left;
    }

    if(right <=n && arr[largest]<arr[right]){
        largest = right ;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest); //ye krne ke baad largest index ko baki uske shi jgh pahunchao
    }
}

void heapsort(int *arr,int n){
    int size = n;
    while(size>1){
        //step 1:
        swap(arr[size],arr[1]);
        //step 2:
        size--;
        heapify(arr,size,1);
    }
}
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletefromArray();
    h.print();

    //heap creation : 

    int arr[6] = {-1,54,55,53,52,50};
    int n = 5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    //print the array
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //heapsort
    heapsort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}