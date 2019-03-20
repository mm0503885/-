#include <stdio.h>
#include <stdlib.h>

typedef struct node { int datum; struct node* succ; } node;

void print(node* p)
{
   	if (p==NULL) printf("\n");
	else { printf("%d ",p->datum); print(p->succ); }
}

bool find(node* p,int d)
{
   	if (p==NULL) return false;
	else if (p->datum==d) return true;
	else return find(p->succ,d);
}
node* insert(node* p,int d)
{
  	node* q=(node*)malloc(sizeof(node));
   	q->datum=d;
	q->succ=p;
	return q;
}
void insertEnd(node** p,int d)
{
    node* q=(node*)malloc(sizeof(node));
    node* r=*p;
    if(*p==NULL)
    {
        q->datum=d;
        q->succ=NULL;
        *p=q;
    }
    else
    {
        while(r->succ!=NULL)
        r=r->succ;
        q->datum=d;
        q->succ=NULL;
        r->succ=q;
    }
}
node* insertEndRec(node* p,int d)
{
    node* q=(node*)malloc(sizeof(node));
    if(p==NULL)
    {
        q->datum=d;
        q->succ=NULL;
        p=q;
    }
    else
    p->succ=insertEndRec(p->succ,d);
    return p;

}
node* erase(node* p,int d)
{
  if (p!=NULL)
		if (p->datum==d) { node* q=p; p=p->succ; free(q); }
		else p->succ=erase(p->succ,d);
	return p;
}
void eraseLast(node** p,int d)
{
   	node *q=*p,*r=*p,*n;
   	int i=1,s;
   	while (q!=NULL)
    {

        if (q->datum==d) {s=i; n=q;}
        q=q->succ;
        i++;
    }
     for(i=1;i<(s-1);i++)
     {
         r=r->succ;
     }
 if (n!=NULL) {
if (n==*p) *p=n->succ; else r->succ=n->succ;
 free(n);
}
}

int x=0;
node* eraseLastRec(node* p,int d)
{
    if (p!=NULL)
       {if(p->succ!=NULL)
        p->succ=eraseLastRec(p->succ,d);
        if (p->datum==d && x==0) { node* q=p; p=p->succ; free(q);  x++; }
       }
	return p;
}

void eraseAll(node* p)
{
	if (p!=NULL) { eraseAll(p->succ); free(p); }
}
size_t length (node* p)
{
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=p->succ;
    }
    return i;
}
size_t lengthRec(node* p)
{
    if (p!=NULL)
    return 1+lengthRec(p->succ);
    else
    return 0;
}

int main(void)
{
   	node* head=NULL;
   	int ch;
	printf("Command: ");
	while ((ch=getchar())!=EOF) {
   		switch(ch) {
      		int d;
		case 'd':
			scanf("%d",&d); head=erase(head,d); break;
        case 'e':
			scanf("%d",&d); eraseLast(&head,d); break;
        case 'E':
			scanf("%d",&d); head=eraseLastRec(head,d); x--; break;

        case 'i':
			scanf("%d",&d); head=insert(head,d); break;
        case 'j':
			scanf("%d",&d); insertEnd(&head,d); break;
        case 'J':
			scanf("%d",&d); head=insertEndRec(head,d); break;

		case 'l':
			printf("length = %d\n",length(head)); break;
		case 'L':
			printf("length = %d\n",lengthRec(head)); break;
		case 'p':
			print(head); break;
        case 's':
			scanf("%d",&d);
			printf(find(head,d)? "Found\n": "Not found\n");
			break;
		default: continue;
          	}
		printf("Command: ");
	}
   	eraseAll(head); head=NULL;
	printf("List erased\n");
}
