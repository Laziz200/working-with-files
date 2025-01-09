#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *inputFile, *outputFile;
    int asciiCode;
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
    while (fscanf(inputFile, "%d", &asciiCode) == 1) {
        fprintf(outputFile, "%c", (char)asciiCode);
    }
    fclose(inputFile);
    fclose(outputFile);
    printf("Matn output.txt fayliga muvaffaqiyatli yozildi.\n");
    
    return 0;
}
