#include <stdio.h>
#include <ctype.h>
int main(){
    FILE *inputFile, *outputFile;
    char ch;
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
    int inWord = 0; 
    while ((ch = fgetc(inputFile)) != EOF) {
        if (isspace(ch)) {
            inWord = 0;
            fputc(ch, outputFile); 
        } else {
            if (!inWord) {
                ch = toupper(ch);
                inWord = 1;
            }
            fputc(ch, outputFile);
        }
    }
    fclose(inputFile);
    fclose(outputFile);

    printf("Matn o'zgartirilib, output.txt fayliga yozildi.\n");

    return 0;
}
