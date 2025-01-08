#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
  FILE *file = fopen("1.txt", "r");
  if (file == NULL){
    printf("Faylni ochishda xatolik yuz berdi");
    return 1;
  }
  FILE *juft = fopen("juft.txt", "w");
  FILE *toq = fopen("toq.txt", "w");
  int number[8];
  int i=0;
  int length;
  while (!feof(file)){
    fscanf(file, "%d", &number[i]);
    i++;
  }
  fclose(file);
  length = sizeof(number)/sizeof(number[0]);
  printf("%d", length);
  for (int i=0; i<length; i++){
    if (number[i]%2 == 0){
      fprintf(juft, "%d ", number[i]);
    }else{
      fprintf(toq, "%d ", number[i]);
    }
  }
  
}
