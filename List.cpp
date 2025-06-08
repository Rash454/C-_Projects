
#include <iostream>
using namespace std;
#include <list>
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
template <class T>
class List{
  node <T> *head ;
  int count ;
  node<T>*setpos(int pos){
      node<T>*q=head;
      for(int i=0;i<pos ;i++)
      q=q->next;
      return q;
  }
  public :
  List(){ count =0 ; head=0;}
  bool empty() { return count==0; }
  int size(){return count; }
  void insert (int pos , T item){
      if (pos <0 || pos > count) return ;
      node<T> *temp = new node<T>(item);
      if (temp==0) return ;
      node<T>*prev,*follow ;
      if (pos>0){
          prev =setpos(pos-1);
          follow =prev->next;
          
      }
      else 
      follow=head;
      temp->next = follow ;
      if(pos>0)
      prev->next = temp;
      else 
      head =temp;
      count++;
  }
   void remove (int pos ){
       if(empty())return ;
      if (pos <0 || pos >= count) return ;
      node<T>*prev,*follow ;
      if (pos>0){
          prev =setpos(pos-1);
          follow =prev->next;
          
      }
      else 
      follow=head;
      if(pos>0)
      prev->next = follow->next;
      else 
      head =head->next;
      delete follow;
      count--;
  }
 void retrieve (int pos , T &item ){
   if (empty())return; 
      if (pos <0 || pos >= count) return ;
      node<T>*p=setpos(pos);
      item= p->data;
      
  }
  void replace(int pos , T item){
      if(empty()) return;
     if (pos <0 || pos >= count) return ;
     node<T>*p=setpos(pos);
     p->data=item;
  }
  ~List(){
      while(!empty()) remove(0);
  }
  void operator=(List<T>&l){
      while(!empty()) remove (0);
      if (!l.empty()){
          node<T>*newhead ,*p , *temp;
          p=l.head;
          newhead=temp=new node<T>(p->data);
          while (p->next !=0 ){
              p=p->next ;
              temp->next= new node<T>(p->data);
              temp = temp->next;
          }
          head=newhead;
          count=l.count;
          
      }
  }
   List (List <T> &l2){
          node<T>*newhead ,*p , *temp;
          p=l2.head;
          if(p!=0){
          newhead=temp=new node<T>(p->data);
          while (p->next !=0 ){
              p=p->next ;
              temp->next= new node<T>(p->data);
              temp = temp->next;
          }
          head=newhead;
          count=l2.count;
          
      }
  }
};
void fill (List <int> &L, int n){
    for(int i=1; i<=n ; i++)
    L.insert(L.size(),rand()%100);
}
void print(List<int>L ){
    int item;
    for(int i =0 ; i<L.size() ; i++){
    L.retrieve(i,item);
    cout<<item<<" ";}
    cout<<endl;
}

void reverse(List<int>&l){
    if(!l.empty()){
        int first , last ;
        for(int i=0 ; i<l.size()/2 ; i++){
            l.retrieve(i,first);
            l.retrieve(l.size()-1-i,last);
            l.replace(i,last);
            l.replace(l.size()-1-i,first);
        }
    }
}
template <class T>
List <T> oddItems(List <T> &l1 ,List<T>&l2){
    List <T> l3 ;
    T item;
    for(int i=0 ; i<l1.size() ; i++ ){
        l1.retrieve(i,item);
        if(item%2)
        l3.insert(l3.size(),item);
    }
      for(int i=0 ; i<l2.size() ; i++ ){
        l2.retrieve(i,item);
        if(item%2)
        l3.insert(l3.size(),item);
    }
    return l3;
}

int main()
{
    List <int> s,s2;
    fill(s,10);
    print(s);
    fill(s2,6);
    print(s2);
    List<int>l3;
    l3=oddItems(s,s2);
    print(l3);
    return 0;
}