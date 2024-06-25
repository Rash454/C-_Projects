#include<iostream.h>
main(){
	// Assignment 1 >>>  Q(1)
	 
	cout<<"Enter a multidigit number : ";
	int n;
	cin>>n;
	int r1=0,r2=n%10;
	
	if (n<0)
	n*=-1;
	
	if(n/10==0){
	while (n/10==0){
		
	cout<<"Please enter another number: ";
	
	cin>>n;}
	if(n<0){
	n*=-1;
	
	for( ; n!=0 ; n/=10){
		if (n%10 >=r1){
			r2=r1;
			r1=n%10;
		}
		else if(r2<n%10)
		r2=n%10;
	}	
	cout<<r1 << " "<<r2<<endl;
	}	
	
	else if(n>0){
		for( ; n!=0 ; n/=10){
		if (n%10 >=r1){
			r2=r1;
			r1=n%10;
		}
		else if(r2<n%10)
		r2=n%10;
	}	
	cout<<r1 << " "<<r2<<endl;	
	}
	}
	
	else{

	for( ; n!=0 ; n/=10){
		if (n%10 >=r1){
			r2=r1;
			r1=n%10;
		}
		else if(r2<n%10)
		r2=n%10;
	}	
	cout<<r1 << " "<<r2<<endl;
		
	}
	

	
	
}