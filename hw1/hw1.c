#include <stdio.h>
#include <stdlib.h>


//Arithmetic and Geometric series
int main(void)
{
  int a,b,c;
  while (1)
  {
  printf("Enter three integers: ");
  scanf("%d %d %d",&a,&b,&c);
  int n=(b+c-2*a)*(a+c)/2/(b-a);
  printf("Sum of the arithmetic series by formula      = %d\n",n);
  int sum=0,i=a,d=b-a;
  for (i;abs(i)<= abs(c);i+=d) sum+=i;
  printf("Sum of the arithmetic series by accumulation = %d\n",sum);
  n=(a*a-b*c)/(a-b);
  printf("Sum of the geometric  series by formula      = %d\n",n);
  sum=0,i=a,d=b/a;
  for (i; abs(i)<= abs(c);i*=d) sum+=i;
  printf("Sum of the geometric  series by accumulation = %d\n",sum);
  printf("Enter three integers: ");
  }
  return 0;
}


