#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char line[150];
    char longestWord[150] = "";
    char shortestWord[150] = "";
    char word[150];
    inputFile = fopen("1.txt", "r");
    if (inputFile==NULL) {
        printf("Faylni o'qishda xatolik yuz berdi.\n");
        return 1;
    }
    int isFirstWord = 1;
    while (fscanf(inputFile, "%s", word)!=EOF) {
        int wordLength = strlen(word);
        if (isFirstWord || wordLength > strlen(longestWord)) {
            strcpy(longestWord, word);
        }
        if (isFirstWord || wordLength < strlen(shortestWord)) {
            strcpy(shortestWord, word);
        }
           isFirstWord = 0;
    }
    fclose(inputFile);
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("xatolik yuz berdi.\n");
        return 1;
    }

    fprintf(outputFile, "Eng uzun so'z: %s\n", longestWord);
    fprintf(outputFile, "Eng qisqa so'z: %s\n", shortestWord);
    fclose(outputFile);

    return 0;
}
