#include <stdio.h>
#include <stdlib.h>
const int sz=16;
int a[2][sz];
void out (int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%4d",a[0][i]);
    }
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        printf("%4d",a[1][i]);
    }
    printf("\n\n");
}
void randscore (int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[1][i]=rand()%101;
    }
}
void randperm (int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[0][i]=(i+1);
    }
    int j,t;
    for(i=n;i>1;i--)
    {
        j=rand()%i;
        t=a[0][i-1];
        a[0][i-1]=a[0][j];
        a[0][j]=t;
    }
}
void cyclesort (int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        int t=a[0][i];
        int x=a[1][i];
        int q=t;
        int y=x;
        while(q!=(i+1))
        {
            q=a[0][t-1];
            y=a[1][t-1];
            a[0][t-1]=t;
            a[1][t-1]=x;
            t=q;
            x=y;
        }
        a[0][i]=q;
        a[1][i]=y;
    }
}
void gnomesort (int n)
{
    int i=0;
    while(i<n)
    {
        if (i==0)
            i++;
        else if(a[1][i]<a[1][i-1])
        {
            int m=a[1][i-1];
            int n=a[0][i-1];
            a[1][i-1]=a[1][i];
            a[0][i-1]=a[0][i];
            a[1][i]=m;
            a[0][i]=n;
            i--;
        }
        else
            i++;
    }
}
int main(void)
{
        int n=sz;
        srand(14530529);
        for (int i=1;i<=3;i++) {
                printf("Unsorted data %d ***\n\n",i);
                randperm(n); randscore(n); out(n);
                printf("Cycle-sort by student numbers ...\n\n");
                cyclesort(n);
                out(n);
                printf("Gnome-sort by midterm scores  ...\n\n");
                gnomesort(n);
                out(n);
                printf("\n");
        }
}




