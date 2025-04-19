
#include <iostream>
#include <queue> 
#include <stack>
using namespace std;

//Function to swap between the Front and the Rear in the Queue .

void fill (queue<int> &q , int n){
    for( int i=1 ; i<=n ; i++)
  q.push(i);
  
}
void print (queue<int> q ){
   while (!q.empty()){
       cout<<q.front()<<" ";
       q.pop();
   }
  cout<<endl;
}
void swapFR(queue <int> &q ){
    stack <int> temp1,temp2;
    while (!q.empty()){
        temp1.push(q.front());
        q.pop();
    }
    int Front =temp1.top();
    q.push(Front);
    temp1.pop();
    while(!temp1.empty()){
        temp2.push(temp1.top());
        temp1.pop();
    }
    int bottom = temp2.top();
    temp2.pop();
    while(!temp2.empty()){
        q.push(temp2.top());
        temp2.pop();
    }
    q.push(bottom);
}

int main()
{
queue <int> q ;
fill(q,5);
print(q);
swapFR(q);
print(q);
    return 0;
}