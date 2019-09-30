#include<stdio.h>
#include<stdlib.h>
struct node
{
  char usn[2],name[20],branch[5],phno[12];
  int sem;
  struct node*link;
};
typedef struct node*NODE;
NODE temp,FIRST=NULL;
NODE getnode()
{
  NODE x;
  x=(NODE)malloc(sizeof(struct node));
  return x;
}
void read()
{
  temp=getnode();
  temp->link=NULL;
  printf("Enter the usn:");
  scanf("%s",temp->usn);
  printf("Enter name:");
  scanf("%s",temp->name);
  printf("Enter branch:");
  scanf("%s",temp->branch);
  printf("Enter phno:");
  scanf("%s",temp->phno);
  printf("Enter sem:");
  scanf("%d",&temp->sem);
}
void create_SLL()
{
  int n,i=1;
  printf("Enter the number of students:\n");
  scanf("%d",&n);
  while(i<=n)
  {
     printf("\nEnter the details of the %d students\n",i++);
     read();
     if(FIRST==NULL)
        FIRST=temp;
     else
     {
        temp->link=FIRST;
        FIRST=temp;
     }
   }
}
void display_count(NODE FIRST)
{
   temp=FIRST;
   int count=1;
   printf("Students details:\n");
   if(FIRST==NULL)
       printf("Student detail is null and count is %d\n",count-1);
   else
   {
       while(temp->link!=NULL)
       {
          count++;
          printf("%s\t%s\t%s\t%s\t%d\n",temp->usn,temp->name,temp->branch,temp->phno,temp->sem);
          temp=temp->link;
       }
       printf("%s\t%s\t%s\t%s\t%d",temp->usn,temp->name,temp->branch,temp->phno,temp->sem);
       printf("\nStudent count:%d\n",count);
    }
    return;
}
void insertionfront()
{
   printf("Enter the details of the students\n");
   read();
   if(FIRST==NULL)
      FIRST=temp;
   else
   {
      temp->link=FIRST;
      FIRST=temp;
   }
}
NODE insertionend(NODE FIRST)
{
   NODE last=FIRST;
   printf("Enter the details of the new student\n");
   read();
   if(last!=NULL)
   {
      while(last->link!=NULL)
           last=last->link;
      last->link=temp;
    }
    else 
       FIRST=temp;
    return FIRST;
}
void deletionfront()
{
    temp=FIRST;
    if(FIRST==NULL)
        printf("List is empty\n");
    else
    {
        printf("Delted element is %s\n",temp->usn);
        FIRST=temp->link;
        free(FIRST);
     }
     return;
}
void deletionend()
{
    NODE pre=NULL;
    temp=FIRST;
    if(FIRST==NULL)
       printf("List empty\n");
    else if(temp->link==NULL)
    {
       printf("Deleted element is %s\n",temp->usn);
       free(temp);
       FIRST=NULL;
    }
    else
    {
      while(temp->link!=NULL)
      {
        pre=temp;
        temp=temp->link;
      }
      pre->link=NULL;
      printf("Deleted element is %s\n",temp->usn);
      free(temp);
    }
    return;
}         
    
void main()
{
  int choice;
  while(1)
  {
     printf("-------MENU-------\n");
     printf("1.Create a SLL of N students\n");
     printf("2.Display SLL\n");
     printf("3.Insertion at front\n");
     printf("4.Insertion at end\n");
     printf("5.Deletion at front\n");
     printf("6.Deletion at end\n");
     printf("7.End\n");
     printf("Enter your choice:");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:create_SLL();
               break;
        case 2:display_count(FIRST);
               break;
        case 3:insertionfront();
               break;
        case 4:FIRST=insertionend(FIRST);
               break;
        case 5:deletionfront();
               break;
        case 6:deletionend();
               break;
        case 7:return;
        default:printf("\nInvalid choice\n");
      }
   }
}
     
     
