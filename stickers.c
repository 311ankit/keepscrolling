#include<stdio.h>

void main()
{
int i,j,n,t,max;
int p[10];
for(i=0;i<10;i++)
{
p[i]=0;
}
printf("Enter the value of n");
scanf("%d",&n);

while(n>0)
  {
    t = n%10;
    p[t]= p[t]+1;
    n = n/10;
  }
max = 0;
for(j=0;j<10;j++)
   {
      if(p[j]>max)
        {
           max=p[j];
        }
   }
printf("%d",max);
}
