#include "stack.h"

// Driver program to test your stack of brackets
int main() 
{ 
    Stack* stack = createStack(100); 
	
	Bracket b1 = {ROUND, 0};
    push(stack, b1);
	Bracket b2 = {SQUARE, 1};	
    push(stack, b2);
	Bracket b3 = {CURLY, 2};
    push(stack, b3); 
  
	Bracket top = pop(stack);
    printf("Popped from stack: bracket of type %d at position %d\n", top.type, top.position); 
  
    return 0; 
} 