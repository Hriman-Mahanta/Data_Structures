// 2. Write a C program to read text from a file.

#include<stdio.h>

int main()
{
	char str[50];
	FILE *file;
	file = fopen("data.txt", "r");
	if (file == NULL)
	{
		printf("Error in opening the file");
		return -1;
	}
	while (fgets(str, 50, file) != NULL)
	{
		printf("%s", str);
	}
	fclose(file);
	return 0;
}
