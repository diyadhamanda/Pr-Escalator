#include<iostream>
using namespace std;

class Queue{
    public:
        int front, rear, capacity;
        int *arr;
    
    Queue(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[this->capacity];
        this->front = this->rear = -1;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void Enqueue(int data);
    int Dequeue();
    int Front();
    int Rear();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
};

    void Queue::Enqueue(int data)
    {
        if(this->isFull())
        {
            cout<<"Queue is overflow!";
        }
        else if(this->front == -1 && this->rear == -1)
        {
            this->front = this->rear = 0;
            this->arr[this->rear] = data;
        }
        else
        {
            this->arr[++this->rear] = data;
        }
    }

    int Queue::Dequeue()
    {
        if(isEmpty())
        {
            return -1;
        }
        else if (this->front == this->rear)
        {
            int data = arr[this->front];
            this->front = this->rear = -1;
        }
        else
        {
            return arr[this->front++];
        }
    }
    
    int Queue::Front()
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[this->front];
        }
    }

    int Queue::Rear()
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[this->rear];
        }
    }

    bool Queue::isEmpty()
    {
        return this->front == -1;
    }

    bool Queue::isFull()
    {
        return this->rear == this->capacity - 1;
    }

    int Queue::size()
    {
        if(isEmpty())
        {
            cout<<"Queue is underflow!";
            return 0;
        }
        else
        {
            return this->rear - this->front + 1;
        }
    }

    void Queue::display()
    {
        if(isEmpty())
        {
            cout<<"Queue is underflow!";
        }
        else
        {
            cout<<"Queue is: ";
            for(int i = this->front; i <= this->rear; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }

int main()
{
    int  size , choice, element;;
    cout<<"Enter the capacity of the queue: ";
    cin>>size;

    Queue q(size);

    do{

        cout<<endl<<"-------------------"<<endl;
        cout<<"Enter 1  for the element Enqueue"<<endl;
        cout<<"Enter 2  for the element Dequeue"<<endl;
        cout<<"Enter 3  for the element Front"<<endl;
        cout<<"Enter 4  for the element Rear"<<endl;
        cout<<"Enter 5  for the element Size"<<endl;
        cout<<"Enter 6  for the element Display"<<endl;
        cout<<"Enter 0  for the element Exit"<<endl;
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout << "Enter element to enqueue: ";
                cin>>element;
                q.Enqueue(element);
            break;

            case 2:
                cout<<"Dequeue of element is: "<<q.Dequeue()<<endl;
            break;

            case 3:
               cout<<"front of element is: "<<q.Front()<<endl;
            break;

            case 4:
                cout<<"Rear of element is: "<<q.Rear()<<endl;
            break;

            case 5:
                cout<<"Size of queue: "<<q.size()<<endl;
            break;

            case 6:
                q.display();
            break;

            case 0:
                cout<<"Exiting."<<endl;
            break;
            
            default:
                cout<<"Wrong choice."<<endl;
            break;
        }

    }while(choice != 0);

    return 0;
}