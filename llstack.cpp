//Program on linked list implementation of stack.
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
//linked list
struct node{
	int data;
	node *next;
};
//stack
struct stack{
	node *top;
};

stack* createStack(){
	stack *s = new stack;
	s->top = NULL;
	return s;
}

void push(stack *s,int item){
	node *temp = new node;
	if(!temp){
		cout<<"Stack Overflow";
		return;
	}
	temp->data = item;
	temp->next = s->top;
	s->top = temp;
}

int isEmpty(stack *s){
	return (s->top==NULL);
}

int pop(stack *s){
	int item;
	node *temp;
	if(isEmpty(s))
		return -1;
	temp=s->top;
	s->top=s->top->next;
	item=temp->data;
	free(temp);
	return item;
}

int main()
{
	int item;
	stack *stack=createStack();
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
