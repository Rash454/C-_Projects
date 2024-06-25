#include <iostream.h>

void rasha (int num)
{
  int co=0,sum=0;
  for (;num<=2023109806; num++)
	{
	   sum = 0;
	  if (num > 0)
		{
		  for (int j = 1; j < num; j++)
			{
			  if (num % j == 0)sum += j;
			}
		  if (sum==num)	cout<<num<<" ";
		}
	}
}
int main ()
{
  cout << "Enter a number \n";
 long int n;
  cin >> n;
  cout << "the perfect numbers  " ;
  rasha (n);

  return 0;

}