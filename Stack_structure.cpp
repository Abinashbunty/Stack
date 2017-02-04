#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;
struct student
{
	char name[25];
	int age;
	char gender;
};
int Pop(student [], int&);
int Push(student [], int&, student);
void Display(student [], int);

const int size = 20;

student Stack[size];

void ReadStu(student &s)
{
	cout<<"Enter name of the student: "<<endl;
	cin>>s.name;
	cout<<"Enter age of the student: "<<endl;
	cin>>s.age;
	cout<<"Enter M for male or F for female: "<<endl;
	cin>>s.gender;
}

void Disp_stu(student s)
{
	cout<<"Name: "<<s.name<<endl;
	cout<<"Age: "<<s.age<<endl;
	if(s.gender=='F' || s.gender=='f')
		cout<<"Gender: Female\n\n";
	else if(s.gender=='M' || s.gender=='m')
		cout<<"Gender: Male\n\n";
	else
		cout<<"Prefer not to say\n\n";
}

int main()
{
	student a;
	int top=-1, val;
	char ch = 'y';
	while(ch=='y' || ch=='Y')
	{
		cout<<"\nEnter an item for insertion"<<endl;
		ReadStu(a);
		val = Push(Stack, top, a);
		if(val==-1)
		{
			cout<<"\nOverflow condition";
			break;
		}

		cout<<"\nThe Stack at present is: "<<endl;
		Display(Stack, top);
		cout<<"\nPress y and enter if you want to insert more elements: "<<endl;
		cin>>ch;
	}

	cout<<"\nElements are going to be deleted now."<<endl;
	ch = 'y';


	while(ch=='y' || ch=='Y')
	{
		val = Pop(Stack, top);
		if(val==-1)
		{
			cout<<"\nUnderflow condition"<<endl;
			break;
		}

		else
		{
			cout<<"\nElement deleted is :"<<endl;
			Disp_stu(Stack[top+1]);
			cout<<"\nThe Stack at present is: "<<endl;
			Display(Stack, top);
		}

		cout<<"\nPress y and enter if you want to delete more elements: "<<endl;
		cin>>ch;
	}
	return 0;
}

int Push(student Stack[], int& top, student a)
{
	if(top==size-1)
		return -1;
	else
	{
		top++;
		strcpy(Stack[top].name, a.name);
		Stack[top].age = a.age;
		Stack[top].gender = a.gender;
	}
	return 0;
}

int Pop(student Stack[], int& top)
{
	if(top==-1)
		return -1;
	else
		top--;
	return 0;
}

void Display(student Stack[], int top)
{
	Disp_stu(Stack[top]);
	cout<<"\nThe above set is top structure\n";
	int i;
	for(i=top-1;i>=0;i--)
		Disp_stu(Stack[i]);
	cout<<"\n";
}
