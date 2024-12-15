#include <iostream>
#include <string.h>
using namespace std;

class hero
{

private:
    int health;

public:
    char *name; // char name[100] --> aise bhi likh skta tha lekin we know that is bad practice  array me pdha tha
    char level;

    hero()
    {
        cout << "This is a constructor made by the user " << endl;
        name = new char[100];
    }

    hero(int health, char level)
    {
        // one more paramterised constructor will 2 parameters
        this->health = health;
        this->level = level;
    }

    void print()
    {
        cout << endl;
        cout << "[ Name : " << this->name << " , ";
        cout << "Health : " << this->health << " , ";
        cout << "Level : " << this->level << " ] " << endl;
        cout << endl;
    }

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

    void setLevel(char l)
    {
        level = l;
    }

    void setName(char *temp)
    {
        strcpy(this->name, temp);
    }

    // //destructor
    ~hero()
    {
        cout << "Destructor is called " << endl;
    }
};
int main()
{

    // static
    hero a;

    // dynamic
    hero *b = new hero();

    /* op : 
      This is a constructor made by the user --> for object a
      This is a constructor made by the user --> for dynamically created object b
      Destructor is called  --> for object a, for static objects destructor called itself
    */

   delete b;
   /* op after delete b statement : 
      This is a constructor made by the user --> for object a
      This is a constructor made by the user --> for dynamically created object pointed by b
      Destructor is called  --> for object a, for static objects destructor called itself
      Destructor is called  --> for dynamic object pointed by b , we have to call destructor manually be like this "delete b"
    */

    return 0;
}