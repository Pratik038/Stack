//Program of array implementation of stack.
#include<constream.h>
#include<process.h>

struct Stack{
	int top;
	int capacity;
	int *array;
};

Stack* createStack(int cap){
	Stack *stack=new Stack;
	if(!stack)
		return NULL;
	stack->capacity=cap;
	stack->array=new int[stack->capacity];
	if(!stack->array)
		return NULL:
	stack->top=-1;
	return stack;
}

int isFull(Stack *stack){
	return(stack->top == stack->capacity-1);
}

int isEmpty(Stack *stack){
	return(stack->top==-1);
}

void push(Stack *stack,int item){
	if(isFull(stack))
		cout<<"Stack Overflow";
	else
		stack->array[++stack->top]=item;
}

int pop(Stack *stack){
	if(isEmpty(stack))
		{ cout<<"Stack is Empty";
		 return -1;
		}
	else
		return(stack->array[stack->top--]);
}
void main(){
	clrscr();
	Stack *stack;
	int c,item; cout<<"Enter the capacity of array:"; cin>>c;
	stack=createStack(c);
	while(1){
	clrscr();
	int ch;
	cout<<"\n1.PUSH";
	cout<<"\n2.POP";
	cout<<"\n3.Exit";
	cout<<"\n\nEnter your choice:";
	cin>>ch;
		switch(ch){
			case 1: cout<<"Enter a number:";
				cin>>item;
				push(stack,item);
				break;
			case 2:cout<<"Poped element is "<<pop(stack);
				break;
			case 3:exit(0);
			default:cout<<"\nINVALID CHOICE!";
		}
	getch();
	}
}
