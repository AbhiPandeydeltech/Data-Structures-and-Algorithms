#include <iostream>
using namespace std;

class circular_Queue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    circular_Queue()
    {
        size = 5;
        arr = new int[size];
        front = rear = -1;
    }

    int get_front()
    {
        return front;
    }

    int get_rear()
    {
        return rear;
    }

    bool enqueue(int data)
    { // return true if data is pushed
        if ((front == 0 && rear == (size - 1)) || (rear == (front - 1) ))//% (size - 1))) --> both formula okay
        {
            cout << "Queue is Full" << endl;
            return false;
        }
        else if (front == -1)
        {
            // first element to be pushed
            front = rear = 0;
            // arr[rear]=data;   this is common among the three conditions so isko bahr hi likhdo end me
        }
        else if ((rear == (size - 1)) && front != 0)
        {
            rear = 0; // to maintain the cyclic nature
            // arr[rear]=data;
        }
        else
        {
            rear++;
            // arr[rear]=data;
        }
        arr[rear] = data;
        return true;
    }

    int dequeue()
    {
        // in dequeue we will be printing the popped element
        if (front == -1)
        {
            cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1; // removed that element and also before removing stored that element also
        // single element is the queue
        if (front == rear)
        {
            // is conditional statement ko implement krne se pehle i want to have that value of single element
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0; // to maintain cyclic nature
        }
        else
        {
            front++; // normal case
        }
        return ans;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    circular_Queue c1;

    cout << "Front is : " << c1.get_front() << endl;
    cout << "Rear is : " << c1.get_rear() << endl;

    

    cout << "element is entered or not : " << c1.enqueue(1) << endl;
    cout << "Front is : " << c1.get_front() << endl;
    cout << "Rear is : " << c1.get_rear() << endl;
    cout << "element is entered or not : " << c1.enqueue(2) << endl;
    cout << "Front is : " << c1.get_front() << endl;
    cout << "Rear is : " << c1.get_rear() << endl;
    cout << "element is entered or not : " << c1.enqueue(3) << endl;
    cout << "Front is : " << c1.get_front() << endl;
    cout << "Rear is : " << c1.get_rear() << endl;
    cout << "element is entered or not : " << c1.enqueue(4) << endl;
    cout << "Front is : " << c1.get_front() << endl;
    cout << "Rear is : " << c1.get_rear() << endl;
    cout << "element is entered or not : " << c1.enqueue(5) << endl;
    cout << "Front is : " << c1.get_front() << endl;
    cout << "Rear is : " << c1.get_rear() << endl;
    c1.print();

    
   
    cout<<"Element popped is : "<<c1.dequeue()<<endl;
    cout << "Front is : " << c1.get_front() << endl;
    cout << "Rear is : " << c1.get_rear() << endl;
    c1.print();

    cout << "element is entered or not : " << c1.enqueue(6) << endl;
    cout << "Front is : " << c1.get_front() << endl;
    cout << "Rear is : " << c1.get_rear() << endl;

    cout<<c1.enqueue(7)<<endl;
    c1.print();
    


    return 0;
}