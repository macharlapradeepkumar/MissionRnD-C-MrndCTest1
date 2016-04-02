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
typedef struct node *lptr;
int insertend(lptr p);
int insert1(lptr p);
int corr(int oneday, int onemon, int oneyar);
int between_days(struct node *date1head, struct node *date2head){
	lptr p = date1head, q = date2head;
	lptr e, f;
	e = p;
	f = q;
	if (p == NULL || q == NULL) return -1;

	int l = insertend(p);
	int m = insertend(q );
	p = e;
	q = f;
	int t = insert1(p);
	int g = insert1(q);

}
int insert1(lptr p){
	int l = 0,n=0;
	while (l != 2)
	{
		int r = p->data;
		n = n * 10 + r;
		p = p->next;
		l++;
	}
	return  n;

}
int insertend(lptr p)
{
	int l = 0,n=0,m=0,k=0;
	while(l != 2)
	{
	int r= p->data;
		n = n * 10 + r;
		p = p->next;
		l++;
	}
	while (l >= 2 && l <= 3)
	{
		int b = p->data;
		m = m * 10 + b;
		p = p->next;
		l++;
	}
	while (l >= 4 && l <= 7)
	{
		int c = p->data;
		k = k * 10 + c;
		p=p->next;
		l++;
	}
	int a = corr(n, m, k);
	return a;
}
int corr(int oneday, int onemon, int oneyar)
{
	switch (onemon)
	{
	case 01:if (oneday <= 31 || oneday > 0)
		return 31;
			
		break;

	case 02:if (oneyar % 4 == 0 && (oneyar % 100 != 0 || oneyar % 400 == 0))
	{
		if (oneday <= 29 || oneday >0)
			return 29;
	}

			else
			{
				if (oneday > 28 || oneday <= 0) return 28;
			}

			break;
	case 03: if (oneday <= 31 || oneday > 0)  return 31;
			
		break;
	case 04: if (oneday <= 30 || oneday > 0)  return 30;
			 
		break;
	case 05: if (oneday <=31 || oneday > 0)  return 31;
		break;
	case 06: if (oneday <= 30 || oneday > 0)  return 30;
			
		break;
	case 07: if (oneday <= 31 || oneday > 0)  return 31;
			
		break;
	case 8:
		if (oneday <= 31 || oneday > 0)  return 31;

		break;
	case 9: if (oneday <= 30 || oneday > 0)  return 30;
		break;
	case 10: if (oneday <=31 || oneday > 0)  return 31;
			 
		break;
	case 11: if (oneday <= 30 || oneday > 0)  return 30;
			 
		break;
	case 12: if (oneday <= 31 || oneday > 0)  return 31;
			 
		break;


	}
}