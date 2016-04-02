/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

struct node * getLength_make_sll(struct node *head, int *cnt){
	if (head == NULL)
		return NULL;
	if (head->next == head){
		*cnt = 1;
		return head;
	}

	struct node *cur = NULL;
	cur = head->next;
	*cnt = 2;
	while (cur->next != head){
		cur = cur->next;
		*cnt = *cnt + 1;
	}
	cur->next = NULL;
	return head;
}

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL)
		return(head2);
	else if (head2 == NULL)
		return(head1);

	struct node *result = NULL;

	if (head1->data <= head2->data){
		result = head1;
		result->next = merge2LinkedLists(head1->next, head2);
	}
	else{
		result = head2;
		result->next = merge2LinkedLists(head1, head2->next);
	}

	return result;
}

int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	if (*head1 == NULL && *head2 == NULL)
		return -1;
	
	int head1len = 0, head2len = 0;
	
	*head1 = merge2LinkedLists(getLength_make_sll(*head1, &head1len), getLength_make_sll(*head2, &head2len));
	
	struct node *cur = NULL;
	cur = *head1;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = *head1;

	return head1len + head2len;
}