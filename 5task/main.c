#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *inputFile, *outputFile;
    char expression[100]; 
    int num1, num2, result;
    char operator;
    inputFile = fopen("Input.txt", "r");
    if (inputFile == NULL) {
        printf("Input faylini ochishda xatolik!\n");
        return 1;
    }
    outputFile = fopen("Output.txt", "w");
    if (outputFile == NULL) {
        printf("Output faylini ochishda xatolik!\n");
        fclose(inputFile);
        return 1;
    }
    while (fgets(expression, sizeof(expression), inputFile)) {
        sscanf(expression, "%d %c %d", &num1, &operator, &num2);
        
        if (operator == '+') {
            result = num1 + num2;
            fprintf(outputFile, "%d+%d=%d\n",num1,num2, result);
        } else if (operator == '-') {
            result = num1 - num2;
            fprintf(outputFile, "%d-%d=%d\n",num1,num2, result);
        } else if (operator == '*') {
            result = num1 * num2;
            fprintf(outputFile, "%d*%d=%d\n",num1,num2, result);
        } else if (operator == '/') {
            if (num2 != 0) {
                result = num1 / num2;
                fprintf(outputFile, "%d/%d=%d\n",num1,num2, result);
            } else {
                fprintf(outputFile, "Xatolik: Nolga bo'linish.\n");
                continue;
            }
        } 
    }
    fclose(inputFile);
    fclose(outputFile);

    printf("Natijalar Output.txt fayliga yozildi.\n");
    return 0;
}
