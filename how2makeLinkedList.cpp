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
        list():head(nullptr), cursor(nullptr){}     // default constructor
        list(const int* arr, int n);                // tranfer data from another data
        list(const list& lst){                      // copy constructor (== move constructor)
            if(lst.head == 0){
                head = 0; cursor =0;
            }else{
                cursor = lst.head;
                list_element* h = new list_element();
                list_element* previous;
                head = h;
                h->d = lst.head->d;
                previous = h;

                for (cursor = lst.head; cursor != 0; )
                {
                    h = new list_element();
                    h->d = cursor ->d;
                    previous->next = h;
                    cursor = cursor->next;
                    previous = h;
                }
            cursor = head;
            }
        }
        void prepend(int n); //insert at front value n
        void append(int n); //insert at back value n
        int get_element(){ return cursor->d; }
        void advance(){ cursor = cursor->next;}
        void print();

        ~list(){
            cout << "destructor called" << endl; // debug demonstration 소멸자를 가치있게 쓰는 좋은 습관!
            for ( cursor = head; cursor !=0; )
            {
                cursor = head->next;
                delete head;
                head = cursor;
            }
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
        while (temp->next != nullptr){
            temp->next = temp;
        }
        cursor = new list_element(n, nullptr);
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

int main()
{
    list a, b;
    int data[10] = {3, 4, 6, 7, -3, 5};
    list d(data, 6);
    list e(data, 10);
    a.prepend(9); a.prepend(8);
    cout << " list a " << endl;
    a.print();
    for(int i = 0; i<40; ++i)
        b.prepend(i*i);
    cout<< "list b " << endl;
    b.print();
    list c(b); // deep copy
    //list c = b;  shallow copy     constructor 부분에서 동적 
    c.print();
    d.print();
    e.print();

    return 0;
}