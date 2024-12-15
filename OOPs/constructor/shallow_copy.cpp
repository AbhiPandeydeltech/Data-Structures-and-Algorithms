#include <iostream>
#include<string.h>
using namespace std;
class hero
{

private:
    int health;

public:
    
    char *name; //char name[100] --> aise bhi likh skta tha lekin we know that is bad practice  array me pdha tha
    char level;

    hero()
    {
        cout << "This is a constructor made by the user " << endl;
        name=new char[100];
    }

    hero(int health, char level)
    {
        // one more paramterised constructor will 2 parameters
        this->health = health;
        this->level = level;
    }

    void print()
    {   
        cout<<endl;
        cout<<"[ Name : "<<this->name<<" , ";
        cout << "Health : " << this->health << " , ";
        cout << "Level : " << this->level << " ] "<<endl;
        cout<<endl;
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

    void setName(char *temp){
        strcpy(this->name,temp);
    }
};

int main()
{
    hero hero1;
    hero1.setHealth(70);
    hero1.setLevel('A');
    char name[9]="Abhishek";
    hero1.setName(name);
    cout<<"name is : "<<hero1.name<<endl;
    hero1.print();

    //using default inbuilt copy constructor 

    hero hero2(hero1);
    hero2.print();

    hero1.name[0]='B';
    hero1.print();
    hero2.print(); //shallow copy is there 
    return 0;
}