#include <stdio.h>
int sum1 (int n)
{
     int r=1;
     while (n/r>=10) r*=10;
     int sum1=0,a=1;
     while (r>0)
    {
     int d=n/r;
     if (a==1)
     printf("%d",d),sum1+=d;
     else if (a%2==1)
     printf("+%d",d),sum1+=d;
     else
     printf("-%d",d),sum1-=d;
     n%=r;
     r/=10;
     a++;
    }
     printf(" = %d\n",sum1);
     return sum1;
}
void sum2 (int n)
{
     int r=1,a=1;
     while(n/r>=10)
    {r*=10; a++;}
     int b=1,e=(a-2);
     while (b<=e)
    {printf("("); b++;}
     int d=1,m=n,c;
     while(n>=10)
    {
     c=n%10;
     printf("%d",c);
     if(d==1)
     printf("*10+");
     else
     printf(")*10+");
     d++;
     n/=10;
    }
     printf("%d = ",n);
     while (m%10==0) m/=10;
     while(m>0)
    {
     c=m%10;
     printf("%d",c);
     m/=10;
    }
     printf("\n");
}
int main(void)
{
     printf("Enter an integer >=0: ");
     int n;
     while
    (scanf("%d",&n)!=EOF)
    {
     sum1(n);
     sum2(n);
     printf("Enter an integer >=0: ");
    }
     return 0;
}











