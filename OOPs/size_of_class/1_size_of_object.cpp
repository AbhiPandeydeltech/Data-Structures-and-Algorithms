#include <iostream>
using namespace std;

class Hero{
    //--> if no properties of class is there then size allocated to an object is also 1 Byte 
    //since objects are instances of class 

    //properties
    int health; //if prop are there then the size of object is the total sum of size of its individual properties in the class 
                //as object bnate hi uska 1 instance create hota hai from the template of the class , discussed in nb  
};

int main(){

    Hero h1;

    cout<<sizeof(h1);

    return 0;
}