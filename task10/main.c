#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    int numbers[10];
    inputFile = fopen("1.txt", "r");
    if (inputFile == NULL) {
        printf("1.txt faylini ochishda xato yuz berdi.\n");
        return 1; 
    }
    for (int i = 0; i < 10; i++) {
        fscanf(inputFile, "%d", &numbers[i]);
    }
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("output.txt faylini ochishda xato yuz berdi.\n");
        fclose(inputFile);
        return 1; 
    }
    fprintf(outputFile, "%d %d\n", numbers[0], numbers[9]);
    fclose(inputFile);
    fclose(outputFile);
    
    printf("Dastlabki va oxirgi son output.txt fayliga yozildi.\n");

    return 0;
}
