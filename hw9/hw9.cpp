
#include <stdio.h>
#include <stdlib.h>


struct stack {
 int top;
 char stk[10];
 };
stack s={-1};

void x3 (void);
void x3_2 (void)
{
switch (getchar())
{
    case '0': x3(); return;
    case '1': x3_2(); return;
    case '\n': printf("Rejected\n\n"); return;
}
}
void x3_1 (void)
{
switch(getchar())
{
    case '0': x3_2(); return;
    case '1': x3_1(); return;
    case '\n': printf("Rejected\n\n"); return;
}
}

void x3 (void)
{
switch(getchar())
{
    case '0': x3_1(); return;
    case '1': x3(); return;
    case '\n': printf("Accepted\n\n"); return;
}
}
void eatline (void)
{
    if(getchar()!='\n') eatline();
    return;
}
void show (int);
int x3 (int);
int x3_2 (int n)
{
    if(n>0)
    {
        s.stk[++s.top]=0;
        int r=x3 (n-1);
        s.top--;
        s.stk[++s.top]=1;
        int q=x3_2 (n-1);
        s.top--;
        return r+q;
    }
	else 
	  return 0;
}
int x3_1 (int n)
{
    if(n>0)
    {
        s.stk[++s.top]=0;
        int r=x3_2 (n-1);
        s.top--;
        s.stk[++s.top]=1;
        int q=x3_1 (n-1);
        s.top--;
        return r+q;
    }
	else 
	  return 0;
}
int x3 (int n)
{
    if(n==0)
    {
        show(s.top);
        printf(" ");
        return 1;
    }
    if(n>0)
    {
        s.stk[++s.top]=0;
        int r=x3_1(n-1);
        s.top--;
        s.stk[++s.top]=1;
        int q=x3(n-1);
        s.top--;
        return r+q;
    }
}
void show (int i)
{
    if(i!=0) show(i-1);
    printf("%d",s.stk[i]);
	return ;
}
void ui (void)
{
    printf("Enter your choice: (1) Recognizer (2) Generator: ");
    int n;
    if(scanf("%d",&n)==EOF) return;
    if(n==1)
    {
         eatline();
         int ch;
         printf ("Enter a binary string: ");
         if((ch=getchar())==EOF) return;
         ungetc(ch,stdin);
         x3();
         return ui();
    }
    if(n==2)
    {
        int m;
        printf("Enter the length of binary string: ");
        if(scanf("%d",&m)==EOF) return;
        s.top=-1;
        printf("\n%d binary strings in total",x3 (m));
        printf("\n\n");
        return ui();
    }
}
int main (void)
{
  ui();
}

