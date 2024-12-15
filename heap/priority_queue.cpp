#include <iostream>
#include<queue>
using namespace std;
int main(){
    
    cout<<"Using the priority queue"<<endl;

    //default priority queue max heap bnata hai 
    //we can make min head also
    priority_queue<int>pq;

    pq.push(4);
    pq.push(3);
    pq.push(5);
    pq.push(1);

    cout<<"The top element is : "<<pq.top()<<endl;
    pq.pop();
    cout<<"The top element is : "<<pq.top()<<endl;

    cout<<"Size is : "<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }

    //minimum heap using priority queue :
    
    priority_queue<int,vector<int>,greater<int> >minheap;
    minheap.push(4);
    minheap.push(3);
    minheap.push(5);
    minheap.push(1);
    cout<<"The top element is : "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"The top element is : "<<minheap.top()<<endl;

    cout<<"Size is : "<<minheap.size()<<endl;

    if(minheap.empty()){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }
    return 0;
}