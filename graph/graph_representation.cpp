#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

/*  Method 1 : to store the graph using adjacency matrix
//for 1 based nodes 
    int adjM[n+1][n+1];

    // time complexity : O(m) in short linear time complexity 
    for(int i = 0;i<m;i++){

        //there exists and edge between u and v nodes 
        int u,v;
        cin>>u>>v;

        adjM[u][v] = 1;
        adjM[v][u] = 1; //this is for undirected graph as if there exists an edge between u and v then there necessarily exists an edge 
                        //between v and u , this statement wont be there in case of directed graphs 
    }
*/
 
 //method 2 : to store the graph using adjacency list 
 vector<int> adj[n+1] ;  //for 1 based nodes

 //time complexity : linear time 
 //space complexity : O(2E) ~ O(E)
 for(int i =0;i<m;i++){
    //there exists an edge between u and v 
    int u,v;
    cin>>u>>v;

    adj[u].push_back(v);
    adj[v].push_back(u);  //this is not required in a directed graph reason u know already 

 }
    return 0;
}