#include <iostream>
using namespace std;

class hero
{
private:
    int health;

public:
    char level;
};

//hr class ka apna default constructor hota hai joki khud hi create hojata hai we dont create them manually , we can create them 
//but as soon as we create our own constructor default constructor wont exist anymore 

int main()
{
    hero ramesh;  //object create krte hi backend pe "ramesh.hero()" --> call horha hoga where hero() is the default constructor  

    return 0;
}