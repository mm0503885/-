#include <stdio.h>

//Binaty-coded decimal

typedef unsigned bcd,decimal;
bcd dec2bcd (decimal n)
{
    unsigned i=0,x=0,a;
    while(n>0)
    {
        a=n%10;
        a<<=(4*i);
        n/=10;
        x+=a;
        i++;
    }
  return x;
 }
bcd add (bcd a,bcd b)
{
    unsigned i=0,s;
    s=a+b;
    while(i<8)
    {
       if(((s>>4*i)&0xF)>=10)
       {
           s+=(6<<4*i);
       }
       if((((a>>4*i)&0xF)+((b>>4*i)&0xF))>=16)
       {
           s+=(6<<4*i);
       }
        i++;
    }
    return s;
}
bcd subtraction (bcd a,bcd b)
{
    unsigned i=0,s;
    s=a-b;
     while(i<8)
    {
       if(((s>>4*i)&0xF)>=10)
       {
           s-=(6<<4*i);
       }
       if((int)(((b>>4*i)&0xF)-((a>>4*i)&0xF))>=7)
       {
           s-=(6<<4*i);
       }
       i++;
    }
    return s;
}
decimal bcd2dec (bcd n)
{
    unsigned i=0,k=1,s=0,m;
    while(i<8)
    {
        m=(n>>4*i)&0xF;
        s+=m*k;
        k*=10;
        i++;
    }
return s;
}
int main (void)
{
    unsigned a,b;
    printf ("Enter a+b or a-b: ");
    while (scanf ("%u",&a)!=EOF)
    {
        if (scanf (" + %u",&b))
        {
           unsigned k=bcd2dec(add(dec2bcd(a),dec2bcd(b)));
           printf ("%u + %u = %u\n\n",a,b,k);
           printf ("Enter a+b or a-b: ");
        }
        if (scanf (" - %u",&b))
        {
           unsigned k=bcd2dec(subtraction(dec2bcd(a),dec2bcd(b)));
           printf ("%u - %u = %u\n\n",a,b,k);
           printf ("Enter a+b or a-b: ");
        }
    }
    return 0;
}
