#include <iostream>
#include <string.h>
using namespace std;

class hero
{

private:
    int health;

public:
    static int timeTocomplete;
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

    static int random(){
        return timeTocomplete;
    }

    // //destructor
    ~hero()
    {
        cout << "Destructor is called " << endl;
    }
};

//initialisation of static data members 
int hero::timeTocomplete=5;
int main()
{
    cout<<hero::timeTocomplete<<endl; //static data members belongs to class and we dont need object creation for accessing this

    hero a;
    cout<<a.timeTocomplete<<endl;//it will work fine lekin it is not recommended because static data members dont belong to the class 

    hero b;
    b.timeTocomplete=10; //timetocomplete will get updated 

    cout<<a.timeTocomplete<<endl;
    cout<<b.timeTocomplete<<endl;

    hero::timeTocomplete=20;
    cout<<a.timeTocomplete<<endl;

    //static functions can only access static data members
    cout<<hero::random()<<endl;

    cout<<b.random()<<endl;//works fine but not recommended again

    return 0;
}