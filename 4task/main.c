#include <stdio.h>
int main(){
    FILE *f,*a;
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("input.txt faylini ochishda xato yuz berdi.\n");
        return 1;
    }
    a = fopen("output.txt", "w");
    if (a == NULL) {
        printf("output.txt faylini ochishda xato yuz berdi.\n");
        fclose(a);
        return 1; 
    }
    int b;
    int n=0;
    fscanf(f,"%d",&b);
    for (int i = 1; i <= b; i++)
    {    
    fprintf(a,"%d",i);
        n+=i;
        if (i!=5)
        {
        fprintf(a,"+");
        }
    }
    fprintf(a,"=%d\n",n);

    fclose(f);
    fclose(a);

    printf("Matn o'zgartirilib, output.txt fayliga yozildi.\n");
    return 0;
}