#include <iostream>
using namespace std;

class Hero{
    //--> if no properties of class is there then size allocated to a class is 1 Byte
    int health;  //--> if properties are there, then size of the class is the total sum of size of its individual properties  
};

int main(){
    
    cout<<sizeof(Hero);

    return 0;
}