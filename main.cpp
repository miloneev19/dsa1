#include <iostream>
using namespace std;

int front=-1,rear=-1,n=5 ;
int cqueue[5];

void enqueue(int x)
{
    if((front==0 && rear==n-1) || front==rear+1)
    {
     cout<<"Queue Overflow"<<endl;
     return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        if(rear==n-1)
        {
            rear=0;
        }
        else
        {
            rear=rear+1;
        }
    }
    cqueue[rear]=x;
}

void dequeue()
{
    if(front==-1)
    {
        cout<<"Queue is empty, element can't be popped "<<endl;
        return;
    }
    cout<<"popped out element is "<<cqueue[front]<<endl;
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        if(front==n-1)
        {
            front=0;
        }
        else
        {
            front=front+1;
        }
    }
}


void display() {
    if (front == -1) {
        cout << "queue is empty" << endl;
    }
    cout << "queue elements are" << endl;
    if (front <= rear) {
        while (front <= rear) {
            cout << cqueue[front] << " ";
            front++;
        }
    } else {
        while (front <= n - 1) {
            cout << cqueue[front] << " ";
            front++;
        }
        front = 0;
        while (front <= rear) {
            cout << cqueue[front] << " ";
            front++;
        }
    }
    cout<<endl;

}

int main() {
    int ch, val;
    cout<<"1)Insert\n";
    cout<<"2)Delete\n";
    cout<<"3)Display forward\n";
    cout<<"4)Exit\n";
    do {
        cout<<"Enter choice : "<<endl;
        cin>>ch;
        switch(ch) {
            case 1:
                cout<<"Input for insertion: "<<endl;
                cin>>val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout<<"Exit\n";
                break;
            default: cout<<"Incorrect!\n";
        }
    } while(ch != 4);
    return 0;
}
