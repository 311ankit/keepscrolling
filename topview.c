#include<stdio.h>
#include<malloc.h>

struct node
{
struct node *l, *r;
int data;
};

struct node *nn(int data)
{
struct node *n = (struct node *)malloc(sizeof(struct node));
n->l=NULL;
n->r=NULL;
n->data=data;
}

void in(struct node *ro)
{
if(ro==NULL)
return;
in(ro->l);
printf("%d",ro->data);
in(ro->r);
}

void minmax(struct node *ro, int *min, int *max, int hd)
{
if(ro==NULL)
return;
if(hd<*min)
*min=hd;
if(hd>*max)
*max=hd;
minmax(ro->l, min, max, hd-1);
minmax(ro->r, min, max, hd+1);
}

void tv(struct node *ro, int ln, int hd)
{

if(ro==NULL)
{
return;
}
if(ln==hd)
{
printf("%d", ro->data);
}

tv(ro->l, ln, hd-1);
tv(ro->r, ln, hd+1);
}



void main()
{
struct node *a = (struct node *)malloc(sizeof(struct node));
a->data=10;
a->l=nn(5);
a->l->r=nn(7);
a->r=nn(12);
in(a);
int min=0, max=0;
int hd=0, ln;
minmax(a, &min, &max, hd);
//printf("%d%d", min, max);
for(ln=min; ln<=max; ln++)
{
tv(a, ln, hd);
}
}



