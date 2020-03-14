//Program to implement stack using dynamic array
#include<iostream>
#include<cstdlib>
#include<conio.h>

using namespace std;

struct Stack{
	int top;
	int capacity;
	int *array;
};

Stack* createStack(int capacity){
	Stack *s = new Stack;
	if(!s)
		return NULL;
	s->capacity=capacity;
	s->top=-1;
	s->array=new int[s->capacity];
	if(!s->array)
		return NULL;
	return s;
}

int isFull(Stack* s){
	return (s->top==s->capacity-1);
}

int isEmpty(Stack* s){
	return (s->top==-1);
}

void doubleStack(Stack *s){
	s->capacity=2*s->capacity;
	s->array=(int*)realloc(s->array,s->capacity*sizeof(int));
}

void push(Stack* s,int item){
	if(isFull(s)){
		cout<<"Array size is doubled.";
		doubleStack(s);
	}
		s->array[++s->top]=item;
}

int pop(Stack* s){
	if(isEmpty(s)){
		cout<<"Stack Underflow!\n";
		return -1;
	}
	else
		return (s->array[s->top--]);
}


int main(){
	int cap,item;
	cout<<"Enter the capacity:";
	cin>>cap;
	Stack *stack=createStack(cap);
	while(1){
		system("cls");
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
			case 2: cout<<"Popped element:"<<pop(stack);
					break;
			case 3: exit(0);
			default:cout<<"INVALID CHOICE!";
		}
		getch();
	}
	
	return 0;
}
