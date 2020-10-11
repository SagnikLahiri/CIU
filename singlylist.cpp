#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class singlelist
{
private:
    node *head, *tail;
    int size;

public:
    singlelist();
    ~singlelist();
    void push_front(int value);
    int pop_front();
    void push_back(int value);
    int pop_back();
    int front();
    int back();
    void insert(int index, int value);
    void reverse();
    void erase(int index);
    void value(int n);
    void remove_val(int value);
    void display();
};

singlelist::singlelist()
{
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

singlelist::~singlelist()
{
    node *tmp = this->head;
    while (tmp != NULL)
    {
        node *nxt = tmp->next;
        delete tmp;
        tmp = nxt;
    }
    this->head = NULL;
    this->tail = NULL;
}

void singlelist::push_front(int value)
{
    node *list = new node;
    list->data = value;

    if (this->head == NULL)
    {
        list->next = NULL;
        this->head = list;
        this->tail = list;
    }
    else
    {
        list->next = this->head;
        this->head = list;
    }
    this->size++;
}

int singlelist::pop_front()
{
    int ele;
    if (this->head == NULL)
        return -1;

    node *tmp = this->head;
    ele = tmp->data;
    cout << "Element popped from front:- " << ele << endl;
    this->head = (this->head)->next;
    delete tmp;

    if (this->head == NULL)
        this->tail = NULL;
    this->size--;
    return ele;
}

void singlelist::push_back(int value)
{
    if (this->tail == NULL && this->head == NULL)
        push_front(value);

    else
    {
        node *list = new node;
        list->data = value;
        list->next = NULL;

        this->tail->next = list;
        this->tail = list;
        this->size++;
    }
}

int singlelist::pop_back()
{
    if (this->tail == NULL && this->head == NULL)
        return -1;

    node *prev;
    node *tmp = this->head;

    int ele;
    prev = NULL;

    while (tmp->next != NULL)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    ele = tmp->data;

    if (prev == NULL)
    {
        this->head = NULL;
        this->tail = NULL;
        delete tmp;
        this->size--;
        return ele;
    }
    else
    {
        prev->next = NULL;
        this->tail = prev;
        delete tmp;
        this->size--;
        return ele;
    }
}

int singlelist::front()
{
    if (this->head == NULL)
        return -1;

    else
        return this->head->data;
}

int singlelist::back()
{
    if (this->tail == NULL)
        return -1;
    else
        return this->tail->data;
}

void singlelist::insert(int index, int value)
{
    if (index == 0 || index < size + 1)
        cout << "Noob!!!,WTF is that index?" << endl;

    else if (index == 1)
        push_front(value);

    else if (index == size + 1)
        push_back(value);

    else
    {
        node *new_node = new node;
        new_node->data = value;
        new_node->next = NULL;

        node *tmp = this->head;
        node *prev = tmp;

        for (int i = 1; i < index; i++)
        {
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = new_node;
        new_node->next = tmp;
        this->size++;
    }
}

void singlelist::reverse()
{
    node *current = this->head;
    node *prev = NULL, *nxt = NULL;
    this->tail = current;

    while (current != NULL)
    {
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    this->head = prev;
}

void singlelist::erase(int index)
{
    node *tmp = this->head;
    node *prev = tmp;
    if (this->head == NULL)
        cout << "List is empty\n";

    else if (index < 0 || index > this->size)
        cout << "Wrong index noob!!!" << endl;

    else if (index == 1)
        pop_front();

    else if (index == size)
        pop_back();

    else
    {
        for (int i = 1; i < index; i++)
        {
            prev = tmp;
            tmp = tmp->next;
        }
        cout << "Erased " << tmp->data << endl;
        prev->next = tmp->next;
        this->size--;
        delete tmp;
    }
}

void singlelist::value(int n)
{
    node *tmp = this->head;
    for (int i = 0; i < (this->size - n); i++)
        tmp = tmp->next;

    cout << "Value is " << tmp->data << endl;
}

void singlelist::remove_val(int value)
{
    node *tmp = this->head;
    int count = 1;

    while (tmp != NULL)
    {
        if (tmp->data == value)
            erase(count);
        count++;
        tmp = tmp->next;
    }
}

void singlelist::display()
{
    node *tmp;
    tmp = this->head;
    while (tmp != NULL)
    {
        cout << " " << tmp->data;
        tmp = tmp->next;
    }
    cout << endl<< this->size << endl;
}

int main(int argc, char *argv[])
{
    singlelist a;
    int val;
    a.push_front(1);
    a.push_front(2);
    a.display();
    a.push_back(0);
    val = a.pop_back();
    cout << " " << val << endl;
    val = a.pop_front();
    cout << a.front() << endl;
    cout << a.back() << endl;
    a.insert(0, 55);
    a.reverse();
    a.display();
    a.push_front(0);
    a.push_back(3);
    a.display();
    a.erase(5);
    a.push_back(10);
    a.value(1);
    a.remove_val(0);
    a.display();
    return 0;
}