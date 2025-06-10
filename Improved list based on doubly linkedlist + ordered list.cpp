
#include <iostream>
using namespace std;


template <class T >
struct node{
    T data;
    node <T> *next , *back;
    node(){
        next=back=0;
        
    }
    node(T item){
        data=item;
        next=back=0;
    }
};

template <class T>
class List{
    protected :
    int count , currentpos;
    node<T>*currentptr;
    void setpos(int pos){
        if(pos<currentpos){
            while (pos!=currentpos){
            currentpos--;
            currentptr=currentptr ->back;
        }
    }
    else {
        if (pos!=currentpos){
            currentpos++;
            currentptr=currentptr->next;
        }
    }
}
public:
bool empty(){
    return count==0;
}
int size(){return count;}
List(){ count =0; currentptr=nullptr;
currentpos=-1;
}
 
 void insert(int pos , T item){
     if ( pos<0 || pos>count) return ;
     node <T>*temp = new node<T> (item);
     if (temp==0) return ;
     node<T>*prev,*follow ;
     if (pos > 0 ){
         setpos(pos-1);
         prev=currentptr;
         follow=prev->next;
     }
     else {
         if (currentptr != 0)
         setpos(0);
     }
     if (pos > 0 ){
         if (follow==0){
             currentptr->next = temp;
             temp->back = currentptr;
         }
         else {
             temp -> next =follow ;
             currentptr->next = temp; 
             temp->back =currentptr;
             follow -> back =temp;
         }
     }
     else{
         if(currentptr!=0){
             temp -> next = currentptr;
             currentptr->back = temp;
         }
     }
     currentpos=pos;
     currentptr=temp;
     count++;
 }
 T retrieve (int pos  ){
   if (empty())return 0; 
   T item;
      if (pos <0 || pos >= count) return 0;
      setpos(pos);
      return currentptr->data;
  }
   void replace(int pos , T item){
      if(empty()) return;
     if (pos <0 || pos >= count) return ;
     setpos(pos);
     currentptr->data=item;
  }
  
};
 
 void fill (List <int> &L, int n){
    for(int i=1; i<=n ; i++)
    L.insert(L.size(),rand()%100);
}


template <class T>
class OrderedList : public List <T> {
    public:
    void insert(T item){
        int pos ;
        for( pos=0 ; pos< List <T> :: size() ; pos++){
        if(  List <T> ::retrieve(pos)>= item )
        break;}
        List<T> :: insert(pos,item);
    }
};
void print(OrderedList<int>L ){
   
    for(int i =0 ; i<L.size() ; i++)
    cout<<L.retrieve(i)<<" ";
    
    cout<<endl;
}

int main()
{
OrderedList <int> l;
l.insert(10);
l.insert(20);
l.insert(30);

print(l);

    return 0;
}