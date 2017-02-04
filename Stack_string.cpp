#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;
int Pop(char [][50], int&);
int Push(char [][50], int&, char[50]);
void Display(char [][50], int);

const int size = 20;

int main()
{
	char Stack[size][50], item[50];
	int top=-1, val;
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
			cout<<"Element deleted is :"<<Stack[top+1]<<endl;
			cout<<"The Stack at present is: "<<endl;
			Display(Stack, top);
		}

		cout<<"Press y and enter if you want to delete more elements: "<<endl;
		cin>>ch;
	}
	return 0;
}

int Push(char Stack[][50], int& top, char a[50])
{
	if(top==size-1)
		return -1;
	else
		strcpy(Stack[++top], a);
	return 0;
}

int Pop(char Stack[][50], int& top)
{
	if(top==-1)
		return -1;
	else
		top--;
	return 0;
}

void Display(char Stack[][50], int top)
{
	cout<<Stack[top]<<" <-- This is top\n";
	int i;
	for(i=top-1;i>=0;i--)
		cout<<Stack[i]<<endl;
}
