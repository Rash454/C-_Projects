#include <iostream.h>
main(){
cout<< " Enter a number to find the square of it over it's factorial: ";
int a,f=1;
double sum=0,d,c,p;
cin >>a;
for ( int i=1 ; i<=a ; i++){
p=i*i;
d=(f*=i)*1.0;

for(int j=1 ; j<=a ; j++)
c=p/d;
sum+=c;
}
cout<<sum<<endl;
}
