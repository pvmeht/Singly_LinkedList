#include <stdio.h>
#include <stdlib.h>

struct singly
{
  int d;
  struct singly *next;
};

struct singly *append (struct singly *st, int n)
{
  struct singly *newnode, *temp;
  newnode = (struct singly *) malloc (sizeof (struct singly));
  newnode->d = n;
  newnode->next = NULL;
  if (st == NULL)
    st = newnode;
  else
    {
      temp = st;
      while (temp->next != NULL)
	temp = temp->next;
      temp->next = newnode;
    }
  return (st);
}

void display (struct singly *start)
{
  struct singly *temp;
  temp = start;
  printf ("Linked list data :- ");
  while (temp != NULL)
    {
      printf ("%d  ", temp->d);
      temp = temp->next;
    }
}

void search (struct singly *start, int x)
{
  struct singly *temp;
  int c = 1;
  temp = start;
  while (temp != NULL)
    {
      if (temp->d == x)
	{
	  printf ("Element is found at position %d \n", c);
	  break;
	}
      else
	temp = temp->next;
      c++;
    }
  if (temp == NULL)
    {
      printf ("Element Not Found");
    }
}



struct singly *insert(struct singly *start, int n, int p)
{
  struct singly *newnode, *temp;
  int c = 0;
  temp = start;			//count of nodes
  while (temp != NULL)
    {
      c++;
      temp = temp->next;
    }
  printf ("No. of Nodes :- %d", c);
  newnode = (struct singly *) malloc (sizeof (struct singly));
  newnode->d = n;
  newnode->next = NULL;
  if (p == 1)			//at Beginning
    {
      newnode->next = start;
      start = newnode;
    }
  else if (p > c)		// at end
    {
      temp = start;
      while (temp->next != NULL)
	temp = temp->next;
      temp->next = newnode;
    }
  else
    {
        c=1;
        temp=start;
        while(c<(p-1))
        {
            temp=temp->next;
            c++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
  return (start);
}

struct singly *delete(struct singly*start, int p)
{
    struct singly *temp;
    int c=0;
    temp=start;
    while(temp!=NULL) // No. of nodes in linked list
    {
        c++;
        temp=temp->next;
    }
    if(p==1) // delete 1st node
    {
        temp=start->next;
        free(start);
        start=temp;
    }
    else if(p==c) // delete last node
    {
        temp=start;
        while(temp->next->next!=NULL) //travel linked list to second last node
            temp=temp->next;
        
        free(temp->next);
        temp->next=NULL;
    }
    else if(p>c)
        printf("\n Invalid Position\n");
    return(start);
}