#include<stdio.h>
#include<stdlib.h>

//declaring struct node
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
int count=0;

int insertAtBegin();
int insertAtEnd();
int insertAtPosition();
int deleteAtBegin();
int deleteAtEnd();
int deleteAtPosition();

//function for creating node
void createNode()
{
    int i=0,n,choice;
    struct node *newnode,*temp;
    
    printf("Enter the number of node you want :");
    scanf("%d",&choice);
    if(choice==0)
		{
			printf("Please enter a non-zero value.\n");
			return;
		}
    while (i<choice)
    {
        //memory is allocated
		newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data\n");
        scanf("%d",&n);//newline (\n) can cause issus
        // nw ->data should come first otherwise incorrect data will come
		newnode->data=n;
        newnode->next=head;
       // head=newnode;
        
        
        if(head==NULL)
        {
             head=newnode;
             temp=newnode;
        }
        else 
        {
            temp->next=newnode;
            temp=newnode;
        }
        //count is use to count how many node will our list contain and i++ for iteration
        i++;
    }
    choice++;
    
}
//function for display of link list
void displayNode()
{
  struct node *temp;
  temp=head;
  printf("The linked list is\n");
  
  while (temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->next;
  }
 
}

int insertNode()
{
int choice,Exit=1;
	while(1)
	{
		printf("Enter the choice from below:\n1.Insert At Begin\n2.Insert At End\n3.Insert At Position\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insertAtBegin();
				break;
			case 2:
			    insertAtEnd();
				break;
			case 3:
			    insertAtPosition();
				break;
			case 4:
				Exit=1;
			    return 0;//it will exit the loop instead of doing nothing
		    default :
			    printf("Invalid choice");
				break;					
		}
	}
	return 0;
}

//insert at begin
int insertAtBegin()
{
    int n;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&n);
    
    newnode->data=n;
    newnode->next=head;
    head=newnode;
    count++;
    return 0;
}
//insert at end
int insertAtEnd()
{
    int n;
    struct node *newnode,*temp;
    if (head==NULL)
     {
    	printf("There is no node in list...");
    	return 0; 
	}
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d",&n);
        
        newnode->next=0;
        newnode->data=n;
        //logic for insert at end
        temp=head;
        while(temp->next!=0)
        {
           temp=temp->next;
        }
        temp->next=newnode;	
        count++;
	}
    
    return 0;
}

//insert at position
int insertAtPosition()
{
    int pos,i=1,n;
    struct node *newnode,*temp;
    printf("Enter the position at which you want to insert :");
    scanf("%d",&pos);
    //to cheak whether we have more node than the node that we want to insert at position
    if(pos<1 || pos>count+1)
    {
        printf("The link list is not of length %d",i);
    }
    
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data :");
    scanf("%d",&n);
	newnode->data=n;
	    
    if(pos==1)
    {
    	newnode->next=head;
    	head=newnode;
			
	}
    else
    {
        temp=head;
        //if we want to insert node at 3 then our temp should be at 2 position
        while (i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;     
    }
    count++;
    return 0;
    
}

//fuction for delete
void deleteNode()
{
	int choice,Exit;
	while(1)
	{
		printf("Enter the choice from below:\n1.Delete At Begin\n2.Delete At End\n3.Delete At Position\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				deleteAtBegin();
				break;
			case 2:
			    deleteAtEnd();
				break;
			case 3:
			    deleteAtPosition();
				break;
			case 4:
				Exit=1;
			    return ;//it will exit the loop instead of doing nothing
		    default :
			    printf("Invalid choice");
				break;					
		}
	}
	
}

//fuction for delete at begin
int deleteAtBegin()
{
	struct node *temp;
	temp=head;
	if (head==NULL)
	{
		printf("No element present in list");	
	}
	// to delete the first node we have to make head point to the second node(i.e head->next will point to second node)
	else
	{
		head=head->next;
	    free(temp);
		
	}
	count--;
	return 0;	
}

//fuction for delete at end
int deleteAtEnd()
{
	struct node *temp,*prev;
	if (head == NULL) 
	{
        printf("No element present in the list\n");
        return 0;
    }
	temp=head;
	//if we consider having 3 node in list linked to each other then this loop will run untill position 2->next 
	//which will have the location of 3 node and when the loop goes to 3->next it will be null so it will stop
	//in loop prev will tell us the location of 2 node we need it because when we want delete the last node then we have to make last second node's next to null so wee need prev 
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	//if our list have only one node then we will have haed and temp pointing to only node we have to delete it so first we have to make head null so that had is null 
	//and do not have any location store in it 
	if (temp==head)
	{
		head=NULL;
	}
	else
	{
		prev->next=NULL;	
	}
	free(temp);
	count--;
	return 0;
	
}

//function for delete at position
int deleteAtPosition()
{
	int pos,i=1;
	struct node *temp,*newnode;
	if (head == NULL) 
	{
        printf("The list is empty\n");
        return 0;
    }
	
	printf("Enter the position at which you want to delete: ");
	scanf("%d",&pos);
	if (pos<1 || pos>count)
	{
		printf("Invalid Position!.....");
	}
	//if we want to delete the node at pos 3 then we have to have temp at pos pos-1 then we can delete the node at 3 pos 
	temp=head;
	while(i<pos-1)
	{
		if (temp==NULL)
		{
			printf("Invalid position");
			return 0;
		}
		temp=temp->next;
		i++;
	}
	//nw is pointing to the node which we want to delete and temp is pointing to node newnode-1 so the we can insert the node at newnode+1 to the exiting list after we delete 
	// a node at specific pos and we do not want the node after the delete pos do not want to get lost
	newnode=temp->next;
	temp->next=newnode->next;
	free(newnode);
	count--;
	return 0;
	
}



int main()
{   
    int choice,Exit;
    printf("---------------------MENU---------------------\n");
    printf("______________________________________________\n");
    while(1)
    {
        printf("Enter the choice from below:\n1.Create Node\n2.Insert Node\n3.Delete Node\n4.Display List\n5.Exit\n");
        printf("Enter your choice here: ");
        scanf("%d",&choice);
        //creating menu for user
    
        switch (choice)
        {
        case 1:
            createNode();
            break;
        case 2:
            insertNode();
            break;
		case 3:
            deleteNode();
            break;	    
        case 4:
            displayNode();
            break;
        case 5:
        	Exit=1;
            break;
        default:
            printf("Invalid choice!.....");
            break;
        }
        printf("-----------------------------------------\n");
    }
    return 0;
                                                               
}

