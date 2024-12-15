#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
   vector<int>rank,parent,size;

   public:
   //constructor 
    DisjointSet(int n){
    rank.resize(n+1,0); //resize will redinfing the size of the vector 
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++){ parent[i] = i;
    size[i] = i; }
   }

   int findPar(int node){
    if(node==parent[node]) return node;
    // return findPar(parent[node]);   //but this one is logarithmic time , so i need the path compression
    return parent[node] = findPar(parent[node]); //this is the line where path compression comes in
    //so in future someone comes up and ask me whether 2 nodes have same parents then this is where path compression helps
   }

   void unionByRank(int u,int v){
    int ulp_u = findPar(u); //ultimate parent of u = ulp_u
    int ulp_v = findPar(v);
    /* we cant write :
    int ulp_u = Parent(u);  
    int ulp_v = parent(v); --> because we are not applying path compression in union by rank function and we are not
    updating the parent array in this function so we wont be getting the ultimate parents
    */

    if(ulp_u==ulp_v) return ; //they belonging to the same component

    //if they dont belong to the same component
    if(rank[ulp_u] < rank[ulp_v]){
        //smaller gets attaced to the bigger ranked guy
        parent[ulp_u] = ulp_v;
        //no changes in rank 
    }
    else if(rank[ulp_v]<rank[ulp_u]){
        parent[ulp_v] = ulp_u;
        //again rank wont be getting updated
    }
    else{
        //if they are equal
        //can connect any one 
        //either ulp_u--> ulp_v or ulp_v---> ulp_u
        //in ulp_u-->ulp_v rank[ulp_u] increement by 1
        //in ulp_v-->ulp_u rank[ulp_v] increement by 1

        //i will be going with ulp_u-->ulp_v
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;

    }


   }
   
    void unionBySize(int u, int v){
        int ulp_u = findPar(u); 
        int ulp_v = findPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
  
};

int main(){

    DisjointSet ds(7); 
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    //check whether 3 and 7 are in same component
    if(ds.findPar(3) == ds.findPar(7)) cout<<"Same\n";
    else cout<<"Not same\n"; 
    ds.unionByRank(3,7);
    if(ds.findPar(3) == ds.findPar(7)) cout<<"Same\n";
    else cout<<"Not same\n"; 
    ds.unionByRank(3,7);
   
    DisjointSet ds1(7);
    ds1.unionBySize(1,2);
    ds1.unionBySize(2,3);
    ds1.unionBySize(4,5);
    ds1.unionBySize(6,7);
    ds1.unionBySize(5,6);

    //check whether 3 and 7 are in same component
    if(ds1.findPar(3) == ds1.findPar(7)) cout<<"Same\n";
    else cout<<"Not same\n"; 
    ds1.unionBySize(3,7);
    if(ds1.findPar(3) == ds1.findPar(7)) cout<<"Same\n";
    else cout<<"Not same\n"; 
    

    return 0;
}