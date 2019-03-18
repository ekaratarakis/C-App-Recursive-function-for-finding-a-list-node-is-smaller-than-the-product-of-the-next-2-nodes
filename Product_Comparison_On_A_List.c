#include <stdio.h>
#include <stdlib.h> 

// Declaration of list
struct list
{
	int value; // the list contains 2 variables : value and next
	struct list *next;
};

// Declaration of recursive function
struct list *productCompare(struct list *headIn,struct list **ptr);

// Declaration of functions for displaying all nodes of the list and insert nodes to the list 
void display_all_nodes(struct list *list_head);
struct list *insertEnKomvos(int n, struct list *listhead);

/////////////////////////////////
///////START OF THE MAIN/////////
/////////////////////////////////
int main()
{
	struct list *headEn;
    	headEn=(struct list *)malloc(sizeof(struct list)); // dynamic memory allocation for headEn using malloc
    
    	struct list *ptr;
    	ptr=(struct list *)malloc(sizeof(struct list)); // dunamikh desmeush mnhmhs gia ton ptr me malloc

    	int numberOfNodes,i,number;
    	char choice;
        
    	do // "do while" for iterative use of this app
    	{
		headEn = NULL;
	    	ptr=NULL; // initializing the head and the pointer of the list to NULL 
	    
	    	printf("Please, give number of total inputs of the list:\n:) ");
	    	do
	    	{
			scanf("%d",&numberOfNodes);//to plithos einai o arithmos twn stoixeiwn ths listas
	    		if(numberOfNodes<0) // checking if the list entered by the user has a size greater than 0
			{
				printf("Please give a positive value.\n\n");
			}
	    	}while(numberOfNodes<0);

	    	/****************************************************
				Insert nodes in the list
		****************************************************/

	    	printf("Start entering %d numbers.\n",numberOfNodes);
	    	for(i=0;i<numberOfNodes;i++)
	    	{
			printf("\nPlease enter input number %d : ",i+1);
	    		scanf("%d",&number);
	    		// inserting nodes in the list using the fucntion "insertEnKomvos" 
	    		headEn=insertEnKomvos(number,headEn);
	    	}

	    	display_all_nodes(headEn);
	    	system("\nPAUSE\n");
	    
	    	// RECURSIVE CALL
	    	productCompare(headEn,&ptr);
	    	if(ptr==NULL)
	    	{ // Case 1 : Node smaller than the product of the next 2 nodes found
	    		printf("\nFound satisfying elements!!!\n");
	    	}
	    	else
	    	{ // Case 2 : Node smaller than the product of the next 2 nodes not found
	    		printf("Found NO satisfying elements!!!\n");
	    		//printf("Pointer = %d\n",ptr);
	    	}
	    	system("\nPAUSE\n");
	    
    		printf("\n\nDo you want to re-run the program?\nPress y/Y for yes, or anything else to terminate.\n");
    		choice=getch();
    		if(choice=='y' || choice=='Y')
    		{
       			free(headEn); // free allocated memory
       			system("cls");
    		}	
    	
	}while (choice =='Y' || choice =='y');
    	return 0;   
}

struct list *productCompare(struct list *headIn,struct list **ptr) // RECURSIVE FUNCTION
{
	// checking for cases of 0 or less than or equal 2 nodes 
    	if (headIn==NULL || headIn->next==NULL || headIn->next->next == NULL) // empty list
	{
		printf("The list has 2 or less elements (no less than 0)-considered as success.\n"); // in these cases we consider that the list satisfy the necessary condition
		*ptr=NULL; // returning NULL
		return *ptr;
	}
	else
	{
		// checking for case of more than 2 nodes
    		if((headIn->next->next->next == NULL) && ((headIn->value)<(headIn->next->value)*(headIn->next->next->value)))
        	{
			printf("SUCCESS\n\nSatisfying elements were found in this list.\n");
			*ptr=NULL; // returning NULL due to success
            		return *ptr; // rerutning the pointer ptr                         
        	} 
		else if((headIn->value)<(headIn->next->value)*(headIn->next->next->value))
        	{
		        productCompare(headIn->next,ptr); // recursive call of the function "productCompare" 
        	}
	    	else 
        	{
            		printf("SORRY-No satisfying elements were found.\n"); 
            		*ptr=headIn; // returning the 1st node of the triplet that doesn't satisfy the necessary condition
            		return *ptr; // returning the pointer ptr
        	}
    	}
}
///////////////////////////////
/////END OF productCompare/////
///////////////////////////////

void display_all_nodes(struct list *list_head) // function for displaying all nodes of the list
{
	printf("\nYou've entered following list:\n");
	if(list_head != NULL) // checking if the list is empty - NULL
	{
		struct list *p;
	    	p=list_head;
		printf("["); // printing all the nodes of the list
		while(p!=NULL)
		{
			printf(" %d ",p->value);
			p=p->next;
		}              
		printf("]\n");
	}
	else
	{
		printf("[]\n"); // this is for empty list
	}
}/*END OF display_all_nodes*/

struct list *insertEnKomvos(int n, struct list *listhead) // function for insert nodes to the list
{
	struct list *node,*returnValue;
    	node = malloc(sizeof(struct list)); // dynamic memory allocation using malloc function
    	struct list *node2 = listhead;
    	node->value = n; // insert to every node, every value 
    	node->next = NULL; // setting the next node to NULL
    	if (listhead == NULL)
    	{
		returnValue = node;
        	return returnValue;
    	}
    	while(node2->next !=NULL)
    	node2=node2->next;
    	node2->next=node;
    	return listhead;
}/*END OF insertEnKomvos*/	
