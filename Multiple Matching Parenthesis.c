#include <stdio.h>
#include <stdlib.h>

//top = -1 --> index
//arr --> array representation of stack

//Intializing Counter to count the balanced groups

int count =0;
 
// Creating a stack
struct stack
{
    int size;
    int top;
    char *arr;
};
//to check if the stack is empty or not
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// to check if the stack is full or not.
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// to put element in the stack
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
 
 char stackTop(struct stack* sp)
 {
 	return sp->arr[sp->top];
 }
 
//We cannot directly pop the element from stack.
//Create an integer function, match which will get the characters, popped_ch, and the current character of the expression as two parameters. 
//Inside this function, check if these two characters are the same. 
//If they are the same, return 1, else 0.
 
 int match (char a,char b)
 {
 	if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
  return 0;  
 }
 
int parenthesisMatch(char * exp)
//here the expression is divided into a array exp
{
    // Create and initialize the stack
    struct stack* sp;//create a pointer stack;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;
 
 
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='{'||exp[i]=='['||exp[i]=='(')
		{
            push(sp,exp[i]);
            count++;
            
        }
        else if(exp[i]==')'||exp[i]==']'||exp[i]=='}'){
            if(isEmpty(sp))
			{
                return 0;
            }
            
            popped_ch = pop(sp); 
            
            if(!match(popped_ch,exp[i]))
            {
            	return 0;
			}
        }
    }
 
    if(isEmpty(sp))
    
	{
        return 1;
    }
    
    else
	{
        return 0;
    }
    
}
int main()
{
    char * exp = "((8){(9-8)})";
    // Check if stack is empty
    if(parenthesisMatch(exp)){
        printf("The Parenthesis is Matching.");
        printf("\nCount of Open & Close brackets is %d",count);
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}
