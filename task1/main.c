#include <stdio.h>
int main(){

    FILE *f = fopen("1.txt", "r");
    int b;
    float count=0;
    int sum=0;
    while (!feof(f))
    {
        sum++;
        fscanf(f,"%d",&b);
        count+=b;
        printf("%d\n",b);
    }
    printf("yigindi:%.1f\n",count);
    float c=count/sum;
    printf("o'rta arifmetik=%.1f\n",c);
}