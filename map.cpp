#include <iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    
    //creation
    unordered_map<string,int>m;
    /*map<string,int>m;  --> for ordered map */
    //insertion 
    //1st method --> string,int 1 pair hi to hai so :
    pair<string,int>p = make_pair("abhishek",1);
    m.insert(p);
    //2nd method : 
    pair<string,int>p2("mere",2);
    m.insert(p2);
    //4th method : 
    pair<string,int>p3 = {"hi",4};
    m.insert(p3);

     //3rd method : 
    m["mera"]  = 1;  //first time when written then it is creation of a key value pair 
    
    m["mera"] = 5; //when second time written the same then it is a updation 

    //search : 
    cout<<m["mera"]<<endl;
    cout<<m.at("abhishek")<<endl;
   
   // above both statements can be used to search but they are still difference

/*
    // if some key which i havent made as yet then using m.at(" ..... ") will give an error , example : 
    cout<<m.at("unknown")<<endl; //it will show out of range 
*/

    //but when we write like below then there will be the creation the key and value assigned will be 0 , unknown key create hojata hai 
    //corresponding to 0
    cout<<m["unknown"]<<endl;

    //now as upr vale line see key create hogayi hai and value is 0 
    cout<<m.at("unknown")<<endl; 

   //size
   cout<<m.size()<<endl;

   //to find the presence of a key in the map 
   // count()  --> function will be used , if key is present then output will be 1 else 0
   cout<<m.count("mere")<<endl; //1

   cout<<m.count("uk")<<endl; //as there is no key then the output of this statement is 0

   //erase 
   m.erase("unknown");
   cout<<m.size()<<endl;

   //for traversing in the map 
   //1st method : 
   for(auto i:m){
    cout<<i.first<<" "<<i.second<<endl;
   }

   //2nd method : by using the iterator 
   unordered_map<string,int> :: iterator it = m.begin();  //--> unordered_map me traverse krna hai using iterator it 

   /*map<string,int> :: iterator it = m.begin();  --> for ordered map */

   while(it!=m.end()){  //jbtk iterator map ke end tk na pahuch jae
      cout<<it->first<<" "<<it->second<<endl;
      it++;
   }

   //unordered map me jis order me daali thi value us order me print nhi hogi 
   //but in case of orderede map everything will remain same and print order wise hogi 
   



    return 0;
}