#include <stdio.h>

//Prime factorization and divisor

void factorization(unsigned n)
{
    printf("Prime factorization of %u = ",n);
    unsigned p=2,e=0,d=1,f=1,k,m; 
	/* p:質因數 e:指數 d:Number of divisors f:Sum of divisors
	k:f的每個括弧內的每項 m:f的每個括弧 */
	
	
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
