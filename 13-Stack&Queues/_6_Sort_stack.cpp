

//Sort a stack using recursion and push/pull/empty functions
//No use of for , while loop accessible

//leetcode:NO
//codingNinja Studio  link: https://www.codingninjas.com/studio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<iostream>
#include<stack>
using namespace std;
void sorting(stack<int>& stack,int num){
	if(stack.empty() || stack.top()<num){
		stack.push(num);
		return;
	}
	int n=stack.top();
	stack.pop();
	sorting(stack,num);
	stack.push(n);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()) return;
	int num=stack.top();
	stack.pop();
	sortStack(stack);
	sorting(stack,num);
}