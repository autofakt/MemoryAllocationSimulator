#include <stdio.h>
#include <stdlib.h>

// declare structure to store block information (id, starting address, ending address, link to next block)
// declare linked list to connect allocation blocks
// declare global variables

struct node
{
  int id;
  int start;
  int end;
  struct node *link;
} *block_list = NULL;

typedef struct node block_type;

int pm_size;
int hole_algo;
int remaining;
int best_so_far;

/********************************************************************/
void
option1 ()
{


  // prompt for size of physical memory and choice of hole-fitting algorithm (0=first-fit, 1=best-fit), initialize remaining memory 
  printf ("Enter size of physical memory: ");
  scanf ("%d", &pm_size);
  remaining = pm_size;
  best_so_far = pm_size;

  printf ("Enter hole-fitting algorithm (0=first fit, 1=best_fit): ");
  scanf ("%d", &hole_algo);
  return;
}


/********************************************************************/
void
printAllocationTable ()
{
  block_type *next_block = block_list;
  // print table containing block id, starting address, ending address

  printf ("ID\tStart\tEnd\n");
  printf ("----------------\n");

  while (next_block != NULL)
    {
      printf ("%d\t%d\t%d\n", next_block->id, next_block->start,
	      next_block->end);
      next_block = next_block->link;
    }
  return;
}


/********************************************************************/
void
option2 ()
{

  int block_id, block_size;
  block_type *new_block, *current_block, *best_block;
  int hole_start, hole_end;
  int best_start, best_end;
  int large_enough_hole = 0;

  printf ("Enter block id: ");
  scanf ("%d", &block_id);
  printf ("Enter block size: ");
  scanf ("%d", &block_size);

  if (block_size > remaining)
    {
      printf ("Cannot fit the block - not enough memory!");
      return;
    }


  new_block = (block_type *) malloc (sizeof (block_type));
  new_block->id = block_id;

  if (block_list == NULL)
    {
      new_block->start = 0;
      new_block->end = block_size;
      new_block->link = NULL;
      block_list = new_block;

      best_so_far -= block_size;	
      remaining -= block_size;	
      printAllocationTable ();
      return;
    }
  // else traverse list until either appropriate hole is found or the end of the list is reached
  current_block = block_list;

  while (current_block != NULL)
    {

      if (block_id == current_block->id)
	{
	  printf ("Duplicate id\n");
	  return;
	}

      hole_start = current_block->end;

      if (current_block->link != NULL)
	{
	  hole_end = current_block->link->start;
	}
      else
	{
	  hole_end = pm_size;
	}

      //first fit
      if (block_size <= (hole_end - hole_start))
	{
	  large_enough_hole = 1;
	  if (hole_algo == 0)
	    {
	      new_block->start = hole_start;
	      new_block->end = hole_start + block_size;
	      remaining -= block_size;

	      new_block->link = current_block->link;
	      current_block->link = new_block;

	      printAllocationTable ();
	      return;
	    }

	  // best fit
	  else
	    {
	      printf ("best so far: %d", best_so_far);
	      if ((hole_end - hole_start) <= best_so_far)
		{	
		  best_so_far = hole_end - hole_start;
		  best_start = hole_start;
		  best_end = hole_end;
		  best_block = current_block;
		}		//if best so far
	    }			//else best fit
	}			//if block fits
      current_block = current_block->link;
    }				//while        

  if (large_enough_hole == 0)
    {
      printf ("No hole large enough");
      return;
    }

  new_block->start = best_start;
  new_block->end = best_start + block_size;
  new_block->link = best_block->link;
  best_block->link = new_block;

  remaining -= block_size;
  printAllocationTable ();
  return;
}

/********************************************************************/
void
option3 ()
{

  block_type *current_block = block_list;
  block_type *prev_block;
  int block_id;
  current_block = block_list;

  if (current_block == NULL)
    {
      printf ("There are no blocks");
      return;
    }

  printf ("Enter block id: ");
  scanf ("%d", &block_id);
  // until block id is found or end of linked list is reached
  // traverse list
  while ((current_block != NULL) && (block_id != current_block->id))
    {

      prev_block = current_block;
      current_block = current_block->link;
    }
  // if end of linked list reached, print block id not found
  if (current_block == NULL)
    {
      printf ("\nCould not find block ID\n");
    }
  else
    {
      prev_block->link = current_block->link;
      remaining += current_block->end - current_block->start;
      best_so_far += remaining;
      free (current_block);
    }
  // else remove block and deallocate memory
  printAllocationTable ();
  return;
}


/********************************************************************/
void
option4 ()
{
  block_type *current_block;
  int current_size;
  int prev_end = 0;

  current_block = block_list;
  // until end of list is reached
  while (current_block != NULL)
    {
      current_size = current_block->end - current_block->start;	
      current_block->start = prev_end;
      current_block->end = current_block->start + current_size;
      prev_end = current_block->end;
      current_block = current_block->link;
    }				//while
  
  printAllocationTable ();
  return;
}


/********************************************************************/
void
option5 (block_type * node)
{

  if (node == NULL)
    {
      return;
    }
  else
    {
      option5 (node->link);
      free (node);
    }
  return;
}


/***************************************************************/
int
main ()
{
  int userSelection;
  do
    {
      printf ("\n Memory Allocation Strategies\n");
      printf ("--------------------------------\n");
      printf ("1) Enter parameters\n");
      printf ("2) Allocate memory for block\n");
      printf ("3) Deallocate memory for block\n");
      printf ("4) Defragment memory\n");
      printf ("5) Quit program\n");

      printf ("\nEnter Selection: ");
      scanf ("%d", &userSelection);
      switch (userSelection)
	{
	case 1:
	  option1 ();
	  break;
	case 2:
	  option2 ();
	  break;
	case 3:
	  option3 ();
	  break;
	case 4:
	  option4 ();
	  break;
	}

    }
  while (userSelection != 5);
  option5 (block_list);
  printf ("BYE BYE");
  return 0;
}
