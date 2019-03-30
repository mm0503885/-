#include <stdio.h>
#include <stdlib.h>
const int sz=16;
int a[2][sz];

// This function prints out array a[0..1][0..n-1]
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

//This function generates n random scores in the range 0..100 and stores them in array a[1][0..n-1]
void randscore (int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[1][i]=rand()%101;
    }
}

//This function generates a random permutation of 1,2,3,...,and n in array a[0][0..n-1]
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

//cyclesort //see spec
void cyclesort (int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        int number=a[0][i];
        int score=a[1][i];
        int position=number;
        int score_chg=score;
        while(position!=(i+1))
        {
            position=a[0][number-1];
            score_chg=a[1][number-1];
            a[0][number-1]=number;
            a[1][number-1]=score;
            number=position;
            score=score_chg;
        }
        a[0][i]=position;
        a[1][i]=score_chg;
    }
}

//gnomesort //see spec
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




