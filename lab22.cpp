#include <iostream.h>
main(){
	
//	cout<<"1- find max perfect number\n2- calculate series\n3- exit\nEnter your choice:";
	int ch,a,b,d,i,j,c,max=0,n,p=1;
	double sum=0,l=1.0,m=1.0,sum1=0;
//	cin>>ch;
	
	while (ch!=3){
	cout<<"1- find max perfect number\n2- calculate series\n3- exit\nEnter your choice:";	
	cin>>ch;
	
	switch (ch){
		case 1:
		cout<<"Enter 2 number : ";
		cin>>a>>b;
		if(a<0 || b<0){
		cout<<"negative numbers are not included\n";
		break;}
		
		if(a>b){
		c=b;
		b=a;
		a=c;
		}
		for( i=a; i<=b ; i++){
			sum=0;
			for( j=1 ; j<i ; j++){
			if(i%j==0)
			sum+=j;}
			if(sum==i && i>max)
			max=i;
			}
			cout<<"max perfect number between the two numbers you entered is :"<<max<<endl;
			
		break;
		
		case 2:
		sum1=0;
		for( i=1;i<=n;i+=2){
			m=1; d=i+1;
		
			for( j=1;j<=i;j++)
			m*=d*1.0;
			sum1+=(i*a*l)/(1.0*m);
			l*=-1;
		}
		cout<<a+sum1<<endl;
		break;
		}
	/*	cout<<"Enter the two number to find the series: ";
		cin>>a>>n;
			for(int i=1 ;i<=n ; i+=2){

				for ( int j=1; j<=i; j++){
					p*=n;	
					}
				sum+=((i*a)/(p*1.0));
				sum*=-1;
					}	
			cout<<"The result is: "<<a+sum<<endl;*/
			
		
			

		
	}

	
	}
	
	
	
	
