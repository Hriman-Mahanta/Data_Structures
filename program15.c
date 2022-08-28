// 15. Write a C program to implement a priority queue using heap.

#include<stdio.h>

int size = 0;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;l
}

//Heapify
void heapify(int array[], int size, int i)
{
	int l,r;
	if(size == 1)
		printf("Only one element in the heap");
	else
	{
		int largest = i;
		l = 2*i + 1;
		r = 2*i + 2;
		if(l<size && array[l]>array[largest])
			largest = l;
		if(r<size && array[r]>array[largest])
			largest = r;
		if(largest != i)
		{
			swap(&array[largest], &array[i]);
			heapify(array, size, largest);
		}
	}
}

//Insert
void insert(int array[], int value)
{
	if(size == 0)
	{
		array[0] = value;
		size += 1;
	}
	else
	{
		array[size] = value;
		size += 1;
		for(int i = size/2 - 1; i >= 0; i--)
		{
			heapify(array, size, i);
		}
	}
}
	
//Delete root
void deleteRoot(int array[], int num)
{
	int i;
	for(i=0; i<size; i++)
	{
		if(num == array[i])
			break;
	}
	
	swap(&array[i], &array[size - 1]);
	size -= 1;
	for(int i = size/2 - 1; i>=0; i--)
	{
		heapify(array, size, i);
	}
}


//Build heap

//Display heap
void display(int array[], int size)
{
	for(int i = 0; i<size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main()
{
  int array[10];

  insert(array, 3);
  insert(array, 4);
  insert(array, 9);
  insert(array, 5);
  insert(array, 2);

  printf("Max-Heap array: ");
  display(array, size);

  deleteRoot(array, 4);

  printf("After deleting an element: ");

  display(array, size);
}
