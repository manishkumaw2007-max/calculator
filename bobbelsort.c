#include<stdio.h>
int main(){
int arr[10],i,j,temp,pos;
printf("enter the element of arr\n");
for(i=0;i<10;i++)
scanf("%d",&arr[i]);
for ( i = 0; i < 9; i++)
{
    /* code */
    pos=i;
    for(j=i+1;j<10;j++){
        if(arr[pos]>arr[j])
        pos=j;
    }
    if(pos!=i)
    {
        temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
    
    }
}
printf("\n sorset am arr\n");
for(i=0;i<10;i++)
printf("%d\n",arr[i]);
    return 0;
}