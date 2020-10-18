//#include"singlylist.cpp"
#include<iostream>

using namespace std;

struct node
{
    int data;
    int priority;
    node *next;
};

class pri_queue
{
    private:

    node *front;
    int size;

    public:

    pri_queue();
    ~pri_queue();
    void enqueue(int key,int p);
    void dequeue();
    void display();
    
};

pri_queue::pri_queue()
{
    this->front=NULL;
    this->size=0;
}

pri_queue::~pri_queue()
{
    node *tmp = this->front;
    while (tmp != NULL)
    {
        node *nxt = tmp->next;
        delete tmp;
        tmp = nxt;
    }
    this->front = NULL;
}

void pri_queue::enqueue(int key, int p)
{
    node *queue = new node;
    queue->data = key;
    queue->priority = p;

    if(this->front == NULL || p < this->front->priority)
    {
        queue->next = this->front;
        this->front = queue;
    }
    else
    {
        node *tmp;
        tmp = this->front;
        while (tmp->next !=NULL && tmp->next->priority <= p)
            tmp = tmp->next;
        queue->next = tmp->next;
        tmp->next = queue;
    }
}

void pri_queue::display()
{
    node * tmp = this->front;
    while(tmp !=NULL)
    {
        cout<<" "<<tmp->data;
        tmp = tmp->next;
    }    
}

void pri_queue::dequeue()
{
    node *tmp;

    if(this->front == NULL)
        cout<<"Queue is empty";
    else
    {
        tmp = this->front;
        cout<<"Element removed is "<<tmp->data<<endl;
        this->front = this->front->next;
        delete tmp;
    }
}

int main(int argc, char *argv[])
{
    pri_queue a;
    a.enqueue(10,4);
    a.enqueue(25,2);
    a.enqueue(99,3);
    a.enqueue(88,7);
    a.display();
    a.dequeue();
}