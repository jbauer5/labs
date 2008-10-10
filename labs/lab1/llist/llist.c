
#include <stdlib.h>
#include <stdio.h>

#define EMPTY_LIST NULL

typedef struct node {
  int data;
  struct node *next;
} llnode, *llnodep;


int length (llnodep n) {
  int count = 0;

  for (; n != EMPTY_LIST; n = n->next, count++);
  return count;
}

void push (llnodep *head, int data) {
  llnodep n = (llnodep) malloc(sizeof(llnode));
  n->data = data;
  n->next = *head;
  *head = n;
}

void print_list (llnodep node) {
  printf("{ ");
  while (node != EMPTY_LIST) {
    printf("%d", node->data);
    node = node->next;
    if (node != EMPTY_LIST)
      printf(", ");
  }
  printf(" }\n");
}

/******************************************************************************
 * You should be adding code to the functions below to implement the various  *
 * described linked list functions in C.  Take care not to introduce any      *
 * memory leaks in your implementation, and test them carefully when done.    *
 *****************************************************************************/

/* Create a node with the new data, and append it to the end of the list */
void append (llnodep *head, int data) {
	llnodep nn = (llnodep) malloc(sizeof(llnode));
	  nn->data = data;
	  nn->next = 0;

	llnodep tep = *head;
	int len = length(tep);
	int ii = 0;
	for(ii = 0;  ii < (len-1); ii++){
		tep = tep->next;
	}
	if (length(*head)==0){
		*head = nn;
	}
	else{
		tep -> next = nn;
	}

}

/* Returns a count of the number of times the data appears in the list */
int count_of (llnodep head, int data) {
	int count1 = 0;
	llnodep tep = head;
	int len = length(tep);
	int ii = 0;

	for(ii = 0;  ii < (len); ii++){
		if (tep->data == data){
				count1++;
		}
		tep = tep->next;
		}
	  return count1;
}

/* Deallocates all the memory used by the given list, and sets its head to
 * NULL */
void freelist (llnodep *head) {
 llnodep kill = *head;
 llnodep aim = *head;
 int ii = 0;
 int len = length(*head);
 for(ii = 0; ii < len; ii++){
	 aim = aim->next;
	 free(kill);
	 kill = aim;
 }
 *head = 0;
}

/* The complementary function to push --- remove the head node of the list
 * and return its data */
int pop (llnodep *head) {
	int dahta = 0;
	llnodep newhead = *head;
	dahta = newhead->data;
	if(length(*head) > 1){
		newhead= newhead->next;
		free(head);
		*head = newhead;
	}
	else{
		free(head);
		*head = 0;
	}
	return dahta;
}

/* Reverse the list by rearranging next pointers and moving the head
 * pointer (your solution should be iterative) */
void reverse (llnodep *head) {
	llnodep nList = 0;
	int datam = 0;
	int ii = 0;
	int len = length(*head);
	for(ii = 0; ii < len; ii++){
		datam = pop(head);
		append(&nList, datam);
	}
	*head = nList;
}

/* Sorts the given list in increasing order (the easier route to doing
 * this does not involve modifying any pointers) */
void sort (llnodep *head) {
llnodep *temp;
temp = head;

	llnodep T1 = *head;
	llnodep T2 = *head;
	int datam = 0;
	int ii = 0;
	int i2 = 0;
	int len = length(*head);
	for(i2 = 0; i2 < (len); i2++){
		T2 = T2->next;
		for(ii = 0; ii < (len-1); ii++){
			if(T1->data > T2->data){
				datam = T1->data;
				T1->data = T2->data;
				T2->data = datam;
			}
			T1 = T1->next;
			T2 = T2->next;
		}
		T1 = *head;
		T2 = *head;
	}
}

/******************************************************************************/

/* Run some simple test cases */
int main () {
  llnodep lstA = EMPTY_LIST,
          lstB = EMPTY_LIST;

  // Build a simple list with push
  push(&lstA, 2); push(&lstA, 3); push(&lstA, 1); push(&lstA, 5);

  // Check out print_list
  print_list(lstA);
  print_list(lstB);

  // Check the length implementation
  printf("Length: %d\n", length(lstA));
  printf("Length: %d\n", length(lstB));

  // Try adding to and building a list with append
  append(&lstA, 9); append(&lstA, 3);
  append(&lstB, 20); append(&lstB, 30); append(&lstB, 40); append(&lstB, 50);
  print_list(lstA);
  print_list(lstB);

  // Check count_of
  printf("Count of 3: %d\n", count_of(lstA, 3));
  printf("Count of 0: %d\n", count_of(lstA, 0));
  printf("Count of 20: %d\n", count_of(lstB, 20));
  printf("Count of 50: %d\n", count_of(lstB, 50));

  // Try freeing up a list
  freelist(&lstA);
  printf("Length: %d\n", length(lstA));

  // Try popping off a few values
  printf("Popped: %d\n", pop(&lstB));
  printf("Popped: %d\n", pop(&lstB));
  printf("Popped: %d\n", pop(&lstB));

  // Check out reverse
  push(&lstA, -4); push(&lstA, 8); push(&lstA, 1); push(&lstA, 9);
  reverse(&lstA);
  print_list(lstA);

  // And finally, sort
  sort(&lstA);
  sort(&lstB);
  print_list(lstA);
  print_list(lstB);

  return 0;
}
