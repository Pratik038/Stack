#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

void reverse(char *st,int n){
	stack<char> s;
	for(int i=0;i<n;i++)
		s.push(st[i]);
	for(int i=0;i<n;i++){
		st[i]=s.top();
		s.pop();
	}
}
int main(){
	char st[51];
	cout<<"Enter a string:";
	gets(st);
	reverse(st,strlen(st)); 
	cout<<"Reverse:";
	puts(st);
	return 0;
}
