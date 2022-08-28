/*
Implement set using link list, you have to perform all the below task through function call. The tasks are
1. int makeSet(struct Set *SetA), [To make a head of the link list]
2. int insert (struct Set *SetA, int value), [To insert value ‘d’ in set ‘S’ , if not exist] 
3. int delete (struct Set *SetA, int value), [To delete value ‘d’ from set ‘S’ if it exists ] 
4. int printSet (struct Set *SetA), [To print the values of set] (6 points)
5. int Union (struct Set *SetA, struct Set *SetB, struct Set *SetC), [To perform union between two sets S1, S2 and return 
	another set]
6. int intersection (struct Set *SetA, struct Set *SetB, struct Set *SetC), [To perform intersection between two sets S1, 
	S2 and return another set] 
7. int difference(struct Set *SetA, struct Set *SetB, struct Set *SetC), [to perform set difference S1 - S2 and] 
8. int deleteSet (struct Set *SetA), [To perform delete a set] 
*/

#include<stdio.h>
#include<stdlib.h>

/*the structure of the Node*/
 struct Set
{
	int data;
	struct Set *next;
};

/*Make the set*/
int makeSet(struct Set **head)
{
	struct Set *head = NULL;
	return 1;
}
/*Create a Node and data element initialize with given value*/
Set* createNode(int data)
{
	struct Set *temp = (struct Set*)malloc(sizeof(struct Set));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

/*Insert the element into the set if not exists*/
int insert(struct Set **set,int data)
{
	if(*set==NULL)
	{
		if(makeSet(set)==1)
		{
			(*set)->data = data;
			//printf("\nElement %d inserted\n",data);
		}else
		{
			return 0;
		}
	}
	else
	{
		struct Set *temp = *set;
		struct Set *prev = NULL;

		while(temp!=NULL)
		{
			if(temp->data==data)
				break;
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL&&prev!=NULL){
			prev->next = createNode(data);
			//printf("\nElement %d inserted\n",data);
		}
		else
		{
			printf("\nDuplicate Element %d\n",data);
			return 0;
		}
	}
	return 1;
}

/*Delete a given element from the set if exists */
int deleteElement(struct Set **set,int data)
{
	struct Set *temp = *set;
	if(temp==NULL)
	{
		printf("\nSet is empty can't delete %d\n",data);
		return 0;
	}
	else
	{
		if(temp->data==data)
		{
			*set = temp->next;
			free(temp);
			printf("\nElement %d is deleted\n",data);
			return 1;
		}
		Set *prev = temp;
		temp=temp->next;
		while(temp!=NULL)
		{
			if(temp->data==data)
				break;
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL){
			printf("\nElement %d is not present in the set\n",data);
			return 0;
		}else
		{
			prev->next = temp->next;
			free(temp);
			printf("\nElement %d is deleted\n",data);
		}
	}
	return 1;
}

/*Delete all elements of the Set*/
int deleteSet(struct Set **set)
{
	Set *temp = *set;
	Set *prev=NULL;
	while(temp!=NULL)
	{
		prev = temp;
		temp=temp->next;
		free(prev);
	}
	*set = NULL;
	printf("\nSet deleted Successfully..");
	return 1;
}

/*Find the union of Set A and Set B and return the result in set C*/
int unionTwoSet(Set **setA,Set **setB,Set **setC)
{
	*setC = NULL;
	Set *temp = *setA;
	Set *ttemp = *setB;

	if(temp==NULL&&ttemp==NULL)
	{
		printf("\nSetA and SetB are empty..\n");
		return 0;
	}
	if(temp!=NULL&&ttemp!=NULL)
	{
		
		while(temp!=NULL)
		{
			struct Set *pc = createNode(temp->data);
			if(*setC==NULL)
			{
				*setC = pc;
			}
			else
			{
				pc->next = (*setC);
				*setC = pc;
			}
			temp=temp->next;
		}
		while(ttemp!=NULL){
			Set *p=*setC;
			while(p!=NULL&&p->data!=ttemp->data){
				p = p->next;
			}
			if(p==NULL){
				Set *pc = creatNode(ttemp->data);
				pc->next = (*setC);
				*setC = pc;
			}
			ttemp = ttemp->next;
		}
	}else if(temp!=NULL){
		while(temp!=NULL){
			Set *pc = creatNode(temp->data);
			if(*setC==NULL){
				*setC = pc;
			}else{
				pc->next = (*setC);
				*setC = pc;
			}
			temp=temp->next;
		}
	}else{
		while(ttemp!=NULL){
			Set *pc = creatNode(ttemp->data);
			if(*setC==NULL){
				*setC = pc;
			}else{
				pc->next = (*setC);
				*setC = pc;
			}
			ttemp=ttemp->next;
		}
	}
}


/*Find the intersection of Set A and Set B and return the result in set C*/
int intersection(Set **setA,Set **setB,Set **setC){
	*setC = NULL;
	Set *temp = *setA;
	Set *ttemp = *setB;

	if(temp==NULL&&ttemp==NULL){
		printf("\nSetA and SetB are empty..\n");
		return 0;
	}
	if(temp!=NULL&&ttemp!=NULL){
		while(ttemp!=NULL){
			Set *p = *setA;
			while(p!=NULL&&p->data!=ttemp->data){
				p = p->next;
			}
			if(p!=NULL){
				Set *pc = creatNode(ttemp->data);
				if(*setC==NULL){
					*setC = pc;
				}else{
					pc->next = (*setC);
					*setC = pc;
				}
			}
			ttemp = ttemp->next;
		}
	}else{
		printf("\nEither SetA or SetB is empty..\n");
		return 0;
	}	
	return 1;
}

/*Find the difference between Set A and Set B and return the result in set C*/
int difference(struct Set **setA, struct Set **setB, struct Set **setC){
	*setC = NULL;
	struct Set *temp = *setA;

	if(temp==NULL)
		return 0;
	while(temp!=NULL)
	{
		Set *p=*setB;
		while(p!=NULL&&p->data!=temp->data)
			p = p->next;
		if(p==NULL)
		{
			struct Set *pc = createNode(temp->data);
			if(*setC==NULL)
			{
				*setC = pc;
			}
			else
			{
				pc->next = (*setC);
				*setC = pc;
			}
		}
		temp=temp->next;
	}
	return 1;
}

/*Display All the Set Element*/
int printSet(struct Set *set)
{
	if(set==NULL)
	{
		printf("\nSet is empty...\n");
		return 1;
	}
	printf("\nSet Contains: \n");
	while(set!=NULL)
	{
		printf("%d ",set->data);
		set = set->next;
	}
	printf("\n");
	return 1;
}


int main(){
	Set *setA=NULL,*setB=NULL,*setC=NULL;
	
	//Testcase1:
	printf("TestCase:1\n\n");
	insert(&setA,1);
	insert(&setB,1);
	insert(&setA,3);
	insert(&setA,4);
	insert(&setA,4);
	insert(&setA,2);
	insert(&setB,2);
	insert(&setB,6);
	insert(&setB,7);
	insert(&setB,8);
	printSet(setA);
	printSet(setB);
	unionTwoSet(&setA,&setB,&setC);
	printf("\nUnion of two sets:");
	printSet(setC);
	intersection(&setA,&setB,&setC);
	printf("\nIntersection of two sets:");
	printSet(setC);
	difference(&setA,&setB,&setC);
	printf("\ndifference of A and B sets:");
	printSet(setC);
	difference(&setB,&setA,&setC);
	printf("\ndifference of B and A sets:");
	printSet(setC);
	deleteSet(&setA);
	deleteSet(&setB);

	//Testcase2:
	
	printf("\nTestCase:2\n\n");
	insert(&setA,1);
	insert(&setA,3);
	insert(&setA,4);
	insert(&setA,5);
	insert(&setB,5);
	insert(&setB,8);
	insert(&setB,7);
	insert(&setB,6);
	insert(&setB,8);
	deleteElement(&setB,5);
	printSet(setA);
	printSet(setB);

	unionTwoSet(&setA,&setB,&setC);
	printf("\nUnion of two sets:");
	printSet(setC);
	intersection(&setA,&setB,&setC);
	printf("\nIntersection of two sets:");
	printSet(setC);
	difference(&setA,&setB,&setC);
	printf("\ndifference of A and B sets:");
	printSet(setC);
	difference(&setB,&setA,&setC);
	printf("\ndifference of B and A sets:");
	printSet(setC);
	deleteSet(&setA);
	deleteSet(&setB);


	return 0;
}
