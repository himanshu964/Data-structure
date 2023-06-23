#include<stdio.h>
int main()
{
    int n;
    printf("Enter n value ::");
    scanf("%d",&n);
    TOH(n,'A','B','C');

}
void TOH(int n,char BEG,char AUX,char END)
{
    if(n>0)
    {
        TOH(n-1,BEG,END,AUX);
        printf("\n%C->%c",BEG,END);
        TOH(n-1,AUX,BEG,END);
    }
}