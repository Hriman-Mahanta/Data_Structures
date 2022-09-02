// 18. Write a C program to implement polynomial with multiple variables and write functions to add and multiply them.

#include<stdio.h>
#include<stdlib.h>

struct polyNode {
	int coeff;
	int numVars;
	int *varPower;
	struct polyNode *link;
};
typedef struct polyNode polyNode;
typedef struct polyNode * polyNodePtr;


//Create a polynomial
int createPolynomial(polyNodePtr *head, char *filename) {
	FILE *file = fopen(filename, "r");
	int numVars, coeff;
	fscanf(file, "%d", &numVars);
	int varPower[numVars];
	while(fscanf(file, "%d", &coeff) != EOF) {
		polyNodePtr temp = (polyNodePtr)malloc(sizeof(polyNode));
		temp->coeff = coeff;
		temp->numVars = numVars;
		temp->varPower = (int*)malloc(sizeof(int)*numVars);
		for(int i=0; i<numVars; i++) {
			fscanf(file, "%d", &temp->varPower[i]);
		}
		printf("%d", temp->coeff);
		if(*head == NULL) {
			*head = temp;
		}
		else {
			temp->link = *head;
			*head = temp;
		}
		//printf("%d", (*head) -> coeff); 
	}
}
	
// Display the polynomial	
void printPolynomial(polyNodePtr head) {
	polyNodePtr temp = head;
	while(temp != NULL) { 
		printf(" %d x^%d y^%d ", temp->coeff, temp->varPower[0], temp->varPower[1]);
		if(temp->link != NULL)
			printf("+");
		temp = temp->link;
	}
}

// Add two polynomials
int addPolynomials(polyNodePtr P1, polyNodePtr P2, polyNodePtr *res) {
	polyNodePtr temp = (polyNodePtr)malloc(sizeof(polyNode));
	while(P1 != NULL && P2 != NULL) {
		if(P1->varPower[0] == P2->varPower[0] && P1->varPower[1] == P2->varPower[1]) {
			temp->coeff = P1->coeff + P2->coeff;
			temp->varPower[0] = P1->varPower[0];
			temp->varPower[1] = P1->varPower[1];
			P1 = P1->link;
			P2 = P2->link;
			temp = temp->link;
		}
		else {
			if(P1->varPower[0] >= P2->varPower[0]) {
				temp->coeff = P1->coeff;
				temp->varPower[0] = P1->varPower[0];
				temp->varPower[1] = P1->varPower[1];
				P1 = P1->link;
				temp = temp->link;
			}
			else {
				temp->coeff = P2->coeff;
				temp->varPower[0] = P1->varPower[0];
				temp->varPower[1] = P1->varPower[1];
				P2 = P2->link;
				temp = temp->link;
			}
		}
	}
	while(P1 != NULL)
	{
		temp->coeff = P1->coeff;
		temp->varPower[0] = P1->varPower[0];
		temp->varPower[1] = P1->varPower[1];
		P1 = P1->link;
		temp = temp->link;
	}
	while(P2 != NULL)
	{
		temp->coeff = P2->coeff;
		temp->varPower[0] = P2->varPower[0];
		temp->varPower[1] = P2->varPower[1];
		P2 = P2->link;
		temp = temp->link;
	}
	temp->link = NULL;
	*res = temp;
}
			
			
		 	

// Multiply two polynomials
int multiplyPolynomials(polyNodePtr P1, polyNodePtr P2, polyNodePtr *res) {
	polyNodePtr temp = (polyNodePtr)malloc(sizeof(polyNode));
	polyNodePtr temp1 = P1;
	polyNodePtr temp2 = P2;
	while(temp1 != NULL) {
		temp2 = P2;
		while(temp2 != NULL) {
			temp->coeff = temp1->coeff * temp2->coeff;
			temp->varPower[0] = temp1->varPower[0] + temp2->varPower[0];
			temp->varPower[1] = temp1->varPower[1] + temp2->varPower[1];
			temp2 = temp2->link;
			temp = temp->link;
		}
	}
	temp->link = NULL;
	*res = temp;
}

int main() {
	polyNodePtr poly1 = NULL;
	polyNodePtr poly2 = NULL;
	polyNodePtr poly3 = NULL;
	polyNodePtr poly4 = NULL;
	createPolynomial(&poly1, "polyinput1.txt");
	createPolynomial(&poly2, "polyinput2.txt");
	printPolynomial(poly1);
//	printPolynomial(poly2);
	addPolynomials(poly1, poly2, &poly3);
	//printPolynomial(poly3);
	multiplyPolynomials(poly1, poly2, &poly4);
	//printPolynomial(poly4);
	return 0;
}

