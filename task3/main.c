#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char line[100];
    int lineNumber, currentLine = 1;

    inputFile = fopen("1.txt", "r");
    if (inputFile == 0) {
        printf("1.txt faylini o'qishda xatolik yuz berdi.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == 0) {
        printf("output.txt faylini yozishda xatolik yuz berdi.\n");
        fclose(inputFile);
        return 1;
    }
    
    printf("O'chirilishi kerak bo'lgan qator raqamini kiriting: ");
    scanf("%d", &lineNumber);

    while (fgets(line, sizeof(line), inputFile)) {
        if (currentLine != lineNumber) {
            fputs(line, outputFile); 
        }
        currentLine++;
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
