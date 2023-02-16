#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *link;
};

void count_node(struct node *head){
    int c=0;
    if(head==NULL)
        printf("Empty\n");
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        c++;
        ptr=ptr->link;
    }
    printf(" %d\n",c);
}


void print(struct node *head){
    if(head==NULL)
        printf("Empty\n");

    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

void search(struct node *head,int data){
    int c=0,b=0;
    if(head==NULL)
        printf("Empty\n");

    struct node *ptr=head;
    while(ptr!=NULL){
            if(ptr->data==data){
                    printf("\n item Found");
                    printf("\n the position of %d is in %d",data,c+1);
                    b++;
                    break;
            }
        else
        ptr=ptr->link;
        c++;
    }
    if(b==0)
    printf("\n %d item not found",data);
}

void add_at_end(struct node *head,int num){
    struct node *ptr,*temp;
    ptr=head;

    temp= (struct node*) malloc(sizeof(struct node));
    temp-> data = num;
    temp-> link= NULL;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
}

struct node * add_in_end_woT(struct node *ptr,int num){
    struct node *temp;
    temp= (struct node*) malloc(sizeof(struct node));
    temp-> data = num;
    temp-> link= NULL;
    ptr->link= temp;
    return temp;


}

struct node * add_in_beg_woT(struct node *head,int num){
    struct node *temp= (struct node*) malloc(sizeof(struct node));
    temp-> data = num;
    //temp-> link= NULL;

    temp->link= head;
    head=temp;
    return head;
}
void add_at_pos(struct node *head,int num,int pos){

    struct node *ptr = head;
    struct node *temp= (struct node*) malloc(sizeof(struct node));
    temp-> data = num;
    temp-> link= NULL;
    pos--;
    while(pos!=1){
        ptr = ptr->link;
        pos--;
    }
    temp->link=ptr->link;
    ptr->link=temp;
}
struct node * del_at_beg(struct node *head){
    if(head==NULL)
        printf("Empty\n");

    struct node *temp=head;
    head=head->link;
    free(temp);
return head;
};

struct node* del_at_last(struct node *head){
    if(head==NULL)
        printf("Empty\n");

    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *temp=head;
        struct node *temp2=head;
         while(temp->link!=NULL){
          temp2=temp;
          temp=temp->link;
    }
    temp2->link=NULL;
    free(temp);
    temp=NULL;


    }
    return head;
};




int main(){
    //int n,i;
    //printf("Enter number of elements");
    //scanf("%d",&n);

    struct node *head = (struct node*) malloc(sizeof(struct node));
    head-> data =45;
    head-> link= NULL;

    struct node *current = (struct node*) malloc(sizeof(struct node));
    current-> data =5;
    current-> link= NULL;
    head-> link= current;

    current = (struct node*) malloc(sizeof(struct node));
    current-> data =7;
    current-> link= NULL;

    head-> link-> link= current;


    struct node *ptr=current;
    ptr = add_in_end_woT(ptr,33);

    head = add_in_beg_woT(head,100);

    count_node(head);
    print(head);

    add_at_pos(head,99,3);
    add_at_end(head,69);
    add_at_end(head,9);

    head = del_at_beg(head);
    head = del_at_last(head);


    print(head);
    search(head,10);


    return 0;




}
