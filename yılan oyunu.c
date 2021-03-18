#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_CHARS 50


typedef struct c_stack{
  char s[MAX_CHARS];
  int num_chars;
} c_stack;


int push(c_stack *stack, char c){
  if (stack->num_chars<MAX_CHARS){
    stack->s[stack->num_chars] = c;
    stack->num_chars += 1;
    return 1;
  }
  else return 0;
}


char pop(c_stack *stack){
  char c;
  if (stack->num_chars != 0){
    stack->num_chars -= 1;
    return stack->s[stack->num_chars];
  }
  else return '\0';
}


int is_palindrome(){
  char word[MAX_CHARS];
  scanf("%s",word);
  int w_len = strlen(word);
  c_stack stack;
   stack.num_chars = 0;

  int i = 0;
  for (; i < w_len / 2; i++){
    push(&stack,word[i]);
  }

  if (w_len % 2 == 1) i++;

  while (i < w_len){
    if (pop(&stack) != word[i]) return 0;
    i++;
  }
  return 1;
}


int main(void) {
  printf("Enter a palindrome:\n");
  if (is_palindrome())
    printf("This is a palindrome.");
  else
printf("This is not a palindrome.");
}
