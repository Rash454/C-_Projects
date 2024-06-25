#include<iostream.h>

void menu(){
	cout<<"1-Calculate series.\n2-GCD and LCM.\n3-exit.\nEnter your choice: ";

}

int power(int x, int y ){
int p=1;
for(int i=1;i<=y ;i++)
p*=x;
return p;	
}

int fact ( int a){
	int f=1;
	for(int j=1;j<=a;j++)
	f*=j;
	return f;
}

double alpha (int w){
	double sum=0; 
	for(int i=1;i<=w;i++)
	{
	 int f=1;
	 for(int j=2 ; j<i ;j++)
	 if(i%j==0)
     f=0;
     if(i==1)
     f=0;
      
	 if(f)
	 sum+=i;
	}
	return sum;
}

double beta(int z){
	double sum =0;
	for(int i=1; i<=z;i+=2)
	sum+=i;
	return sum;
}

main(){
int ch,x,n;
double sum;

while(ch!=3){
	menu();
	cin>>ch;
	switch (ch){
		//series
		case 1:
		sum=0;
		cout<<"Enter the first number : ";
		cin>>x;
		cout<<"Enter the second number : ";
		cin>>n;
		
		if(n<0)
		n*=-1;
		if(x<0)
		x*=-1;
		
		if(n==0){
			cout<<"Undefined value for this series "<<endl;
		}
		else{
	
		for(int i=1 ;i<=n ; i+=2){
		sum+=(alpha(power(x,i))*power(x,i))/(beta(fact(i))*fact(i)*1.0);	
			
		}
		cout<<"sum= "<<sum<<endl;}
		break;
		
		// GCD & LCM 
     	case 2:
     	
		int x,y,GCD,temp;
		double LCM;
		cout<<"Enter two numbers please : ";
		cin>>x>>y;
		
	    if (x==0 && y!=0){
    
		cout<<"GCD :"<<y<<endl;
		cout<<"LCM is undefined "<<endl;}
		
		if (x!=0 && y==0){
		cout<<"GCD : "<<x<<endl;
		cout<<"LCM is undefined "<<endl;
		}
	    if (x==0 && y==0)
	    cout<<"There's undefined LCM and GCD "<<endl;
		
		if(y>x){
		temp=y;
		y=x;
		x=temp;	
		}
		
		if(y<0)
		y*=-1;
		if(x<0)
		x*=-1;
		
		if (x!=0 && y!=0 ){
			
	
    	for(int i=1; i<=y ; i++){
	    	if (x%i ==0 && y%i==0 )
	    	GCD=i;
	    }
    	
    	cout<<"\nMax GCD number is : "<<GCD<<endl;
    	
    	LCM=(x*y)/(GCD*1.0);
    	cout<<"Least Common Multiple is : "<<LCM<<endl;
		}
    	
    	break;
    	
    	case 3:
    	break;
    	
    	
    	default:
    	cout<<"Invalid input .\n";
    	
    	
	}
		}
		
	}

