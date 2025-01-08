#include <stdio.h>
int main() {
    FILE *file1, *file2, *outputFile;
    char line[100];
    file1 = fopen("1.txt", "r");
    if (file1 == 0) {
        printf("1.txt faylini o'qishda xatolik yuz berdi.\n");
        return 1;
    }
    file2 = fopen("2.txt", "r");
    if (file2 == 0) {
        printf("2.txt faylini o'qishda xatolik yuz berdi.\n");
        fclose(file1);
        return 1;
    }
    outputFile = fopen("output.txt", "w");
    if (outputFile == 0) {
        printf("output.txt faylini yaratishda xatolik yuz berdi.\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }
    while (fgets(line, sizeof(line), file1)) {
        fputs(line, outputFile);
    }
    while (fgets(line, sizeof(line), file2)) {
        fputs(line, outputFile);
    }
    fclose(file1);
    fclose(file2);
    fclose(outputFile);
     printf("Fayllar muvaffaqiyatli birlashtirildi.\n");

    return 0;
}
