#include<iostream>

using namespace std;

class cqueue
{
    private:

        int *a;
        int head;
        int tail;
        int capacity;
       


    public:

        cqueue(int capacity);
        void enqueue(int value);
        void dequeue();
        void display();

        bool isfull()
        {
            if(head == 0 && tail == capacity-1)
                return true;

            if(head == tail+1)
                return true;

            return false;        
        }

        bool isempty()
        {
            if(head == -1)
                return true;
            else
                return false;                 
        } 

};

cqueue::cqueue(int capacity)
{
    this->tail=this->head=-1;
    this->capacity=capacity;
    a=new int(capacity);
}

void cqueue::enqueue(int value)
{
       
    if(isfull())
        cout<<"Queue is full bro!!!!!!!!"<<endl;

    else
    {
        if(head == -1)
            head = 0;

        tail = (tail+1) % capacity;

        *(a+tail)= value;
    }
}

void cqueue::display()
{
    int i;    
    if(isempty())
        cout<<"Queue is empty bruh!!!!!!!"<<endl;
    
    else
    {
       for(i=head;i != tail;i = (i+1)% capacity)
        {  
            cout<<"===="<<endl;
            cout<<"["<<*(a+i)<<"]"<<endl;
        }
        cout<<"["<<*(a+i)<<"]"<<endl;
        cout<<"===="<<endl;
    }
}

void cqueue::dequeue()
{
    int pop;
    if(isempty())
        cout<<"Queue is empty bruh!!!!"<<endl;

    else
    {
        pop= *(a+head);

        if(head == tail)
        {
            head=tail=-1;
        }
        else
        {
            head = (head+1)%capacity;
        }

        cout<<"Element removed "<<pop<<endl;
        
    }
        
}

int main(int argc, char *argv[])
{
    cqueue a(3);
    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(30);
    a.display();
    a.dequeue();
    a.dequeue();
    a.enqueue(40);
    a.display();
    a.enqueue(50);
    a.display();
    return 0;
}