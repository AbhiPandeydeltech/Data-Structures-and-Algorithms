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

    void setLevel(char l)
    {
        level = l;
    }
};

int main()
{
    // dynamically allocation of objects
    hero *h = new hero;
    
    //to access private members :
    // cout<<"Health is : "<<(*h).getHealth()<<endl; //garbage value 
    // cout<<"Health is : "<<(*h).getLevel()<<endl; //garbage value 

    //to set the values of the private members
    (*h).setHealth(70);
    (*h).level='A'; //level is a public data member 

    cout<<"Health is : "<<(*h).getHealth()<<endl;
    cout<<"Level is : "<<(*h).getLevel()<<endl;

    (*h).setLevel('B'); //level is a public data member so we can also do like this 
    cout<<"Level is : "<<(*h).getLevel()<<endl;
    cout<<"level is : "<<(*h).level<<endl;
    
    h->setHealth(80); //can be done like this also using arrow operator 
    h->level='C';
  
    cout<<"Health is : "<<h->getHealth()<<endl;
    cout<<"Level is : "<<h->getLevel()<<endl;

    h->setLevel('D');
    cout<<"level is : "<<h->level<<endl;



    return 0;
}