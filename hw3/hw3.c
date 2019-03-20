#include <stdio.h>
void factorization(unsigned n)
{
    printf("Prime factorization of %u = ",n);
    unsigned p=2,e=0,d=1,f=1,k,m;
	while(p<=n)
    {
        if(n%p==0)
    	{
    	    k=1,m=1;
    		while(n%p==0)
			{
              n/=p;
			  e++;
			  k*=p;
			  m+=k;
            }
	        if(n!=1) printf("%u^%ux",p,e); else printf("%u^%u\n",p,e);
	        d*=(1+e);
	        f*=m;
	        e=0;
	        p++;
    	}
    	else
		{
		  p++;
	    }
    }
    printf("Number of divisors = %u\n",d);
    printf("Sum of divisors = %u\n\n",f);

}
int main (void)
{
    printf("Enter an unsigned integer >= 2: ");
    unsigned n;
    while(scanf("%u",&n)!=EOF)
    {
       factorization(n);
       printf("Enter an unsigned integer >= 2: ");
    }
     return 0;
}
