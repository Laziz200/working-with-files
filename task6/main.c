#include <stdio.h>
#include <string.h>
int main(){
    FILE *uzbekFile, *englishFile, *outputFile;
    char uzbekWord[100];
    char englishWord[100];
    uzbekFile = fopen("uzbek.txt", "r");
    if (uzbekFile == NULL) {
        printf("Uzbek faylini o'qishda xatolik yuz berdi.\n");
        return 1;
    }
    englishFile = fopen("english.txt", "r");
    if (englishFile == NULL) {
        printf("English faylini o'qishda xatolik yuz berdi.\n");
        fclose(uzbekFile);
        return 1;
    }
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Output faylini yaratishda xatolik yuz berdi.\n");
        fclose(uzbekFile);
        fclose(englishFile);
        return 1;
    }
    while (fgets(uzbekWord, sizeof(uzbekWord), uzbekFile) && fgets(englishWord, sizeof(englishWord), englishFile)) {
        uzbekWord[strcspn(uzbekWord, "\n")] = '\0'; 
        englishWord[strcspn(englishWord, "\n")] = '\0';

        fprintf(outputFile, "%s - %s\n", englishWord, uzbekWord);
    }
    fclose(uzbekFile);
    fclose(englishFile);
    fclose(outputFile);
    printf("So'zlar muvaffaqiyatli output.txt fayliga yozildi.\n");

    return 0;
}
