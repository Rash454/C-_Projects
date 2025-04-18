
#include <iostream>
#include <stack>
using namespace std;

void fill (stack<int> &s , int n){
    for( int i=1 ; i<=n ; i++)
  s.push(i);
  
}
void print (stack<int> s ){
    stack <int> temp;
  while (!s.empty()){
      temp.push(s.top());
      s.pop();}
      while(!temp.empty()){
  cout<<temp.top()<<" ";
  temp.pop();  }
  cout<<endl;
}

void removeOdd(stack<int>&s){
    stack <int> temp;
    while (!s.empty()){
        if(s.top()%2 == 0 )
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
}
template <class T>
bool searchX (stack <T> s, T x ){
    while ( !s.empty()){
        if (s.top()==x)
        return 1;
        s.pop();
    }
    return 0 ;
    }
void reverse (stack<int>&s ){
    stack<int> temp1 , temp2;
    while(!s.empty()){
        temp1.push(s.top());
        s.pop();
        
    }
    while (!temp1.empty()){
        temp2.push(temp1.top());
        temp1.pop();
    }
    while (!temp2.empty()){
        s.push(temp2.top());
        temp2.pop();
    }
}

void removeN(stack<int>&s , int n ){
    if(s.empty()) return;
    if (n>=s.size()){
    while(!s.empty())
    s.pop();}
    else{
    for (int i=1 ; i<=n ; i++)
    s.pop();}
}

void swap (stack <int> &s ){
    if (s.size()<2) return;
    stack<int> temp1,temp2;
    int topp=s.top();
    temp1.push(topp);
    s.pop();
    while(!s.empty()){
        temp2.push(s.top());
        s.pop();
    }
    int bottom =temp2.top();
    temp2.pop();
    while(!temp2.empty()){
        temp1.push(temp2.top());
        temp2.pop();
    }
    temp1.push(bottom);
    s=temp1;
}
int main()
{
  stack <int> s;
  fill(s,5);
  print(s);
  swap(s);
  print(s);

   return 0;
}