#include <iostream>

using namespace std;

// Way1: struct ( old style )
struct list_element_struct{
    list_element_struct(int n = 0, list_element_struct* ptr = 0):
        d(n), next(ptr){}
    int d;
    list_element_struct* next;
};

// Way2: class ( C++ style ) (Recommended!)
class list_element{
    public:
        list_element(int n=0, list_element* ptr = nullptr): // nullptr is macro calls NULL
            d(n),next(ptr){}

        // private으로 선언하면 list에서 pointer 접근을 못함
        int d;
        list_element* next;
};

// List         head 의 기준 = 맨 오른쪽 ( 강의에서 그렇게 함)
class list{
    public:
        list():head(nullptr), cursor(nullptr){}     //default constructor
        void prepend(int n); //insert at front value n
        void append(int n); //insert at back value n
        int get_element(){ return cursor->d; }
        void advance(){ cursor = cursor->next;}
        void print();
        void release();

        ~list(){
            cout << "destructor called" << endl; // debug demonstration 소멸자를 가치있게 쓰는 좋은 습관!
            release();
        }

    private:
        list_element* head;
        list_element* cursor; //where we are
};

void list::prepend (int n)
{
    if( head == nullptr) // empty list case
        cursor = head = new list_element(n, head);
    else //add to front - chain
        head = new list_element(n, head);
}

void list::append(int n)
{
    if( head == nullptr ) // empty list case
        cursor = head = new list_element(n, head);
    else{
        list_element* temp = head;
        head = new list_element(n, nullptr);
        temp->next = head;
        cursor = temp;
    }
}

void list::print(){
    list_element* h = head;
    while(h != nullptr){
        cout << h->d << ", ";
        h = h-> next;
    }
    cout << "###" <<endl;
}

void list::release()
{
    delete head;
    delete cursor;
}

int main()
{
    list a, b;
    a.append(9); a.append(8);
    cout << " list a " << endl;
    a.print();
    // for(int i = 0; i<40; ++i)
    //     b.append(i*i);
    // cout<< "list b " << endl;
    // b.print();

    return 0;
}