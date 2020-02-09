#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 100
struct stack
{
    int *a;
    int top1,top2;
}stk;

int N,M;

void push1(int);
int pop1();
void push2(int);
int pop2();

int main()
{
    int x,y,z,arr[size],count=0,mode,temp,c1=0,c2=0;
    float sum,mean,median,sd,sum_sd=0;
    scanf("%d",&N);
    scanf("%d",&M);
    stk.top1=-1;
    stk.top2=N;
    stk.a=(int *)malloc(N*sizeof(int));

    for(int i=0;i<M;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        if(z!=-1)
            arr[count++]=z;

        if(x==1&&y==1)
            push1(z);
        else if(x==2&&y==1)
            pop1();
        else if(x==1&&y==2)
            push2(z);
        else if(x==2&&y==2)
            pop2();
    }
    //mean
    for(int i=0;i<count;i++)
        sum+=arr[i];
    mean=sum/count;
    //median
    for(int i=0;i<count-1;i++)
        for(int j=0;j<count-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    if(count%2==0)
        median=(arr[count/2]+arr[count/2-1])/2.0;
    else
        median=arr[count/2];
    //mode
     mode=arr[0];
    for(int i=0;i<count;i++)
    {
    for(int j=i;j<count;j++)
      {
        if(arr[i]==arr[j])
           c2++;
      }
      if(c2>c1)
      {
          c1=c2;
          mode=arr[i];
      }
      c2=0;
    }
    //standard deviation
    for(int i=0;i<count;i++)
        sum_sd+=pow((arr[i]-mean),2);
     sd=sqrt(sum_sd/count);
     sd=(int)(sd*100)/100.0;
     //printing mean,median,mode and standard deviation
     printf("\n%.1f %.1f %d %.2f",mean,median,mode,sd);

     printf("\n");
   for(int i=stk.top1;i>=0;i--)
     printf("%d ",pop1());

     printf("\n");

    for(int i=stk.top2;i<N;i++)
     printf("%d ",pop2());
     return 0;

}
void push1(int data1)
{
    stk.a[++(stk.top1)]=data1;
}
int pop1()
{
    int p1=stk.a[stk.top1];
    stk.top1--;
    return p1;
}
void push2(int data2)
{
    stk.a[--(stk.top2)]=data2;
}
int pop2()
{
    int p2=stk.a[stk.top2];
    stk.top2++;
    return p2;
}
