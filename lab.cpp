#include <iostream.h>
#include <math.h>
main(){
	cout<<"1- find max perfect number\n2- calculate series\n3- exit\n";
	int ch,i,a,max=0,min,b,c;
	double sum=0;
	cin>>ch;
	switch(ch){
		case 1:
		cin>>a>>b;
		max=0;
		for(  i=a ; i<=b; i++){
			sum=0;
			for( int j=a ; j<=sqrt(i); j++)
			if(i%j==0){
				sum+=j;
				if(j != i/j){
					sum+=i/j;
				}
			}
		}
		if(sum == i && i>max)
		max=i;
		
		if(max==0)
		cout<<"no perfect number found\n";
		else 
		cout<<"max perfect = "<<max<<endl;
		break;
	}	
	
	}
	
	
	
	
	
	
	
