// C-implementation of stack
#include "stack.h"

// function to create a stack of given capacity.
Stack* createStack(unsigned capacity){
	Stack* stack = (Stack*) malloc(sizeof(Stack));
  stack->capacity = capacity;
  stack->top = -1;
  //TODO: Your choice here:
	stack->array = (Bracket*) malloc(stack->capacity * sizeof(Bracket));
	//StackNode* head;
  return stack;
}

// Stack is full when top index is equal to capacity-1
int isFull(Stack* stack){
	return stack->capacity == stack->top+1;
}

// Stack is empty when top is equal to -1 (or head of the list is NULL)
int isEmpty(Stack* stack){
	return stack->top == -1;
}

// Function to add an item to stack.
void push(Stack* stack, Bracket item){
	if (isFull(stack))
        return;
  (stack->array)[++(stack->top)] = item;
}

// Function to remove an item from stack and return it.
Bracket pop(Stack* stack){
	Bracket top = (stack->array)[stack->top];
  (stack->top)--;
	return top;
}
