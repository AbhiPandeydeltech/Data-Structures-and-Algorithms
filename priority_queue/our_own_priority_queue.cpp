#include <iostream>
#include<queue>
using namespace std;

class node{
   public:
   int data;
   int row ;
   int col;

   //a constructor :
   node(int data,int row,int col){
    this->data = data;
    this->row = row;
    this->col = col;
   }

};

class compare{
  public:
  bool operator()(node*a,node*b){
    return a->data > b->data;
  }
};

void print(vector<int>&ans,priority_queue<node*,vector<node*>,compare>&minheap){
    while(minheap.size()>0){
        node* temp = minheap.top();
        minheap.pop();
        ans.push_back(temp->data);
    }

    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    vector<vector<int>>arr = {{3,5,9},{1, 2, 3, 8}};
    vector<int>ans;
    priority_queue<node*,vector<node*>,compare>minheap;
    node* temp = new node(10,0,0);
    minheap.push(temp);
    node* temp2 = new node(7,1,0);
    minheap.push(temp2);
    node* temp3 = new node(8,1,0);
    minheap.push(temp3);
    print(ans,minheap);
    
   
    return 0;
}