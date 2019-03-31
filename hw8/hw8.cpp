#include <stdio.h>

//Coin change
const int kinds=4;
int d[kinds]={1,5,10,50};
struct stack {
int top;
int stk[100];
};
stack s;
void facevalue (int k)
{
    if(k==0) return;
	else
	{
	  facevalue(k-1);
      printf("   $%d",d[k-1]);
	}
}
int cc(int n,int k)
{
    if (n<0||k==0) return 0;
    if (n==0)
    {
         int a[kinds]={0};
         int i;
         for(i=s.top;i>=0;i--)
         {
             int x;
             for(x=0;x<kinds;x++)
                if(s.stk[i]==d[x]) a[x]++;
         }
         printf("\n");
         for(i=0;i<kinds;i++)
            printf("%5d",a[i]);
         return 1;
    }
    if (n>0&&k>0)
    {
        s.stk[++s.top]=d[k-1];
        int r=cc(n-d[k-1],k);
        s.top--;
        return r+cc(n,k-1);
    }
}
void ui (void)
{
    int n;
    printf ("Enter amount of money: ");
    if(scanf("%d",&n)==EOF) return ;
    facevalue(kinds);
    s.top=-1;
    printf("\nThere are %d ways to make change.\n\n",cc(n,kinds));
    return ui();
}
int main (void)
{
  ui();
}

