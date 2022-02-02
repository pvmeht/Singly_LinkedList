#include <stdio.h>
#include "singly.h"


int main ()
{
  int n, ch, c, p, x;
  struct singly *start = NULL;
  while (1)
    {
      printf ("\n1-Append\n");
      printf ("2-Display\n");
      printf ("3-Insert\n");
      printf ("4-Search\n");
      printf ("5-Delete\n");
      printf ("6-Exit\n");

      printf ("Enter choice\n");
      scanf ("%d", &ch);
      switch (ch)
	{
	case 1:
	  printf ("Enter Data\n");
	  scanf ("%d", &n);
	  start = append (start, n);
	  break;
	case 2:
	  display (start);
	  break;
	case 3:
	  printf ("Enter position: ");
	  scanf ("%d", &p);
	  printf ("Enter Data : ");
	  scanf ("%d", &n);
	  start = insert(start, n, p);
	  break;
	case 4:
	  printf ("Enter Search Element:-  ");
	  scanf ("%d", &x);
	  search(start, x);
      break;
	case 5:
	    printf ("Enter Delete Element position:-  ");
	    scanf ("%d", &p);
	    start = delete (start, p);
        break;
	    
	case 6:
	    exit(0);
	  

	}
    }
}



