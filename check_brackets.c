#include <string.h>
#include "stack.h"

// void print_stack(Stack* stack){
//   printf("Capacity:%d, Top:%d\n",stack->capacity, stack->top);
//   for (int i = 0; i <= stack->top; i++){
//     printf("type:%d, position:%d\n",((stack->array)[i]).type,((stack->array)[i]).position);
//   }
// }

int main() {
    int max_line = 105000;
	char input_buffer[max_line];
	int input_len = 0;

	fgets(input_buffer, max_line, stdin);
	input_buffer [strcspn (input_buffer, "\r\n")] = '\0';  //remove end-of-line characters

    input_len = strlen(input_buffer);
    printf("%d characters were read.\n",input_len);
    // printf("The input was: '%s'\n",input_buffer);
	fflush(stdout);
  Stack * opening_brackets_stack = createStack(max_line);
  for (int position = 0; position < input_len; ++position) {
      char next = input_buffer[position];
      if (next == '(' || next == '[' || next == '{') {
          Bracket bracket = {(int)(next>>5)-1, position};
          push(opening_brackets_stack, bracket);
      }

      if (next == ')' || next == ']' || next == '}') {
          Bracket prev = pop(opening_brackets_stack);
          if (prev.type != (int)(next>>5)-1){
            printf("%d\n",position+1);
            return 0;
          }
      }
  }
  // print_stack(opening_brackets_stack);
  // Printing answer, write your code here
  if (!isEmpty(opening_brackets_stack))
    printf("%d\n",(pop(opening_brackets_stack).position)+1);
  else
	 printf("My result is:Success\n");
  return 0;
}
