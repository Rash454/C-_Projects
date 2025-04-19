
#include <iostream>
using namespace std;

// create linked list , add items to the begening and to the last of it .
template <class T>
struct node {
  T data ;
  node <T> *next ;
  node (){
      next=0;
  }
  node(T item){
      data =item ;
      next=0;
  }
};
bool addFirst (node<int> * &head , int item){
    node <int> *temp = new node <int> (item);
    if ( temp ==0 ) return 0;
    temp -> next = head;
    head = temp;
    return 1;
}

bool addLast ( node <int> * &head , int item ){
    node <int> * temp = new node <int> (item);
    if ( temp ==0 ) return 0;
    if ( head ==0 )
    head =temp;
    
    else {
        node <int> *p = head ;
        while (p->next !=0 )
        p=p->next;
        p->next = temp;
    }
    return 1;
}

void print ( node <int> *head ){
    while (head !=0){
        cout<< head -> data <<" ";
        head = head -> next;
    }
    cout<<endl;
}
int main()
{
    node <int> *head =0;
    addFirst(head , 10);
    addFirst(head , 20);
    addFirst(head , 30);
    addLast(head , 40);
    print(head);
    return 0;
}