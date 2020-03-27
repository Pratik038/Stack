#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isOperator(char c){
	return (c=='+' || c=='-' || c=='/' || c=='*');
}
bool isOperand(char c){
	return (c >= '0' && c <= '9');
}

int operation(char c,int op1,int op2){
	if(c=='+') return op1+op2;
	else if(c=='-') return op1-op2;
	else if(c=='*') return op1*op2;
	else if(c=='/') return op1/op2;
	
	else cout<<"unexpected error\n";
	return -1;
}
int evalutePostfix(string exp){
	stack<int> s;
	
	for(int i=0;i<exp.length();i++){
		if(exp[i]==' ' || exp[i]==',') continue;
		
		else if(isOperator(exp[i])){
			int op2=s.top(); s.pop();
			int op1=s.top(); s.pop();
			int result=operation(exp[i],op1,op2);
			s.push(result);
		}
		
		else if(isOperand(exp[i])){
			int operand=0;
			while(i<exp.length() && isOperand(exp[i])){
				operand=operand*10 + exp[i] - '0';
				i++;
			}
			i--;
			s.push(operand);
		}
	}
	return s.top();
}
int main(){
	string exp;
	cout<<"Enter postfix expression:";
	getline(cin,exp);
	cout<<"output = "<<evalutePostfix(exp);
	return 0;
}
