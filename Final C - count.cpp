#include <iostream>
using namespace std;
int rasha (long int num,long int idnum)
{
  int co=0,sum=0;
  for (;num<=idnum; num++)
	{
	   sum = 0;
	  if (num > 0)
		{
		  for (int j = 1; j < num; j++)
			{
			  if (num % j == 0)sum += j;	
			}
		  if (sum==num)	co++;
		}
	}
  return co;
}
int main ()
{
  cout << "Enter number \n";
 long int n;
  cin >> n;
 long long int id = 2023109806;
  cout << "the counts  " << rasha (n, id);

  return 0;
}