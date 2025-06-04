// Create a Stack class ,implementing essential stack operation and testing the stack with a varitey of data type.//

#include <iostream>
using namespace std;
class Stack
{
public:
    int *arr;
    int Top;
    int capacity;
    int size;

    Stack(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[this->capacity];
        this->Top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int element);
    int pop();
    int top();
    bool isEmpty();
    bool isFull();
    void display();
};

bool Stack::isEmpty()
{
    return this->Top == -1;
}

bool Stack::isFull()
{
    return this->Top == capacity - 1;
}

void Stack::push(int element)
{
    if (this->isFull())
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        this->Top++;
        this->arr[this->Top] = element;
    }
}

int Stack::pop()
{
    if (this->isEmpty())
    {
        cout << "Stack Overflow" << endl;
        return -1;
    }
    else
    {
        return arr[Top--];
    }
}

int Stack::top()
{
    if (this->isEmpty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else
    {
        return arr[Top];
    }
}

void Stack::display()
{
    cout << "Stack elements: ";
    for (int i = 0; i <= Top; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size, choice, element;

    cout << "Enter the size of an Arrary: ";
    cin >> size;

    Stack s(size);

    do
    {
        cout << "Enter 1 for Add an element to the top of the stack " << endl;
        cout << "Enter 2 for Remove the top element of the stack " << endl;
        cout << "Enter 3 for Return the top element of the stack " << endl;
        cout << "Enter 4 check if the stack is Empty " << endl;
        cout << "Enter 5  check if the stack is Full " << endl;
        cout << "Enter 6 for View the Display " << endl;
        cout << "Enter 0 For Exit " << endl;
        cout << endl;
        cout << "Enter your your Choice ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element ";
            cin >> element;
            s.push(element);
            break;

        case 2:
            cout << "Remove Element is:" << s.pop() << endl;
            ;
            break;

        case 3:
            cout << "Top element is: " << s.top() << endl;
            break;

        case 4:
            if (s.isEmpty())
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                cout << "Stack is not Empty" << endl;
            }
            break;

        case 5:
            if (s.isFull())
            {
                cout << "Stack is Full" << endl;
            }
            else
            {
                cout << "Stack is not Full" << endl;
            }
            break;

        case 6:
            s.display();
            break;

        case 0:
            cout << "Exiting From The program !" << endl;
            break;

        default:
            cout << "Wrong Choice!";
            break;
        }

    } while (choice != 0);

    return 0;
}