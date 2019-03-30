#include <stdio.h>
#include <stdlib.h>

//Real constant Recognizer

//Represent states as statement labels
void recognizer1 (void)
{
    sign: switch (getchar())
    {
        case '+': case '-': goto sign;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': goto integer;
        case '.': goto fraction;
        case '\n': printf("Rejected by method 1\n\n"); return;
    }
    integer: switch (getchar())
    {
        case '+': case '-': goto error;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': goto integer;
        case '.': goto real;
        case '\n': printf("Rejected by method 1\n\n"); return;
    }
    fraction: switch (getchar())
    {
        case '+': case '-': goto error;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': goto real;
        case '.': goto error;
        case '\n': printf("Rejected by method 1\n\n"); return;
    }
    error: switch (getchar())
    {
        case '+': case '-': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.': goto error;
        case '\n': printf("Rejected by method 1\n\n"); return;
    }
    real: switch (getchar())
    {
        case '+': case '-': case '.': goto error;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': goto real;
        case '\n': printf("Accepted by method 1\n\n"); return;
    }
}

//Represent states as enumerators of an enumeration type
void recognizer2 (void)
{
    enum state {sign,integer,fraction,real,error} q=sign;
    int ch;
    while((ch=getchar())!='\n')
    switch(q)
    {
        case sign: if (ch=='+'||ch=='-') q=sign;
                   if (ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9') q=integer;
                   if (ch=='.') q=fraction;
                   break;
        case integer: if (ch=='+'||ch=='-') q=error;
                      if (ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9') q=integer;
                      if (ch=='.') q=real;
                      break;
        case fraction: if (ch=='+'||ch=='-') q=error;
                       if (ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9') q=real;
                       if (ch=='.') q=error;
                       break;
        case error: if (ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='+'||ch=='-'||ch=='.') q=error;
                    break;
        case real: if (ch=='+'||ch=='-'||ch=='.') q=error;
                   if (ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9') q=real;
                   break;
    }
    if (q==real) printf("Accepted by method 2\n\n");
    else printf ("Rejected by method 2\n\n");
}

//Use the same representation as method 2
//But, this time you shall build a transition table in advance, and determine the next state to transit by table lookup
void recognizer3 (void)
{
    enum state {sign,integer,fraction,error,real} q=sign;
    enum state trans[5][3]={{sign,integer,fraction},{error,integer,real},{error,real,error},{error,error,error},{error,real,error}};
    int ch;
    inline int classify (char n)
    {
        if (n=='+'||n=='-') return 0;
        if (n=='0'||n=='1'||n=='2'||n=='3'||n=='4'||n=='5'||n=='6'||n=='7'||n=='8'||n=='9') return 1;
        if (n=='.') return 2;
    }
    while((ch=getchar())!='\n')
    q=trans[q][classify(ch)];
    if (q==real) printf("Accepted by method 3\n\n");
    else printf ("Rejected by method 3\n\n");
}
int main (void)
{
    printf("Enter a real constant: ");
    int ch;
    while((ch=getchar())!=EOF)
    {
        ungetc(ch,stdin);
        switch(rand()%3)
        {
            case 0: recognizer1(); break;
            case 1: recognizer2(); break;
            case 2: recognizer3(); break;

        }
        printf("Enter a real constant: ");
    }
}
