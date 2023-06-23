//recursion
//Write a program to print first N terms of Fibonacci series.
//print n even natural no..
/*#include<stdio.h>
int main()
{
   int n,i;
   printf("Enter n value::");
   scanf("%d",&n);
   int a=1,b=-1,c;
   for(i=1;i<=n;i++)
   {
       c=a+b;
       printf("%d,",c);
       b=a;
       a=c;
   }

}
*/
/*#include<stdio.h>
int main()
{
     int n;
   printf("Enter n value::");
   scanf("%d",&n);
      evenNR(n);//evenN(n);
}
void evenNR(int n)
{
    if(n>0)
    {
       // evenN(n-1);
        printf("%d,",2*n);
        evenNR(n-1);
    }
}*/
//write a recurive function to print first n odd natural no.
/*#include<stdio.h>
int main()
{
     int n;
   printf("Enter n value::");
   scanf("%d",&n);
   oddNR(n); //oddN(n);//evenN(n);
}
void oddNR(int n)
{
    if(n>0)
    {
         printf("%d,",2*n-1);
    oddNR(n-1);
    //printf("%d,",2*n-1);
    }
}*/
/*#include<stdio.h>
int main()
{
     int n;
   printf("Enter n value::");
   scanf("%d",&n);
   printf("%d",sumN(n));
}
int sumN(int n)
{
    if(n==0)
    return 0;
    return(n+sumN(n-1));
}
*/
/*#include<stdio.h>
int main()
{
 int n;
 printf("Enter the n value::");
 scanf("%d",&n);
 printf("%d",sumE(n));
   
}
int sumE(int n)
{
    int c;
    if(n==0)
    return 0;
    else{
        c=2*n-1+sumE(n-1);
        return(c);
    }
}
*/
//write a recursive function to calculte
#include<stdio.h>
int main()
{
    printf("%d",sum(5));
}
int sum(int n)
{
    if(n==1)
    return(1);
    return(n+sum(n-1));
}
