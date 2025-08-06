#include<stdio.h>
int main(){
int arr[5],i,sum=0;
float avg;
printf("enter the arr number");

for(i=0;i<5;i++)
{
    scanf("%d",&arr[i]);
    sum=sum+arr[i];
    avg=sum/5;

}
printf("sum %d\n",sum);
printf("avg %f\n",avg);
    return 0;
}