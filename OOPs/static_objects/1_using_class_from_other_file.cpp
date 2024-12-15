#include <iostream>
// #include "1_Hero.cpp"  //--> this file contains Hero class and in such cases we can include like this

using namespace std;

class hero
{
    // by default access modifers are private

public:
    int health;
    char level;
};

int main()
{

    // Hero h1; //no error
    
    //creation of object 
    hero ramesh;
/*
    cout << "Health of h1 is : " << ramesh.health << endl; //op-> garbage value
    cout << "Level of h1 is : " << ramesh.level << endl; // op-> garbage value
*/
    ramesh.health = 70;
    ramesh.level = 'A';

    cout << "Health of h1 is : " << ramesh.health << endl; 
    cout << "Level of h1 is : " << ramesh.level << endl;

    return 0;
}