#include <iostream>
using namespace std;

class hero
{

private:
    int health;

public:
    char level;

    // getter :
    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }

    // setter :
    void setHealth(int h)
    {
        health = h;
    }

    /*
    // setter with a condition , means it will set the value only at some condition given by valid users only
    void setHealth(int h, char password)
    {
        if(password=='A)
        {
            health = h;
        }
    }
    */
    void setLevel(char l)
    {
        level = l;
    }
};

int main()
{
    hero ramesh;

    // ramesh.health=70; --> show an error as now health is a private member and we cant access it outside ot the class template
    // we will use getter and setter wherein setter will set the value of health and getter will return the value of health
    // getter and setter are data functions of the class

    // cout << "Health is " << ramesh.getHealth() << endl; // some garbage value
    // now we can access the value

    // use setter
    ramesh.setHealth(70);
    ramesh.setLevel('A'); // since level is still a public data member we can do the same by "ramesh.level='A"

    cout << "Health is : " << ramesh.getHealth() << endl;
    cout << "Level is : " << ramesh.getLevel() << endl;
    cout << "Level is : " << ramesh.level << endl; // we can do this also since level is still a public data member

    cout << "Size of class is " << sizeof(hero) << endl; // op 8,it should be 5

    cout << "Size of object ramesh of hero class is : " << sizeof(ramesh) << endl; // op 8 , it should be 5

    return 0;
}