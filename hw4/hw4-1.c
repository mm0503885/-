#include <stdio.h>
#include <stdbool.h>

bool good (unsigned n)  //判斷n的每個位數的值相加是否為'g'+'o'+'o'+'d'
{
  unsigned int x='g'+'o'+'o'+'d';
  char d[10];
  int i=0;
  while(n>0)
  {
      d[i]=n%10;
      n/=10;
      i++;
  }
  while(i<10)
  {
      d[i]=0;
      i++;
  }
  i=i-2;
  while(i>=0)
  {
      d[i]=d[i]+d[i+1];
      i--;
  }
  unsigned int s=d[0]+d[1]+d[2]+d[3]+d[4]+d[5]+d[6]+d[7]+d[8]+d[9];
  if(s==x)
    return true;
  else
    return false;
}
bool bad(unsigned n) //判斷n是否包含1,3,5
{
    char d[10]={0};
    int a;
    while(n>0)
  {
      a=n%10;
      n/=10;
      d[a]++;
  }
  if(d[1]>=1 && d[3]>=1 && d[5]>=1)
    return true;
  else
    return false;
}
bool ugly(unsigned n) //判斷n是否被2,3,5整除
{
    while(n%2==0)
        n/=2;
    while(n%3==0)
        n/=3;
    while(n%5==0)
        n/=5;
    if(n==1)
        return true;
    else
        return false;
}

int main (void)
{
    unsigned n;
    printf("Enter an unsigned integer >= 1: ");
    while(scanf("%d",&n)!=EOF)
    {
	  if(good(n))
        printf("Good, ");
      else
        printf("Not good, ");
	  if(bad(n))
        printf("Bad, ");
      else
        printf("Not bad, ");
      if(ugly(n))
        printf("Ugly\n\n");
      else
        printf("Not ugly\n\n");
      printf("Enter an unsigned integer >= 1: ");
    }
 return 0;
}
