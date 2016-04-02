/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

void convertdate(struct node *date, int *d, int *m, int *y){
	struct node *cur = date;
	*d = (cur->data * 10) + cur->next->data;
	cur = cur->next->next;
	*m = (cur->data * 10) + cur->next->data;
	cur = cur->next->next;
	*y = (cur->data * 1000) + (cur->next->data * 100) + (cur->next->next->data * 10) + cur->next->next->next->data;

}

int get_length(struct node * head){
	int cnt = 0;
	while (head){
		head = head->next;
		cnt++;
	}
	return cnt;
}

int get_difference(int d1, int d2, int m1, int m2, int y1, int y2){
	int cnt = 0, i;
	int daysinmon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (i = y1 + 1; i < y2; i++){
		if (i % 4 == 0)
			cnt += 366;
		else
			cnt += 365;
	}

}

int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL || get_length(date1head) > 8 || get_length(date2head) > 8)
		return -1;

	int d1, d2, m1, m2, y1, y2;
	convertdate(date1head, &d1, &m1, &y1);
	convertdate(date2head, &d2, &m2, &y2);
	if (y1 < y2)
		return get_difference(d1, d2, m1, m2, y1, y2);
	else
		return get_difference(d2, d1, m2, m1, y2, y1);
	
}