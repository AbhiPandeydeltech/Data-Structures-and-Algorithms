#include <iostream>
using namespace std;

class hero
{

private:
    int health;

public:
    char level;

    
        //creating our own default constructor :
        hero(){
            cout<<"This is a constructor made by the user "<<endl;
        }
    

    // creating our own constructor vo bhi paramterised constructor :
    hero(int health)
    {
        cout << "this->" << this << endl;
        this->health = health; // this will store the address of current object or it is pointer to an instance of hero i.e object
        // (*this).health=health; //this is also same 
    }

    hero(int health,char level){
        //one more paramterised constructor will 2 parameters
        this->health=health;
        this->level=level;
    }

    void print(){
        cout<<"health is : "<<this->health<<endl;
        cout<<"level is : "<<this->level<<endl;
    }

    void print2(){
        cout<<"health is : "<<(*this).getHealth()<<endl;
        cout<<"level is : "<<(*this).getLevel()<<endl; //working fine 

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

    // all valid object declaration below works for default contructor :

    hero ramesh ; //object create krte hi backend pe "ramesh.hero()" --> call horha hoga where hero() is the constructor made by us
    //op after writing this --> This is a constructor made by the user

    ramesh.print();

    // ramesh.hero(); //we cant manually do this even if the constructor() is made manually and in public location

    // hero luv(); --> this too wont work

    //dynamically
    hero *h=new hero; //again contructor called
    h->print();
         //or we can write this like below
    hero *h1=new hero();

    

    // object declaration in case of self made parameterised constructor
    hero abhishek(20);

    cout << "Address of abhishek : " << &abhishek << endl;

    hero *h2 = new hero(30);

    cout << "Address of dynamically allocated object is : " << h2 << endl;
    /* output :
    this->0x61fef4
    Address of abhishek : 0x61fef4
    this->0x10170d0
    Address of dynamically allocated object is : 0x10170d0
    */

   //parameterised constructor is updating the health of object 
   cout<<"health of abhishek is : "<<abhishek.getHealth()<<endl;

   hero* h3=new hero(40,'A');
   cout<<"health is : "<<h3->getHealth()<<endl;
   cout<<"level is : "<<h3->getLevel()<<endl;
   cout<<"health is : "<<(*h3).getHealth()<<endl;
   cout<<"level is : "<<(*h3).getLevel()<<endl;
   cout<<"level is : "<<(*h3).level<<endl;
   cout<<"level is : "<<h3->level<<endl;

   (*h3).print();
   h3->print2();

   

    return 0;
}