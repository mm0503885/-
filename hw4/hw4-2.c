#include <stdio.h>
unsigned ugly (unsigned n)
{
    unsigned H[n+1];
    const unsigned x[3]={2,3,5};
    int index[3]={0};
    unsigned ugly[3];
    int j=1,min;
    H[0]=1;
    while(j<n+1)
    {
       int i=0;
       while(i<3)
       {
          ugly[i]=x[i]*H[index[i]];
          i++;
       }
       min=ugly[0];
       if(ugly[1]<min) min=ugly[1];
       if(ugly[2]<min) min=ugly[2];
       H[j]=min;
       if(min==ugly[0] && min!=ugly[1] && min!=ugly[2]) index[0]++;
       if(min!=ugly[0] && min==ugly[1] && min!=ugly[2]) index[1]++;
       if(min!=ugly[0] && min!=ugly[1] && min==ugly[2]) index[2]++;
       if(min==ugly[0] && min==ugly[1] && min!=ugly[2]) {index[0]++; j--;}
       if(min==ugly[0] && min!=ugly[1] && min==ugly[2]) {index[0]++; j--;}
       if(min!=ugly[0] && min==ugly[1] && min==ugly[2]) {index[1]++; j--;}
       if(min==ugly[0] && min==ugly[1] && min==ugly[2]) {index[0]++; j--;}
       j++;
    }
    printf("H[%u] = %u\n\n",n,H[n]);
}
int main (void)
{
    unsigned n;
    printf("Enter an unsigned integer: ");
    while(scanf("%u",&n)!=EOF)
    {
      ugly(n);
      printf("Enter an unsigned integer: ");
    }
    return 0;
}










