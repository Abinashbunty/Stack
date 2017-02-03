#include <iostream>
using namespace std;
int Pop(int [], int&);
int Push(int [], int&, int);
void Display(int [], int);

const int size = 20;

int main()
{
	int Stack[size], item, top=-1, val;
	char ch = 'y';
	while(ch=='y' || ch=='Y')
	{
		cout<<"Enter an item for insertion"<<endl;
		cin>>item;
		val = Push(Stack, top, item);
		if(val==-1)
		{
			cout<<"Overflow condition";
			break;
		}

		cout<<"The Stack at present is: "<<endl;
		Display(Stack, top);
		cout<<"Press y and enter if you want to insert more elements: "<<endl;
		cin>>ch;
	}

	cout<<"Elements are going to be deleted now."<<endl;
	ch = 'y';
	while(ch=='y' || ch=='Y')
	{
		val = Pop(Stack, top);
		if(val==-1)
		{
			cout<<"Underflow condition"<<endl;
			break;
		}

		else
		{
			cout<<"Element deleted is :"<<val<<endl;
			cout<<"The Stack at present is: "<<endl;
			Display(Stack, top);
		}

		cout<<"Press y and enter if you want to delete more elements: "<<endl;
		cin>>ch;
	}
	return 0;
}

int Push(int Stack[], int& top, int a)
{
	if(top==size-1)
		return -1;
	else
		Stack[++top] = a;
	return 0;
}

int Pop(int Stack[], int& top)
{
	int answer;
	if(top==-1)
		return -1;
	else
	{
		answer = Stack[top];
		top--;
	}

	return answer;
}

void Display(int Stack[], int top)
{
	cout<<Stack[top]<<" <-- This is top\n";
	int i;
	for(i=top-1;i>=0;i--)
		cout<<Stack[i]<<endl;
}
