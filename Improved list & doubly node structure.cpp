
#include <iostream>
using namespace std;
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
  node <T> *head ,*currentPtr ;
  int count , currentPos;
  void setpos(int pos){
      if(pos<currentPos){
          currentPos=0;
          currentPtr=head;
      }
      while(currentPos!=pos){
          currentPos++;
          currentPtr=currentPtr->next;
      }
  }
  public :
  List(){ count =0 ; head=0;
      currentPtr=0;
      currentPos=-1;
  }
  bool empty() { return count==0; }
  int size(){return count; }
  
  void insert (int pos , T item){
      if (pos <0 || pos > count) return ;
      node<T> *temp = new node<T>(item);
      if (temp==0) return ;
      node<T>*prev,*follow ;
      if (pos>0){
          setpos(pos-1);
          prev=currentPtr;
          follow =prev->next;
          
      }
      else 
      follow=head;
      temp->next = follow ;
      if(pos>0)
      prev->next = temp;
      else 
      head =temp;
      currentPtr=temp;
      currentPos=pos;
      count++;
  }
   void remove (int pos ){
       if(empty())return ;
      if (pos <0 || pos >= count) return ;
      node<T>*follow ;
      if (pos>0){
          setpos(pos-1);
          follow =currentPtr->next;
          
      }
      else 
      follow=head;
      if(pos>0){
      currentPtr->next = follow->next;
      currentPtr=currentPtr->next; }
      else {
      head =follow->next;
      currentPtr=head;}
      delete follow;
      currentPos=pos;
      count--;
  }
 T retrieve (int pos  ){
   if (empty())return 0; 
   T item;
      if (pos <0 || pos >= count) return 0;
      setpos(pos);
      return currentPtr->data;
  }
  void replace(int pos , T item){
      if(empty()) return;
     if (pos <0 || pos >= count) return ;
     setpos(pos);
     currentPtr->data=item;
  }
  ~List(){
      while(!empty()) remove(0);
  }
  void operator=(List<T>&l){
      while(!empty()) remove (0);
      for(int i=0; i<l.size();i++)
      insert(size(),l.retrieve(i));
  }
  
   List (List <T> &l2){
         this->head=0;
         this->count=0;
         if(!l2.empty()){
             for(int i=0; i<l2.size() ; i++)
             this->insert(size(),l2.retrieve(i));
         }
  }
};


void fill (List <int> &L, int n){
    for(int i=1; i<=n ; i++)
    L.insert(L.size(),rand()%100);
}
void print(List<int>L ){
   
    for(int i =0 ; i<L.size() ; i++)
    cout<<L.retrieve(i)<<" ";
    
    cout<<endl;
}



template <class T>
class OrderedList :public List <T>{
    public :
    void insert (T item){
        T data;
        int pos;
        for( pos =0 ; pos<List <T> :: size() ; pos++){
           this-> retrieve(pos,data);
            if(data>=item)
            break;
        }
        return List<T>:: insert(pos,item);
    }
    
};




int main()
{
List <int> l;
l.insert(0,10);
l.insert(1,20);
l.insert(2,30);
print(l);



    return 0;
}