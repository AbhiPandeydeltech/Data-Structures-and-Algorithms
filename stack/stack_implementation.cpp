#include <iostream>
using namespace std;

class stack
{
    int top;
    int *arr;
    int size; // size of array needed to determine where to stop
public:
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (!is_Full())
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack is full " << endl;
        }
    }

    void pop()
    {
        if (!is_Empty())
        {
            top--;
        }
        else
        {
            cout << "Stack is empty " << endl;
        }
    }

    int peek()
    {
        int value = arr[top];
        return value;
    }
/*
    bool is_Empty()
    {
        if (top != -1)
        {
            return false;
        }
        return true;
    }
*/   
           //or
    bool is_Empty(){
        if(top>=0){  //much better 
            return false;
        }
        return true;
    }

/*
    bool is_Full()
    {
        if (top != size - 1)
        {
            return false;
        }
        return true;
    }
*/
          //or
    
    bool is_Full(){
        if(size-top>1){
            return false;
        }
        return true;
    }
    
    void print()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
};

int main()
{
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.print();

    cout<<"Stack is empty or not : "<<st.is_Empty()<<endl;
    
    cout<<"Stack is full or not : "<<st.is_Full()<<endl;

    cout<<"The topmost element is : "<<st.peek()<<endl;

    st.pop();
    st.pop();

    cout<<"Stack is empty or not : "<<st.is_Empty()<<endl;
    
    cout<<"Stack is full or not : "<<st.is_Full()<<endl;

    cout<<"The topmost element is : "<<st.peek()<<endl;


    return 0;
}