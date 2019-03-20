#include <stdio.h>
int main(void)
{
  int a,b,c;
  printf("Enter three integers: ");
  while (scanf("%d %d %d",&a,&b,&c)!=EOF)
  {
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


