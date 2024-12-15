#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue()
    {
        size = 5;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    int get_qfront()
    {
        return qfront;
    }

    int get_rear()
    {
        return rear;
    }

    bool isEmpty()
    {
        if (qfront == rear)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (rear == size)
            return true;
        else
            return false;
    }

    void enqueue(int data)
    {

        if (isFull())
        {
            cout << "Queue is full " << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void dequeue()
    {
        // first check is the array is empty or not
        if (isEmpty())
        {
            cout << "Queue is empty " << endl;
        }
        else
        {
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
                qfront = rear = 0;
        }
    }

    int front()
    {
        if (isEmpty())
            return -1; // that means array is empty and we dont have any element is there
        else
            return arr[qfront];
    }

    void print_queue()
    {
        for (int i = qfront; i < rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Queue q1; // constructor will be called amd size , front and rear will be made along with a dynamic array will be initialised
    cout << "Front is : " << q1.get_qfront() << endl;
    cout << "Rear is : " << q1.get_rear() << endl;
    cout << "Empty or not " << q1.isEmpty() << endl;
    cout << "Full or not : " << q1.isFull() << endl;
    q1.enqueue(1);
    cout << "Front is : " << q1.get_qfront() << endl;
    cout << "Rear is : " << q1.get_rear() << endl;
    cout << "Empty or not " << q1.isEmpty() << endl;
    cout << "Full or not : " << q1.isFull() << endl;
    q1.enqueue(2);
    cout << "Front is : " << q1.get_qfront() << endl;
    cout << "Rear is : " << q1.get_rear() << endl;
    cout << "Empty or not " << q1.isEmpty() << endl;
    cout << "Full or not : " << q1.isFull() << endl;
    q1.enqueue(3);
    cout << "Front is : " << q1.get_qfront() << endl;
    cout << "Rear is : " << q1.get_rear() << endl;
    cout << "Empty or not " << q1.isEmpty() << endl;
    cout << "Full or not : " << q1.isFull() << endl;
    q1.enqueue(4);
    cout << "Front is : " << q1.get_qfront() << endl;
    cout << "Rear is : " << q1.get_rear() << endl;
    cout << "Empty or not " << q1.isEmpty() << endl;
    cout << "Full or not : " << q1.isFull() << endl;
    q1.enqueue(5);
    cout << "Front is : " << q1.get_qfront() << endl;
    cout << "Rear is : " << q1.get_rear() << endl;
    cout << "Empty or not " << q1.isEmpty() << endl;
    cout << "Full or not : " << q1.isFull() << endl;
    q1.print_queue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.print_queue();
    cout << "Front is : " << q1.get_qfront() << endl;
    cout << "Rear is : " << q1.get_rear() << endl;
    cout << "Empty or not " << q1.isEmpty() << endl;
    cout << "Full or not : " << q1.isFull() << endl;

    q1.dequeue();

    q1.enqueue(6);

    q1.front();

    return 0;
}