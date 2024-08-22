#include<stdio.h>
#include<string.h>
int main()
{
int x[20],y[30],i,j,k,count,n;
printf("Enter frame size: ");
scanf("%d",&n);
printf("Enter the frame in the form of 0 and 1: ");
for(i=0; i<n; i++)
scanf("%d",&x[i]);
i=0;
count=1;
j=0;
while(i<n)
{
if(x[i]==1)
{
y[j]=x[i];
for(k=i+1; x[k]==1 && k<5; k++)
{
j++;
y[j]=x[k];
count++;
if(count==5)
{
j++;
y[j]=0;
}
i=k;
}
}
else
{
y[j]=x[i];
}
i++;
j++;
}
printf("After Bit Stuffing: ");
for(i=0; i<j; i++)
printf("%d",y[i]);
return 0;
}