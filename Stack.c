#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
///ADVANTAGES OF USING STACK
/**1.Helps you to manage the data in a Last In First Out(LIFO)
method which is not possible with Linked list and array.

2.When a function is called the local variables are stored in a stack,
and it is automatically destroyed once returned.

3.A stack is used when a variable is not used outside that function.

4.It allows you to control how memory is allocated and deallocated.

5.Stack automatically cleans up the object.

6.Not easily corrupted

7.Variables cannot be resized.*/


///DISADVANTAGES OF USING STACK/
/**Stack memory is very limited.
Creating too many objects on the stack
 can increase the risk of stack overflow.

Random access is not possible.

Variable storage will be overwritten,
 which sometimes leads to undefined behavior of the function or program.

The stack will fall outside of the memory area,
which might lead to an abnormal termination.*/

struct ArrayStack* createMemory(int);
struct ArrayStack
{
    int capacity;
    int top;
    int *array;
};
 struct ArrayStack *stack;
struct ArrayStack* createMemory(int cap)
{
    stack=(struct ArrayStack*)malloc(sizeof(struct ArrayStack));
    stack->top=-1;
    stack->capacity=cap;
    stack->array=(int*)malloc(sizeof(int)* stack->capacity);
    return(stack);
}
void push(int data)
{
    if(stack->top==stack->capacity-1)
      printf("Stack is full");
      else
      {
          stack->top++;
          stack->array[stack->top]=data;
      }
}
int pop()
{
    if(stack->top==-1)
    {
        printf("Cannot pop Underflow");
    }
    else
    {

       int key=stack->array[stack->top] ;
          stack->top--;
    return(key);
    }
}
int main()
{
    createMemory(5);
    push(10);
    push(20);
   printf("%d\n",pop());
    printf("%d\n",pop());
     printf("%d\n",pop());
}










