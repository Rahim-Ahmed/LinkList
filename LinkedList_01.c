#include <stdio.h>
#include <stdlib.h>
int counter;

struct node
{
int val;
struct node *next;
};struct node *head;

void show()
{
    int i;
    struct node *ptr=head;
    if(ptr == NULL)
    {
        printf("\nLinked list is empty.");
    }
    else
    {
        printf("\nElements are: \n ");
        while(ptr!=NULL)
        {
            printf("%d---->",ptr->val);
            ptr = ptr->next;
        }
         printf("NULL\n Number of elements: %d.\n",counter);
    }
}

void insert ()
{
    int num;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    printf("\nEnter the value: ");
    scanf("%d",&num);
     ptr->val = num;
     ptr -> next = NULL;
    if(ptr == NULL)
    {
        printf("\n Fail to allocate memory !!");
    }
    else
    {
        if(head==NULL)
        {
            head=ptr;
            printf("\n Inserted at head. ");
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;

            temp->next=ptr;
            printf("\n Item inserted successfully. ");

            //ptr->val = num;
            //ptr->next = head;
           // head=ptr;
        }
        counter++;
    }
}
struct node * add_in_beg(struct node *head,int num){
    struct node *temp= (struct node*) malloc(sizeof(struct node));
    temp->val = num;
    temp->next= head;
    head=temp;
    printf("\nItem inserted at head. ");
           counter++;
    return head;
}

void add_at_pos(struct node *head,int num,int pos){
    struct node *ptr = head;
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->val = num;
    temp->next= NULL;
    pos--;
    while(pos!=1){
        ptr = ptr->next;
        pos--;
    }

    temp->next=ptr->next;
    ptr->next=temp;
    counter++;
    printf("\nItem inserted successfully. ");
}

struct node* del_at_last(struct node *head){
    if(head==NULL)
        printf("Empty\n");

    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *temp=head;
        struct node *temp2=head;
         while(temp->next!=NULL){
          temp2=temp;
          temp=temp->next;
    }
    temp2->next=NULL;
    free(temp);
    temp=NULL;
printf("Successfully deleted the last Node.");
    }
    counter--;
    return head;
};

void deleteFirst() {

    if(head==NULL)
        printf("Empty\n");
    else {
   struct node *tempLink = head;
   head = head->next;
printf("Successfully deleted a Node from beginning.");
counter--;
    }
}


void del_any_pos(struct node **head,int pos){
    struct node *current =head;
    struct node *previous =head;
    if(*head==NULL)
        printf("Empty\n");
    else if (pos==1){
        *head = current->next;
        free(current);
        current=NULL;
    }
    else {
        while(pos!=1){
            previous=current;
            current= current->next;
            pos--;
        }
        previous->next=current->next;
        free(current);
        current=NULL;
    }
    counter--;
    printf("\nItem inserted successfully. ");
}

void reverseList()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; // Make first node as last node

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; // Make last node as head

        printf("Successfully reversed the list\n");
    }
}


void main ()
{
    int choice=0;

    printf("\n-------------------MENU---------------------------\n");
    while(choice != 9)
    {
        printf("\n\nChose one from the below options...\n");
        printf("\n1.Insert new node.\n2.Insert node at beginning. \n3.Insert node at position. \n4.Delete Node from last position\n5.Delete Node from beginning.\n6.Delete Node from any position. \n7.Reverse Linked list \n8.show elements. \n9.exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                insert();
                break;
            }
            case 2:
            {
                int num;
                printf("\nEnter the value: ");
                scanf("%d",&num);
                head = add_in_beg(head,num);
                break;
            }
            case 3:
            {
              int num,pos;
                printf("\nEnter the value: ");
                scanf("%d",&num);
                printf("\nEnter the Position: ");
                scanf("%d",&pos);
                while(pos>counter){
                printf("\nEnter a valid Position: ");
                scanf("%d",&pos);
                }
                if(pos==1)
                    head = add_in_beg(head,num);
                else
                add_at_pos(head,num,pos);

                break;
            }
            case 4:
            {
                head=del_at_last(head);
                break;
            }

            case 5:
            {

               deleteFirst();
                break;
            }

            case 6:
            {
                int pos;
                printf("\nEnter the Position: ");
                scanf("%d",&pos);
                while(pos>counter){
                printf("\nEnter a valid Position: ");
                scanf("%d",&pos);
                }
                del_any_pos(head,pos);
                break;
            }
            case 7:
            {
                reverseList();
                break;
            }
            case 8:
            {
                show();
                break;
            }

            case 9:
            {
                printf("Exiting....");
                break;
            }
            default:
            {
                printf("Please Enter valid choice ");
            }
    };
}
}
