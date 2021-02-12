#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next; 
};
struct node *head;
void insertbegin();
void insertrandom();
void insertlast();
void deletebegin();
void deleterandom();
void deletelast();
void display();
void search();
int main()
{
	int choice=0;
	while(choice!=9)
	{
		cout<<"\n******************Main Menu****************";
		cout<<"\n 1. Insert at start \n 2. Insert at last \n 3. Insert at any position ";
		cout<<"\n 4. Delete at start \n 5. Delete at last \n 6. Delete at any position ";
		cout<<"\n 7. Display \n 8. Search element \n 9. Exit ";
		cout<<"\nEnter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				insertbegin();
				break;
			case 2:
				insertlast();
				break;
			case 3:
				insertrandom();
				break;
			case 4:
				deletebegin();
				break;
			case 5:
				deletelast();
				break;
			case 6:
				deleterandom();
				break;
			case 7:
				display();
				break;
			case 8:
				search();
				break;
			case 9:
				choice=9;
				break;
			default :
				cout<<"\nEnter a Valid Choice.";
		}
	}
	return 0;
}
void insertbegin()
{
	struct node *ptr;
	int item;
	ptr=(struct node *)malloc(sizeof(struct node *));
	cout<<"\nEnter data to insert : ";
	cin>>item;
	ptr->data=item;
	ptr->next=head;
	head=ptr;
	cout<<"\nNode Inserted.";
}

void insertlast()
{
	struct node *ptr, *temp;
	int item;
	ptr=(struct node *)malloc(sizeof(struct node *));
	cout<<"\nEnter data to insert : ";
	cin>>item;
	ptr->data=item;
	if(head==NULL)
	{
		ptr->next=head;
		head=ptr;
		cout<<"\nNode Inserted.";
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->next=NULL;
		cout<<"\nNode Inserted.";
	}
}
void insertrandom()
{
	struct node *ptr, *temp;
	int item,loc,i;
	ptr=(struct node *)malloc(sizeof(struct node *));
	cout<<"\nEnter the location of data you want to insert : ";
	cin>>loc;
	cout<<"\nEnter Data to insert : ";
	cin>>item;
	ptr->data=item;
	temp=head;
	for(i=0;i<loc;i++)
	{
		temp=temp->next;
		if(temp=NULL)
		{
			cout<<"\nNode can't be inserted.";
			return;
		}
	}
	ptr->next=temp->next;
	temp->next=ptr;
	cout<<"\nNode Inserted.";
}
void deletebegin()
{
	struct node *ptr;
	if(head==NULL)
	{
		cout<<"\nNo data present to delete.";
	}
	else
	{
		ptr=head;
		head=ptr->next;
		free(ptr);
		cout<<"\nNode Deleted.";
	}
	
}
void deletelast()
{
	struct node *ptr, *temp;
	if(head==NULL)
	{
		cout<<"\nEmpty list , Deletion can't be performed.";
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=temp->next;
		free(temp);
		cout<<"\nNode Deleted.";
	}
}

void deleterandom()
{
	struct node *ptr, *temp;
	int i,loc;
	cout<<"\nEnter the location from where you want to delete : ";
	cin>>loc;
	temp=head;
	for(i=0;i<loc;i++)
	{
		ptr=temp;
		temp=temp->next;
		if(temp=NULL)
		{
			cout<<"\nNode can't be deleted.";
			return;
		}
	}
	ptr->next=temp->next;
	free(ptr);
	cout<<"\nNode Deleted.";
}
void display()
{
	struct node *ptr;
	if(head==NULL)
	{
		cout<<"\nEmpty list.";
	}
	else
	{
	cout<<"\nElements of Linked list : ";
	ptr=head;
	while(ptr->next!=NULL)
	{
		cout<<ptr->data<<"\n";
		ptr=ptr->next;
	}
	cout<<ptr->data;
    }
}
void search()
{
	struct node *ptr;
	int i,x=0,y=0,item;
	if(head==NULL)
	{
		cout<<"\nEmpty list.";
	}
	else
	{
	cout<<"\nEnter element you want to search : ";
	cin>>item;
	ptr=head;
    while(ptr->next!=NULL)
    {
    	ptr=ptr->next;
    	y++;
    	if(ptr->data==item)
    	{
    		cout<<"\nElement found in the list at "<<y<<" index.";
    		return;
		}
	}
	cout<<"\nElement is not present in the list.";
	}
}
