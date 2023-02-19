#include <stdio.h>
#include <stdlib.h>

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
         printf("NULL");
    }
}

void insert ()
{
    int num;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
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
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;

            temp->next=ptr;
        }
    }
}

void removeDuplicates(struct node* head)
{
    struct node *ptr1, *ptr2, *dup;
    ptr1 = head;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;

        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL) {
            /* If duplicate then delete it */
            if (ptr1->val == ptr2->next->val) {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
                dup=NULL;
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}


    void main ()
    {
        int i,n;
         printf("\nEnter the number of elements: ");
         scanf("%d",&n);
         printf("\nEnter %d value : ",n);
         for(i=0;i<n;i++){
            insert();
         }
         show();
         removeDuplicates(head);
         printf("\n\nRemoving duplicate : ");
         show();

    }
