#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

class Rect
{

private:
    int length;
    int width;

public:
    Rect()
    {
        this->length = 0;
        this->width = 0;
    }

    Rect(int length, int width)
    {
        this->length = length;
        this->width = width;
    }

    void setLength(int len)
    {
        this->length = len;
    }

    void setWidth(int width)
    {
        this->width = width;
    }

    int getLength()
    {
        return this->length;
    }

    int getWidth()
    {
        return this->width;
    }

    int computeArea()
    {
        return (this->length * this->width);
    }
};


class Distance
{
private:
    int feet;
    float inch;

public:
    Distance()
    {
        cout << "inside Default Constructor of Distance" << endl;
    }

    Distance(int f, float i)
    {
        this->feet = f;
        this->inch = i;
    }

    void printDistance()
    {
        cout << "feet : " << this->feet << "\t" << "inch: " << this->inch << endl;
    }

    static Distance addDistance(Distance d1, Distance d2)
    {
        Distance result;
        result.feet = d1.feet + d2.feet;
        result.inch = d1.inch + d2.inch;
        return result;
    }

    Distance operator+(Distance d)
    {
        Distance result;
        result.feet = this->feet + d.feet;
        result.inch = this->inch + d.inch;
        return result;
    }

    ~Distance()
    {
        cout << "inside destructor" << endl;
    }
};

/* swap by reference */
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}


/* ============== Singleton ============== */
class Singleton{
    private:
        static Singleton* instance;
        Singleton(){
            cout<<"Singleton instance created!"<<endl;
        }
    public:
        static Singleton* getInstnace(){
            if(instance == nullptr){
                instance = new Singleton();
            }
            return instance;
        }

        void showMessage(){
            cout<<"Hello, Singleton!"<<endl;
        }

        /* Deleting the Copy constructor and equal operator */
        Singleton(const Singleton&) = delete;
        Singleton& operator= (const Singleton&) = delete; 
};

/* initializing the static class member instance */
Singleton* Singleton::instance = nullptr;



/* Stack Example */

class Stack{
    private:
        int top;
        int size;
        int capacity;
        int* arr;
    
    
    public:
    Stack(int capacity = 3){
        this->size = 0;
        this->capacity = capacity;
        this->top = 0;
        arr = new int[capacity];
    }

    int getSize(){
        return this->size;
    }

    void push(int item){
        if(size == capacity){
            cout<<"Stack full"<<endl;
        }else{
            arr[top] = item;
            top++;
            size++;
        }
    }

    int pop(){
        if(size == 0){
            
            cout<<"stack is empty"<<endl;
            return -5000;
        }else{
            top--;
            int returnedItem = arr[top];
            size--;
            return returnedItem;
        }
    }


    void printStack(){

        if(size == 0){
            cout<<"stack is empty"<<endl;
        }
        else{
            for(int i = top-1; i >= 0; i--){
                cout<<arr[i]<<endl;
            }
        }
    }



    ~Stack(){
        this->size = 0;
        this->top = 0;
        delete[] arr;
    }
};


int main(void)
{
    Rect r1;
    cout << "Area : " << r1.computeArea() << endl;

    cout << "-------------------" << endl;
    Distance d1(5, 10);
    d1.printDistance();

    Distance d2(d1);
    d2.printDistance();

    Distance result = d1 + d2;
    result.printDistance();

    Distance result2 = Distance::addDistance(d1, d2);
    result.printDistance();

    cout << "-------------------" << endl;

    int x = 15;
    int y = 30;

    cout << "Before swapping : " << endl;
    cout << "x: " << x << "\t" << "y: " << y << endl;
    swap(x, y);
    cout << "After swapping : " << endl;
    cout << "x: " << x << "\t" << "y: " << y << endl;

    /* Streams in C++*/
    cout << "-------------------" << endl;
    /* Writing to an external Stream */
    ofstream outfile("notes.txt");
    outfile << "Writing to notes.txt"<<endl;
    outfile.close();

    /* Reading from an external Stream */
    ifstream infile("notes.txt");
    string reading;
    getline(infile,reading);
    cout<<"reading : " << reading<<endl;
    infile.close();

    /* Singleton Design pattern */
    cout << "-------------------" << endl;
    Singleton* firstInstance = Singleton::getInstnace();
    firstInstance->showMessage();

    Singleton* secondInstance = Singleton::getInstnace();

    if(firstInstance == secondInstance){
        cout<<"Singleton Works"<<endl;
    }
    else{
        cout<<"Singleton Doesn't Work"<<endl;
    }

    /* Stack */
    cout << "-------------------" << endl;
    Stack s1;
    cout<<"size: "<< s1.getSize()<<endl; // 0
    s1.push(11);
    s1.push(15);
    s1.push(16);
    s1.push(18); // stack full
    s1.printStack();
    s1.pop();
    s1.pop();
        cout<<"size: "<< s1.getSize()<<endl; // 0

    s1.pop();
    s1.pop(); // stack empty
    s1.printStack(); // stack empty
}