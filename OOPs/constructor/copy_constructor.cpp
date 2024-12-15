#include <iostream>
using namespace std;

class hero
{

private:
    int health;

public:
    char level;

    // creating our own default constructor :
    hero()
    {
        cout << "This is a constructor made by the user " << endl;
    }

    hero(int health, char level)
    {
        // one more paramterised constructor will 2 parameters
        this->health = health;
        this->level = level;
    }

    //copy constructor : 
    hero(hero& temp){  //& nhi lgaenge to error aaega discussed in notebook
        cout<<"Copy constructor is called "<<endl; 
        this->health=temp.health;
        this->level=temp.level;
    }

    void print()
    {
        cout << "health is : " << this->health << endl;
        cout << "level is : " << this->level << endl;
    }

    void print2()
    {
        cout << "health is : " << (*this).getHealth() << endl;
        cout << "level is : " << (*this).getLevel() << endl; // working fine
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
};

int main()
{

    hero suresh;
    suresh.setHealth(70);
    suresh.setLevel('A');
    //above same thing can be done using only 1 line and using parameterised constructor :
    hero abhinav(70,'A'); //done in 1 line 
    abhinav.print();
    
    //default inbuilt copy constructor called 
    hero ak(abhinav); 
    // hero ak=abhinav; //this is fine also
    /* 
    iska mtlb hai : 
       ak.health=abhinav.health  --> bs smjhne ke liye likha hua hai , health private member, cant be accessed using dot 
       ak.level=abhinav.level
    */
    ak.print2();


    return 0;
}