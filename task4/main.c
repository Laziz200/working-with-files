#include <stdio.h>

int main() {
    FILE *outputFile;
    int numbers[5];
    int sum = 0;

    printf("5 ta son kiriting: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i]; 
    }
    outputFile = fopen("new.txt", "w");
    if (outputFile == 0) {
        printf("Faylni ochishda xatolik yuz berdi.\n");
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        fprintf(outputFile, "%d", numbers[i]);
        if (i < 4) {
            fprintf(outputFile, "+");
        }
    }
    fprintf(outputFile, "=%d\n", sum);
    fclose(outputFile);

    return 0;
}
