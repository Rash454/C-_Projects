#include <iostream>
using namespace std ;
#include <stack>
#include <queue>

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

template<class T>
void fill (stack<T>&s , int n ){
    for (int i=0 ; i< n ; i++)
    s.push(rand()%100);
}
template<class T>
void fill (queue<T>&q ,int n ){
    for (int i=0 ; i< n ; i++)
    q.push(rand()%100);
}
template<class T>
void print (queue <T> q){
    while (!q.empty()){
        cout<<q.front()<<" " ;
        q.pop();
    }
    cout<<endl;
}
template<class T>
void print (stack<T> s){
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
void removeLO (stack<int>&s){
stack <int> temp;
int LO=-1;
if (s.empty()) return ;
while(!s.empty()){
    if (s.top()>LO && s.top()%2!=0)
    LO=s.top();
    temp.push(s.top());
    s.pop();
}
while (!temp.empty()){
    if (temp.top()!=LO)
    s.push(temp.top());
    temp.pop();
}
}
bool isFull (queue <int> &q ){
    if (q.empty())return 0;
    else return 1;
}
void reverse(stack <int> &s) {
    stack <int> t1,t2;
    while (!s.empty()){
        t1.push (s.top());
        s.pop();
    }
    while (!t1.empty()){
        t2.push(t1.top());
        t1.pop();
    }
    while (!t2.empty()){
        s.push(t2.top());
        t2.pop();
    }
    
}
void swapMinMax(queue <int> &q ){
    if (q.empty()) return ;
    queue <int> temp;
    int min ,max;
    min =max =q.front();
    while (!q.empty()){
        int item =q.front();
        q.pop();
        if (item<min) min=item;
        if (item>max) max=item;
        temp.push(item);
    }
    while (!temp.empty()){
         int item =temp.front();
        temp.pop();
      if (item ==min)
      q.push(max);
        else if(item ==max)
        q.push(min);
        else 
        q.push(item);
    }
    
}
template <class T >
void print (node <T> *head ){
    while (head !=0){
        cout<<head->data <<" ";
        head = head->next;
    }
    cout<<endl;
}

void reverse (queue <int> &q){
    stack <int> s;
    while (!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()){
        q.push(s.top());
        s.pop();
    }
}
void removeBeforeX(node <int> *&head ,int x){
    if (head ==0 || head->next==0) return ;
    if(head->data ==x)
    return;
    node<int>*prev=0;
    node<int>*curr=head;
    node<int>*next=head->next;
    while (next !=0 && next ->data !=x){
    prev=curr;
    curr=next;
    next=next->next;
    }
    if (next==0) return;
    if (prev==0){
        head=head->next;
        delete curr;
    }
    else {
        prev->next=next;
        delete curr;
    }
    
}

int main()
{
node <int>*head =0;
head =new node<int>(10);
head->next = new node<int>(20);
head->next->next=new node<int>(30);
print(head);
removeBeforeX(head,40);
print(head);
    return 0;
}