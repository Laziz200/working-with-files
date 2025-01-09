#include <stdio.h>
#include <ctype.h>
int main(){
    FILE *inputFile, *outputFile;
    char ch;
    int qoshuv=0,ayruv=0,kopaytiruv=0,boluv= 0;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("input.txt faylini ochishda xato yuz berdi.\n");
        return 1;
    }
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("output.txt faylini ochishda xato yuz berdi.\n");
        fclose(inputFile);
        return 1;
    }
    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch == '+') {
            qoshuv++;
        }
        if (ch == '-') {
            ayruv++;
        }
        if (ch == '*') {
            kopaytiruv++;
        }
        if (ch == '/') {
            boluv++;
        }
    }
    fprintf(outputFile, "+ %d ta\n", qoshuv);
    fprintf(outputFile, "- %d ta\n", ayruv);
    fprintf(outputFile, "* %d ta\n", kopaytiruv);
    fprintf(outputFile, "/ %d ta\n", boluv);

    fclose(inputFile);
    fclose(outputFile);

    printf("Amallar soni output.txt fayliga yozildi.\n");

    return 0;
}
