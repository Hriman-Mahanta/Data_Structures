// 11. Write a C program to find if the parenthesis matching in a text file is valid or not.

#include<stdio.h>
#define SIZE 50

//char stack[SIZE];
//int top = -1;

void push(int stack[], int *top, char c)
{
	if(*top == SIZE-1)
		printf("Stack is full\n");
	else
	{
		*top = *top+1;
		stack[*top] = c;
	}
}

void pop(int stack[], int *top)
{
	if(*top == -1)
		printf("Stack is empty\n");
	else
	{
		*top = *top-1;
	}
}

int main(int argc, char *argv[])
{
	FILE *file;
	int flag=0;
	char c;
	int stack[SIZE];
	int top = -1;
	file = fopen(argv[1], "r");
	if(file == NULL)
	{
		printf("Error in opening the file");
	}
	for(c=fgetc(file); c!=EOF; c=fgetc(file))
	{
		if(c=='(' || c=='{' || c=='[')
			push(stack, &top, c);
		else if(c==')')
		{
			if(stack[top] == '(')
				pop(stack, &top);
			else
				flag=1;
		}
		else if(c=='}')
		{
			if(stack[top] == '{')
				pop(stack, &top);
			else
			{
				flag=1;
			}
		}
		else if(c==']')
		{
			if(stack[top] == '[')
				pop(stack, &top);
			else
			{
				flag=1;
			}
		}
	}
	if(flag==0)
	{
		printf("Input file is valid\n");
	}
	else
	{
		printf("Input file is invalid\n");
	}
	return 0;
}
