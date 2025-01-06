#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    FILE *f = fopen("data.txt", "r+");

    char word[10];

    scanf("%s", word);

    while (!feof(f)) {
        char temp[10];
        fscanf(f, "%s", temp);

        puts(temp);

        if (strcmp(temp, word) == 0) {
            for (int i = 0; i < 10; i++) {
                if (islower(temp[i])) {
                    temp[i] = toupper(temp[i]);
                }
            }
            fseek(f, -strlen(temp), SEEK_CUR);
            fprintf(f, "%s", temp);
        }
    }
   
    fclose(f);

    return 0;
}
