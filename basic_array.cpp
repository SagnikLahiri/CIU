#include<iostream>

using namespace std;

class basic_array
{
private:
    
    int *arr;
    int size;
    int capacity;
    void resize()
    {
        if(capacity == 0)
        capacity++;
        else if (size == capacity)
        capacity =size*2;
        else if (size == (capacity/4))
        capacity = size/2;
    }

public:
    basic_array(int size);
    ~basic_array();
    void array_size();
    void array_capacity();
    void is_empty();
    int at(int pos);
    void push(int element);
    void del(int pos);
    void remove(int ele);
    void insert(int pos,int ele);
    int pop();
    void display();
    
};

basic_array::basic_array(int capacity)
{
    this->capacity=capacity;
    this->size=0;
    arr= new int[capacity];
}

basic_array::~basic_array()
{
    delete arr;
}

void basic_array::array_size()
{
    cout<<this->size<<endl;
}

void basic_array::array_capacity()
{
    cout<<this->capacity<<endl;
}

void basic_array::is_empty()
{
    if(this->size == 0)
    {
        cout<<"Array is empty"<<endl;
    }
        
    else
    {
        cout<<"Array is not empty"<<endl;
    }
        
}

int basic_array::at(int pos)
{
    if(pos<0 || pos>=this->size)
   {
        return -1;
   } 
    else
    {
        return arr[pos-1];
    }
    
}

void basic_array::push(int ele)
{
  /*  if(this->size==this->capacity)
    {
        cout<<"Out of bounds\n";
    }
    else
    {
        arr[this->size]=ele;
        this->size ++;
    }  */
    
    this->resize();
    arr[this->size]=ele;
    this->size ++;
}

void basic_array::del(int pos)
{
    if (pos<0 || pos>=this->size)
    {
        cout<<"Invalid position\n";
    }
    else
    {
        cout<<"Element removed "<<arr[pos-1]<<endl;
        
        for (int i=pos-1; i<this->size;i++)
        {
            arr[i]=arr[i+1];
        }
        this->size -=1;

    }
    
}

void basic_array::remove(int ele)
{
    for(int i=0;i< this->size;i++)
    {
        if(arr[i] == ele)
        {
            del(i+1);
        }
    }
}
void basic_array::display()
{
    for(int i=0;i< this->size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void basic_array::insert(int pos,int ele)
{
    int i;
    if(pos<0 || pos>this->size)
    cout<<"Index out of bound"<<endl;
    else
    {
        for(i=this->size;i>pos-1;i--)
        {
            arr[i+1]=arr[i];
        }
            arr[i]=ele;
    }
    

}

int basic_array::pop()
{
    int ele=arr[(this->size)-1];
    (this->size)--;
    return ele;
    
}

int main(int argc, char * argv[])
{
    basic_array *obj;
    int ele=0;
    obj->array_capacity();
    obj->push(4);
    obj->push(10);
    obj->push(8);
    obj->push(70);
 //   obj.push(45);
   // obj.push(30);
    obj->display();
    obj->array_capacity();
    obj->array_size();
    ele = obj->at(6);
    if (ele == -1)
    {
        cout<<"Index out of bound\n";
    }
    else
    {
        cout<<ele<<endl;
    }
       
    obj->del(2);
    obj->display();
    obj->array_size();
    obj->array_capacity();
    return 0;
}