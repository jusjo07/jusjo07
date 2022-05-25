#include<stdio.h>
#include<stdlib.h>
void main()
{
	struct node
	{
		int data;
		struct node *next;
	};
	struct node*head=NULL,*pos=NULL,*tail=NULL;
	int ch,entry,count,flag,n;
	while(1)
	{
		printf("\n 1.insert \n 2.display \n 3.search\n 4.delete\n 5.exit\n");
		printf("\n enter your choice\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
					printf("\n enter the data\t");
					scanf("%d",&entry);
					if (head==NULL)
					{
						head=(struct node*)malloc(sizeof(struct node));
						head->data=entry;
						pos=head;
						tail=head;
					}
					else
					{
						tail->next=(struct node*)malloc(sizeof (struct node));
						tail=tail->next;
						tail->data=entry;
					}break;
			}
			case 2:
			{
				pos=head;
				printf("\n elements are:");
				while(pos!=NULL)
				{
					printf("%d",pos->data);
					printf("\n");
					pos=pos->next;
				}
				break;
			}
			case 3:
			{
				pos=head;
				printf("\n the element to be searched for");
				scanf("%d",&n);
				while(pos!=NULL)
				{
					if(pos->data==n)
					{
					flag=1;
					break;
					}
					else
					{
					flag=0;
					}
					pos=pos->next;
				}
				if(flag==1)
					printf("element found");
				else
				{
					printf("element not found");
				}
				break;
			}
			case 4:
			{
				struct node *temp=head;
				printf("\n enter position of data",temp->data);
				scanf("%d",&entry);
				if (entry==0)
				{
					head=head->next;
					temp->next=NULL;
					free(temp);
				}
				else
				{
				for(int i=0; i<entry-1;i++)
					{
						temp=temp->next;
					}
					struct node *del=temp->next;
					temp->next=temp->next->next;
					del->next=NULL;
					printf("enter element to be deleted is %d",del ->data);
					printf("\n");
					free(del);
				}
				break;
			}
			case 5:
			{
			printf("\n goodbye");
			exit(0);
			}
			default:
			{
				printf("invalid choice");
				break;
			}
		}
	}
}
