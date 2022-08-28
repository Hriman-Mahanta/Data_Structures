// 1. Write a C program to write text into a file

#include<stdio.h>

int main()
{
	FILE *file;
	file = fopen("data.txt", "w");
	if (file == NULL)
	{
		printf("Error in creating the file");
		return -1;
	}
	fprintf(file, "Hello World!");
	//fputs("Hello World", file);
	fclose(file);
	return 0;
}
