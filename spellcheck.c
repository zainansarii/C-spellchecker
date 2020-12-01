/*Read words one at a time and places them into the correct part of an
array so that all words are alphabetically sorted*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINES 2891
#define LENGTH 20

enum bool{true, false};
typedef enum bool bool;

void alpha_sort(char words[LINES][LENGTH]);
void print_str(char words[LINES][LENGTH]);
bool search(char words[LINES][LENGTH], char input[LENGTH]);

int main(void)
{
  int i;
  char words[LINES][LENGTH], input[LENGTH];
  FILE *f;

  if((f = fopen("34words.txt", "r")) == NULL){
    printf("Error: cannot read file\n");
    exit(EXIT_FAILURE);
  }
  for(i = 0; i < LINES; i++){
    fscanf(f, "%s", words[i]);
  }
  alpha_sort(words);

  scanf("%s", &input);
  if(search(words, input) == true){
    printf("Your word is present in the list!");
  }
  else{
    printf("Your word is not present in the list!");
  }

  fclose(f);
  return 0;
}

void alpha_sort(char words[LINES][LENGTH])
{
  int i, j;
  char temp[LENGTH];

  for(i = 0; i < LINES; i++){
    for(j = 0; j < i; j++){
      if(strcmp(words[i], words[j]) < 0){
        strcpy(temp, words[j]);
        strcpy(words[j], words[i]);
        strcpy(words[i], temp);
      }
    }
  }
}

void print_str(char words[LINES][LENGTH])
{
  int i;
  for(i = 0; i < LINES; i++){
    printf("%s\n", words[i]);
  }
  printf("\n");
}

bool search(char words[LINES][LENGTH], char input[LENGTH])
{
  int i, j;

  for(i = 0; i < LINES; i++){
    if(strcmp(words[i], input) == 0){
      return true;
    }
  }
  return false;
}
