// labovi_ais.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
typedef struct _person {
	char name[32], lastname[32];
	int yearOfBirth;
	struct _person* next;
}p;
typedef p* position;
p* pushFront(p*);
void printing(position);//racunaj ubuduce uvik int ne void!
void deleting(position);
position pushBack(p*);
position searchByLastName(char[], p*);
position deleteSelected(char[], p*);


position addAfterSelected(char[], p*);
position addBeforeSelected(char[], p*);

position readFromFile(char[], position);
position sortListByLastname(p*);
position findPositionBefore(p*, p*);

position putDataFromListToFile(char[], p*);


typedef struct _polynomials {
	int num, exp;
	struct _polynomials* next;
}poly;
typedef poly* _position;
int findNumOfDataInList(_position);
_position readFrom1stFile(char[], _position);
void printingPolynomials(_position);
_position sortPolynomials(_position);
_position mergeSameExp(_position, _position);
_position  addPolynomials(_position, _position, _position);
void deletingPolynomials(_position);
int isNumThere(int,int,int*);
_position multiplication(_position, _position, _position);


typedef struct _list {
	int num;
	struct _list* next;
}list;
typedef list* l_position;
l_position Union(l_position, l_position, l_position);
l_position read(l_position, char[]);
void printList(l_position);
void deleteList(l_position);
l_position intersection(l_position, l_position, l_position);
int push(int, int);
l_position fillList(l_position, int, int, int);
l_position emptyStack(l_position);
l_position emptyQueue(l_position);

l_position fillCircularStack(l_position, int, int, int);
void printCircular(l_position);
void deleteC(l_position);

typedef struct _listp {
	int num,priority;
	struct _listp* next;
}listp;
typedef listp* position_;
position_ queueP(position_, int, int, int);
position_ sortByPriority(position_);
position_ emptyQueuePriority(position_);
void printing_q(position_);

typedef struct postfix_ {
	int num;
	char oper;
	int isNum;  
	struct postfix_* next;
}post;
typedef post* positionX;
positionX GetDataFromPostfix(positionX, char[]);
void printing_postfix(positionX head);
void delete_postfix(positionX head);
int result(positionX);
l_position putOnStack(l_position head, int value);
l_position deleteFromStack(l_position,char);

int main()
{
	p head;
	head.next = NULL;
	int o;
	printf_s("1 - 2. i 3. vj (bez citanja iz datot. u listu\n2 -citanja iz datot. u listu\n3 - polinomi\n4 - unija i presjek\n5 - simulacija stoga i reda\n6 - cirkularni stog i red s prioritetom\n7 - postfix izraz \t ");
	scanf_s(" %d", &o);
	if (o == 1) {
		//position test = NULL;
		pushFront(&head);
		printf("back insert\n");
		pushBack(&head);
		printing(&head);


		printf("enter lastname you want to find inside a list\n");
		char lstName[32];
		scanf_s(" %31s", lstName, (unsigned)_countof(lstName));
		//lstName[strcspn(lstName, "\r\n")] = '\0';
		searchByLastName(lstName, &head);



		printf("enter first name to delete person from the list\n");
		char name[32];
		scanf_s(" %31s", name, (unsigned)_countof(name));
		deleteSelected(name, &head);
		printf("proof of deletion\n");
		printing(&head);


		printf("enter last name to insert new person after it\n");
		char lName[32];
		scanf_s(" %31s", lName, (unsigned)_countof(lName));

		addAfterSelected(lstName, &head);
		printf("proof of adding new after selected\n");
		printing(&head);


		char lName1[32];///---> radije ovo napravi da ne kupi prijašnji unos!
		printf("enter last name to insert new person before it\n");
		scanf_s(" %31s", lName1, (unsigned)_countof(lName1));
		addBeforeSelected(lName1, &head);
		printf("proof of adding new before selected\n");
		printing(&head);
		sortListByLastname(&head);

		char ime2datot[] = "IzListe.txt";
		printf("insetring data in file\n");
		putDataFromListToFile(ime2datot, &head);

		deleting(&head);
	}
	
	if (o == 2) {
		char imeDat[] = "people.txt";
		readFromFile(imeDat, &head);
		printing(&head);
		printf("sort list by last name");
		sortListByLastname(&head);
		printing(&head);
		deleting(&head);
	}
	/*deleting(&head);
	printf("proof of deletion\n");
	printing(&head);*/
	/*printf("sorting list by lastname");
	sortListByLastname(&head);
	printing(&head);
	deleting(&head);*/

	/*char ime2datot[] = "IzListe.txt";
	printf("upisivanje podataka u datoteku\n");
	putDataFromListToFile(ime2datot, &head);
	deleting(&head);*/
	if (o == 3) {
		poly head;
		head.next = NULL;
		char name[] = "polinomi.txt";
		readFrom1stFile(name, &head);
		printingPolynomials(&head);

		poly head2;
		head2.next = NULL;
		char name2[] = "polinomi2.txt";
		readFrom1stFile(name2, &head2);
		printingPolynomials(&head2);

		
		printf("check if there are numbers with same exponents...\n");
		poly head_merged, head2_merged;
		head_merged.next=NULL;
		head2_merged.next = NULL;
		
		mergeSameExp(&head2,&head2_merged);
		mergeSameExp(&head, &head_merged);
		printf("printing merged polynomials\n");
		printingPolynomials(&head_merged);
		printingPolynomials(&head2_merged);
		printf("sorting polynomials\n");
		sortPolynomials(&head_merged);
		sortPolynomials(&head2_merged);
		printf("adding polynomials\n");
		poly polyAdd;
		polyAdd.next = NULL;

		addPolynomials(&head_merged, &head2_merged, &polyAdd);
		printf("added\n");
		printingPolynomials(&polyAdd);
		poly polyMulti;
		polyMulti.next = NULL;
		printf("multiplicaton\n");
		multiplication(&head_merged, &head2_merged, &polyMulti);
		sortPolynomials(&polyMulti);
		printingPolynomials(&polyMulti);

		deletingPolynomials(&head);
		deletingPolynomials(&head2);
		deletingPolynomials(&head_merged);
		deletingPolynomials(&head2_merged);
		deletingPolynomials(&polyAdd);
		deletingPolynomials(&polyMulti);
		
		
	}
	if (o == 4) {
		printf("izvrsava se\n");
		char n1[] = "L1.txt";
		char n2[] = "L2.txt";
		list L1;
		L1.next = NULL;
		list L2;
		L2.next = NULL;
		read(&L1, n1);
		printList(&L1);

		read(&L2, n2);
		printList(&L2);

		printf("union\n");
		list u;
		u.next = NULL;
		Union(&L1, &L2, &u);
		printList(&u);

		list intr;
		intr.next = NULL;
		printf("intersection\n");
		intersection(&L1, &L2, &intr);
		printList(&intr);

		deleteList(&L1);
		deleteList(&L2);
		deleteList(&u);
		deleteList(&intr);
		printList(&L1);
		printList(&L2);
		printList(&u);
		printList(&intr);
	}
	if (o == 5) {
		srand((unsigned)time(NULL));
		printf("enter length of list\n");
		int d, mi=10, ma=100;
		scanf_s(" %d", &d);
		/*printf("enter min value\n");
		scanf_s(" %d", &mi);
		printf("enter max value\n");
		scanf_s(" %d", &ma);*/

		list l1;
		l1.next =NULL;
		fillList(&l1, d, mi, ma);
		printList(&l1);
		/*int t = generateNum(1, 10);
		printf("%d", t);*/
		
		printf("do you want to empty it as a stack (enter 1) or queue (enter 0)");
		int c;
		scanf_s(" %d", &c);
		if (c == 1) {
			emptyStack(&l1);
			printList(&l1);
			deleteList(&l1);
		}
		if (c == 0) {
			emptyQueue(&l1);
			printList(&l1);
			deleteList(&l1);
		}

	}
	if (o == 6) {
		srand((unsigned)time(NULL));
		printf("enter length of list\n");
		int d, mi = 1, ma = 5;
		scanf_s(" %d", &d);
		list l1;
		l1.next = NULL;
		fillCircularStack(&l1,d, mi, ma);
		printCircular(&l1);
		deleteC(&l1);
		listp l2;
		l2.next = NULL;
		queueP(&l2, d, mi, ma);
		sortByPriority(&l2);
		emptyQueuePriority(&l2);
		printing_q(&l2);
		deleteList(&l1);

	}
	if (o == 7) {
		char nzv[] = "postfix.txt";
		post l1;
		l1.next = NULL;
		GetDataFromPostfix(&l1, nzv);
		printing_postfix(&l1);
		int rez;
		result(&l1);
		delete_postfix(&l1);
	}
	return 0;
}
positionX GetDataFromPostfix(positionX head, char name[]) {
	FILE* fp = NULL;
	char c;
	int x = fopen_s(&fp, name, "r");
	if (x != 0 || fp == NULL) {
		printf("file cant be opened!\n");
		return head;
	}

	while ((c = getc(fp)) != EOF) {

		if (isdigit(c)) {
			positionX pp =(positionX) malloc(sizeof(post));
			if (!pp) {
				printf("error\n");
				fclose(fp);
				return head;
			}

			pp->num = c - '0';
			pp->isNum = 1;
			pp->next = NULL;

			positionX h = head;
			while (h->next)
				h = h->next;
			h->next = pp;
		}

		else if (isspace(c)) {
			continue;
		}

		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			positionX pp =(positionX) malloc(sizeof(post));
			if (!pp) {
				printf("error\n");
				fclose(fp);
				return head;
			}

			pp->oper = c;
			pp->isNum = 0;
			pp->next = NULL;

			positionX h = head;
			while (h->next)
				h = h->next;
			h->next = pp;
		}
	}

	fclose(fp);
	return head;
}
void printing_postfix(positionX head) {
	positionX temp = head->next;
	
	while (temp != NULL) {
		if (temp->isNum == 1) {

			printf("%d ", temp->num);
		}
		else {
			printf("%c ", temp->oper);
		}
		temp = temp->next;
	}
}
void delete_postfix(positionX head) {
	positionX now = head->next;
	positionX temp = head;
	while (now != NULL) {
		temp = now;
		now = now->next;
		free(temp);
	}
	head->next = NULL;
}
int result(positionX head)
{
	positionX h = head;
	l_position stack = NULL;

	while (h != NULL) {
		if (h->isNum)
			stack = putOnStack(stack, h->num);
		else
			stack = deleteFromStack(stack, h->oper);

		h = h->next;
	}

	if (stack!=NULL) {
		printf("Result = %d\n", stack->num);
	}
	return 0;
}

l_position putOnStack(l_position head, int value)
{
	l_position pp = (l_position)malloc(sizeof(list));
	if (pp == NULL) {
		printf("error\n");
		return head;
	}

	pp->num = value;
	pp->next = head;
	return pp;
}

l_position deleteFromStack(l_position head, char o)
{
	if (head==NULL || head->next==NULL) {
		printf("not enough operands\n");
		return head;
	}

	l_position a = head;
	l_position b = head->next;
	int result;

	switch (o) {
	case '+':
		result = b->num + a->num;
		break;
	case '-':
		result = b->num - a->num; 
		break;
	case '*':
		result = b->num * a->num;
		break;
	case '/':
		
		result = b->num / a->num;
		break;
	
	}

	free(a);
	b->num = result;
	return b;
}


int isListEmpty(positionX head) {

	if (head->next == NULL) {
		printf("list is empty\n");
		return -1;
	}
	else {
		return 1;
	}
}

_position mergeSameExp(_position head, _position head_merged) {
	_position head_i;
	_position head_j;
	int sum, brojac = findNumOfDataInList(head);
	head_i = head->next;
	printf("%d br\n", brojac);

	int* niz = (int*)malloc(sizeof(int) * brojac);
	if (niz == NULL) {
		printf("failed allocation\n");
		return head;
	}


	int i = 0;
	while (head_i != NULL) {
		head_j = head_i->next;
		*(niz + i) = head_i->exp;
		sum = head_i->num;
		while (head_j != NULL) {
			if (head_i->exp == head_j->exp) {
				sum += head_j->num;
				head_j = head_j->next;
			}
			else {
				head_j = head_j->next;
			}
		}
		int prov = isNumThere(brojac, head_i->exp, niz);
		if (prov == 0) {
			_position pp = (_position)malloc(sizeof(poly));
			if (pp == NULL) {
				printf("error\nfailed alocation\n");
				return head;

			}
			pp->num = sum;
			pp->exp = head_i->exp;

			pp->next = head_merged->next;
			head_merged->next = pp;

			
		}
		i++;
		head_i = head_i->next;
	}
	free(niz);
	
	return head_merged;

}

_position multiplication(_position head1, _position head2, _position head3) {
	_position h = head1->next;
	
	while (h != NULL) {
		_position h2 = head2->next;
		while (h2 != NULL) {
			_position pp = (_position)malloc(sizeof(poly));
			if (pp == NULL) {
				printf("error\nfailed alocation\n");
				return head1;

			}
			pp->exp = h->exp + h2->exp;
			pp->num = h->num * h2->num;

			pp->next = head3->next;
			head3->next = pp;

			h2 = h2->next;
		}
		h = h->next;
	}

	return head3;
}

_position sortPolynomials(_position head) {
	
	_position prev, temp, c, c1, end;

	end = NULL;
	while (head->next != end) {
		
		prev = head;
		c = head->next;
		if (c->next != NULL) {
			c1 = c->next;
		}
		else {
			c = NULL;
			return head;
		}
		while (c1 != end) {
			
			if (c->exp>c1->exp) {
				temp = c1;
				prev->next = temp;
				c->next = temp->next;
				temp->next = c;

				prev = temp;
				c1 = c->next;
			}
			
			else {
				prev = c;
				c = c1;
				c1 = c1->next;
			}

		}
		end = c;
	}

	return head;
}
_position readFrom1stFile(char nzv[], _position head) {
	FILE* p = NULL;
	int x = fopen_s(&p, nzv, "r");
	if (p == NULL || x != 0) {
		printf("closed\n");
		return head;
	}
	else {
		printf("open\n");
	}
	int n, e;
	while (fscanf_s(p, "%d %d", &n,&e) == 2) {
		_position po = (_position)malloc(sizeof(poly));

		if (po == NULL) {
			printf("alocation failed\n");
			return head;
		}
		po->num = n;
		po->exp = e;

		po->next = head->next;
		head->next = po;
	}
	fclose(p);
	return head;
}
void printingPolynomials(_position head) {
	head = head->next;
	while (head != NULL) {
		printf("%d %d\n", head->num, head->exp);
		head = head->next;
	}
	printf("\n");
}
_position addPolynomials(_position head1, _position head2, _position final) {
	
	 _position h1 = head1->next;
     while (h1 != NULL) {
        int found = 0;
        _position h2 = head2->next;
		while (h2 != NULL) {
			if (h1->exp == h2->exp) {
				_position pp = (_position)malloc(sizeof(poly));
				if (pp == NULL) {
					printf("error\n");
					return final;
				}
				pp->exp = h1->exp;
				pp->num = h1->num + h2->num;

				_position tt = final;
				while (tt->next != NULL) {
					tt = tt->next;
				}
                tt->next = pp;
                pp->next = NULL;

                found = 1;
                break;
            }
            h2 = h2->next;
        }

		if (found == 0) {
			_position pp = (_position)malloc(sizeof(poly));
			if (pp == NULL) {
				printf("error\n");
				return final;
			}
			pp->exp = h1->exp;
			pp->num = h1->num;

			_position tt = final;
			while (tt->next != NULL){
				tt = tt->next;
			}
            tt->next = pp;
            pp->next = NULL;
        }

        
		h1 = h1->next;
     }
	 _position h2 = head2->next;
    while (h2 != NULL) {
		int found = 0;
        _position t = final->next;
		 while (t != NULL) {
            if (t->exp == h2->exp) {
                found = 1;
                break;
            }
            t = t->next;
         }
		 if (found==0) {
            _position pp = (_position)malloc(sizeof(poly));
            if (pp == NULL) {
                printf("error\n");
                return final;
            }

            pp->exp = h2->exp;
            pp->num = h2->num;

          
            _position end = final;
            while (end->next != NULL)
                end = end->next;

            end->next = pp;
            pp->next = NULL;
         }

        h2 = h2->next;
    }

    return final;
}
void deletingPolynomials(_position head) {
	_position now = head->next;
	_position temp;
	
	while (now != NULL) {
		temp = now;
		now = now->next;
		free(temp);
	}
	head->next = NULL;

}

l_position read(l_position l1, char name[]) {
	FILE* fp = NULL;
	int x = fopen_s(&fp, name, "r");
	if (fp == NULL || x != 0) {
		printf("closed\n");
		return l1;
	}
	else {
		printf("opened\n");
	}
	int n;
	while (fscanf_s(fp, "%d", &n) == 1) {
		l_position po = (l_position)malloc(sizeof(poly));

		if (po == NULL) {
			printf("alocation failed\n");
			return l1;
		}
		po->num = n;

		po->next = l1->next;
		l1->next = po;
	}

	fclose(fp);
	return l1;
}
void printList(l_position head) {
	l_position temp = head->next;
	while (temp != NULL) {
		printf("%d\t", temp->num);
		temp=temp->next;
	}
}
void deleteList(l_position head) {
	l_position now = head->next;
	l_position temp = head;
	while (now != NULL) {
		temp = now;
		now = now->next;
		free(temp);
	}
	head->next = NULL;
}
l_position Union(l_position head1, l_position head2, l_position head3) {
	l_position h1 = head1->next;
	
	while (h1 != NULL) {
		int here = 0;
		l_position h2 = head2->next;
		while (h2 != NULL) {
			if (h1->num == h2->num) {
				l_position pp = (l_position)malloc(sizeof(list));
				if (pp == NULL) {
					printf("error\n");
					return head1;
				}
				pp->num = h1->num;

				l_position temp = head3;
				while (temp->next!= NULL) {
					temp = temp->next;
				}
				temp->next = pp;
				pp->next = NULL;
				here = 1;
				break;
			}
			
			h2 = h2->next;
		}
		if (here == 0) {
			l_position pp = (l_position)malloc(sizeof(list));
			if (pp == NULL) {
				printf("error\n");
				return head1;
			}
			pp->num = h1->num;

			l_position temp = head3;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = pp;
			pp->next = NULL;
			here = 1;
		}
		h1 = h1->next;
	}


	l_position h2 = head2->next;
	while (h2 != NULL) {
		l_position h3 = head3->next;
		int here = 0;
		while (h3 != NULL) {
			if (h2->num == h3->num) {
				here = 1;
				break;
			}
			h3 = h3->next;
		}
		if (here == 0) {
			l_position pp = (l_position)malloc(sizeof(list));
			if (pp == NULL) {
				printf("error\n");
				return head1;
			}
			pp->num = h2->num;

			l_position temp = head3;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = pp;
			pp->next = NULL;
			here = 1;
		}
		h2 = h2->next;
	}

	return head3;
}
l_position intersection(l_position head1, l_position head2, l_position head3) {
	l_position h1 = head1->next;
	while (h1 != NULL) {
		l_position h2= head2->next;
		while (h2 != NULL) {
			if (h1->num == h2->num) {
				l_position pp = (l_position)malloc(sizeof(list));
				if (pp == NULL) {
					printf("error\n");
					return head1;
				}
				pp->num = h1->num;

				l_position temp = head3;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = pp;
				pp->next = NULL;
			}
			h2 = h2->next;
		}
		h1 = h1->next;
	}
	return head3;
}

int push(int min, int max) {
	
	int r = (rand() % (max - min + 1)) + min;
	return r;


}
l_position fillList(l_position head, int len, int min, int max) {
	l_position h = head;
	int i = len;
	while (i > 0) {
		l_position pp = (l_position)malloc(sizeof(list));
		if (pp == NULL) {
			printf("error\n");
			return head;
		}

		pp->num = push(min, max);

		l_position h = head;

		while (h->next != NULL) {
			h = h->next;
		}
		h->next = pp;
		pp->next = NULL;

		i--;
	}
	return head;
}
l_position emptyStack(l_position head) {
	int c = -2;
	do {
		if (head->next == NULL) {
			printf("cant remove more, list is empty\n");
			return head;
		}
		l_position now = head;
		while (now->next->next != NULL) {
			now = now->next;
		}
		l_position temp;
		temp = now->next;
		now->next = NULL;
		free(temp);
		printList(head);
		printf("\ndo you want to remove 1 more num from stack y-1 n-0\n");
		scanf_s(" %d", &c);

		

	} while (c != 0);
	return head;
}
l_position emptyQueue(l_position head) {
	int c = -2;
	do {
		if (head->next == NULL) {
			printf("cant remove more, list is empty\n");
			return head;
		}
		l_position temp = head->next;
		l_position keep = temp->next;

		head->next = keep;
		
		free(temp);
		printList(head);
		printf("\ndo you want to remove 1 more num from queue y-1 n-0\n");
		scanf_s(" %d", &c);

		
	} while (c != 0);
	return head;
}

l_position fillCircularStack(l_position head, int l, int min, int max) {
	int i;

	for (i = 0; i < l; i++) {
		l_position _new =(l_position) malloc(sizeof(list));
		if (!_new) {
			printf(" error\n");
			return head;
		}

		_new->num = push(min, max);

		if (head->next == NULL) {
			head->next = _new;
			_new->next = _new;
		}
		else {
			
			_new->next = head->next->next;
			head->next->next =_new;
			head->next = _new;

		}
	}

	return head;
}
void printCircular(l_position head) {
	l_position start = head->next;

	if (start == NULL)
		return;

	l_position p = start;
	do {
		printf("%d\t", p->num);
		p = p->next;
	} while (p != start);

}
void deleteC(l_position head) {
	if (head->next == NULL)
		return;

	l_position start = head->next;
	l_position curr = start->next;

	while (curr != start) {
		l_position temp = curr;
		curr = curr->next;
		free(temp);
	}

	free(start);        
	head->next = NULL;
}
position_ queueP(position_ head, int l, int min, int max) {
	position_ h = head;
	int i = l;
	while (i > 0) {
		position_ pp = (position_)malloc(sizeof(listp));
		if (pp == NULL) {
			printf("error\n");
			return head;
		}

		pp->num = push(min, max);
		pp->priority = push(1, 5);
		position_ h = head;

		while (h->next != NULL) {
			h = h->next;
		}
		h->next = pp;
		pp->next = NULL;

		i--;
	}
	return head;
}
position_ sortByPriority(position_ head) {
	position_ prev, temp, c, c1, end;

	end = NULL;
	while (head->next != end) {

		prev = head;
		c = head->next;
		if (c->next != NULL) {
			c1 = c->next;
		}
		else {
			c = NULL;
			return head;
		}
		while (c1 != end) {

			if (c->priority > c1->priority) {
				temp = c1;
				prev->next = temp;
				c->next = temp->next;
				temp->next = c;

				prev = temp;
				c1 = c->next;
			}

			else {
				prev = c;
				c = c1;
				c1 = c1->next;
			}

		}
		end = c;
	}

	return head;

}
position_ emptyQueuePriority(position_ head) {
	int c = -2;
	do {
		if (head->next == NULL) {
			printf("cant remove more, list is empty\n");
			return head;
		}
		position_ temp = head->next;
		position_ keep = temp->next;

		head->next = keep;

		free(temp);
		printing_q(head);
		printf("\ndo you want to remove 1 more num from queue y-1 n-0\n");
		scanf_s(" %d", &c);


	} while (c != 0);
	return head;

}
void printing_q(position_ head) {
	position_ temp = head->next;
	
	while (temp != NULL) {
		printf("%d (%d)\t",temp->num,temp->priority);
		temp = temp->next;
	}
}





position putDataFromListToFile(char nameOfFile[], p* head) {
	FILE* f = NULL;
	int x = fopen_s(&f, nameOfFile, "w");
	if (x != 0 || f == NULL) {
		printf("error, file cant be opened\n");
		return head;
	}
	position temp = head->next;
	while (temp != NULL) {
		fprintf_s(f,"%31s %31s %d\n", temp->name,temp->lastname,
			temp->yearOfBirth);
		temp = temp->next;
	}
	fclose(f);
	return head;
}

position readFromFile(char fileName[], position head) {

	
	FILE* f = NULL;
	int x = fopen_s(&f, fileName, "r");
	if (x != 0 || f == NULL) {
		printf("cant open file\n");
		return head;
	}
	else {
		printf("file is open\n");
	}
	char ime[32], prez[32];
	int god;
	while (fscanf_s(f, "%31s %31s %d", ime,
		(unsigned)_countof(ime), prez,
		(unsigned)_countof(prez),&god) == 3) {
		
		position pp = (position)malloc(sizeof(p));
		if (pp == NULL) {
			printf("error\nneuspjesna alokacija\n");
			return head;

		}
		ime[strcspn(ime, "\r\n")] = '\0';
		prez[strcspn(prez, "\r\n")] = '\0';
		strcpy_s(pp->name, ime);
		strcpy_s(pp->lastname, prez);
		pp->yearOfBirth = god;

		pp->next = head->next;
		head->next = pp;
	}

	fclose(f);
	return head;
}
p* pushFront(position head) {
	/*position pp = (position)malloc(sizeof(p));
	if (pp == NULL) {
	printf("error\nneuspjesna alokacija\n");

	}*/
	int choice ;

	do {
		position pp = (position)malloc(sizeof(p));//------> ALOKACIJA UVIK UNUTRA (AKO JE VAN NEMA SMISLA!)
		if (pp == NULL) {
			printf("error\nneuspjesna alokacija\n");
			return head;

		}
		/*strcpy_s(pp->name, "Ivan");
		strcpy_s(pp->lastname, "Horvat");
		pp->yearOfBirth = 1994;*/

		char ime[32], prezime[32];
		int god;
		printf("enter name\n");
		scanf_s(" %31s", ime, (unsigned)_countof(ime));
		ime[strcspn(ime, "\r\n")] = '\0';
		strcpy_s(pp->name, ime);
		printf("enter lastname\n");
		scanf_s(" %31s", prezime, (unsigned)_countof(prezime));
		prezime[strcspn(prezime, "\r\n")] = '\0';
		strcpy_s(pp->lastname, prezime);
		printf("enteer year of birth\n");
		scanf_s(" %d", &god);
		pp->yearOfBirth = god;


		pp->next = head->next;
		head->next = pp;
		printf("do you want to continue?\nY-1,N-0");

		scanf_s(" %d", &choice);
		/*if (choice == 1) {
		char ime[32], prezime[32];
		int god;
		printf("enter name\n");
		scanf_s(" %31s",ime, (unsigned)_countof(ime));
		ime[strcspn(ime, "\r\n")] = '\0';
		strcpy_s(pp->name, ime);
		printf("enter lastname\n");
		scanf_s(" %31s",prezime, (unsigned)_countof(prezime));
		prezime[strcspn(prezime, "\r\n")] = '\0';
		strcpy_s(pp->name, prezime);
		printf("enteer year of birth\n");
		scanf_s(" %d",&god);
		pp->yearOfBirth = god;
		}
		pp->next = head->next;
		head->next = pp;*/

	} while (choice==1);

	return head;
}
void printing(position head) {
	position temp = head->next;
	//do {
	// printf("%31s\t%31s\t%d", temp->name, temp->lastname, temp->yearOfBirth);
	// temp = temp->next;
	//} while (temp != NULL);
	//
	while (temp != NULL) {
		printf("%31s\t%31s\t%d\n", temp->name, temp->lastname, temp->yearOfBirth);
		temp = temp->next;
	}//---->>> ako je NULL odma te izbacuje (bolje nego do-while)
}
void deleting(position head) {
	position now = head->next;
	position temp;
	/*do {
	temp = now;
	now = head->next;--------->>>>NEMOJ DO WHILE! PROVJERI NA POCETKU
	free(temp);

	} while (now != NULL);*/
	while (now != NULL) {
		temp = now;
		now = now->next;
		free(temp);
	}
	head->next = NULL;
}
position pushBack(p* head) {
	position now = head;
	while (now->next != NULL) {
		now = now->next;
	}
	printf("insert at the back of the list\n");
	//-----> Alociraj!
	position pp = (position)malloc(sizeof(p));
	char ime[32], prezime[32];
	int god;
	printf("enter name\n");
	scanf_s(" %31s", ime, (unsigned)_countof(ime));
	ime[strcspn(ime, "\r\n")] = '\0';
	strcpy_s(pp->name, ime);
	printf("enter lastname\n");
	scanf_s(" %31s", prezime, (unsigned)_countof(prezime));
	prezime[strcspn(prezime, "\r\n")] = '\0';
	strcpy_s(pp->lastname, prezime);
	printf("enteer year of birth\n");
	scanf_s(" %d", &god);
	pp->yearOfBirth = god;
	pp->next = NULL;//uzemlji!
	now->next = pp;
	return head;
}
position searchByLastName(char lastN[], p* head) {
	lastN[strcspn(lastN, "\n\r")] = '\0';
	position now = head->next;

	while (now != NULL) {

		if (_strcmpi(lastN, now->lastname) == 0) {
			printf("the person is found!\n");
			//now == NULL;
			return now;
		}
		else {

			now = now->next;

		}
	}


	printf("person not found\n");
	return NULL;
}
position deleteSelected(char name[], p* head) {
	//position temp;
	position before = head;
	position now = before->next;
	while (now != NULL) {
		if (_strcmpi(name, now->name) == 0) {
			before->next = now->next;
			free(now);
			printf("selected name is removed from the list\n");
			return head;
		}
		else if (_strcmpi(name, now->name) < 0 || _strcmpi(name, now->name) > 0) {
			now = now->next;
			before = before->next;
		}
	}
	printf("selected person not found\n");
	return head;
}
position addAfterSelected(char prezime[], p* head) {
	position newhead = (position)malloc(sizeof(p));
	//newhead = NULL;
	/*printf("enter lastname you want to add new element after\n");
	char lstnm[32];*///----> imas u main-u vec upisat prezime!
	//scanf_s(" %31s",lstnm, (unsigned)_countof(lstnm));
	//newhead= searchByLastName(lstnm, head);---->vamo je curilo
	if (newhead == NULL) {
		printf("allocation failed\n");
		return head;
	}
	prezime[strcspn(prezime, "\r\n")] = '\0';
	position n = searchByLastName(prezime, head);
	if (n != NULL) {
		printf("found!\n");
	}
	else {
		printf("not found\n ");
		free(newhead);
		return head;
	}


	printf("enter name of new person\n");
	scanf_s(" %31s", newhead->name, (unsigned)_countof(newhead->name));
	printf("enter lastname of new person\n");
	scanf_s(" %31s", newhead->lastname, (unsigned)_countof(newhead->lastname));
	printf("enter  of new person\n");
	scanf_s(" %d", &newhead->yearOfBirth);
	newhead->next = n->next;
	n->next = newhead;

	return head;
}
position addBeforeSelected(char lstname[], p* head) {
	position nHead = (position)malloc(sizeof(p));
	if (nHead == NULL) {
		printf("allocation failed\n");
		return head;
	}
	position check = searchByLastName(lstname, head);
	if (check == NULL) {
		printf("person not found\n");
		free(nHead);///-->nemoj zaboravljat!
		return head;
	}
	position front = head;
	while (front->next != check) {
		front = front->next;
	}
	printf("enter name of new person\n");
	scanf_s(" %31s", nHead->name, (unsigned)_countof(nHead->name));
	printf("enter lastname of new person\n");
	scanf_s(" %31s", nHead->lastname, (unsigned)_countof(nHead->lastname));
	printf("enter  of new person\n");
	scanf_s(" %d", &nHead->yearOfBirth);

	nHead->next = front->next;
	front->next = nHead;
	return head;

}
position sortListByLastname(p* head) {
	////NEMA OVDE ALOKACIJE !
	position prev, temp, c, c1, end;
	
	end = NULL;
	while (head->next != end) {
		/*c = head->next;
		c1 = c->next;*/
		prev = head;
		c = head->next;
		if (c->next != NULL) {
			c1 = c->next;
		}
		else {
			c = NULL;
			return head;
		}
		while (c1 != end) {
			//prev = findPositionBefore(head,c);->mozda remeti
			/*if (prev == NULL) {
			printf("position of the previus element not found\n");
			return head;
			}*/
			if (_strcmpi(c->lastname, c1->lastname) > 0) {
				temp = c1;
				prev->next = temp;
				c->next = temp->next;
				temp->next = c;

				prev = temp;
				c1 = c->next;
			}
			/*else {
			//pomocna zamjena
			position p_prev, p_c, p_c1, p_temp;
			p_prev = c;
			p_c = c1;
			p_c1 = p_c->next;

			p_temp = p_c1;
			p_prev->next = p_temp;
			p_c = p_temp->next;
			p_temp->next = p_c;


			}*/
			else {
				prev = c;
				c = c1;
				c1 = c1->next;
			}
			
		}
		end = c;
	}

	return head;
}
position findPositionBefore(p* head, p* trenutno) {
	p* start = (p*)malloc(sizeof(p));
	p* finish = (p*)malloc(sizeof(p));
	if (start == NULL) {
		printf("alocation failed (findPositionBefore1)\n");
		free(finish);
		return head;//provjeri oćeš li vraćat null
	}
	if (finish == NULL) {
		printf("alocation failed (findPositionBefore2)\n");
		free(start);
		return head;
	}
	start = head;
	finish = searchByLastName(finish->lastname, head);
	if (finish == NULL) {
		printf("position in function findPositionBefore was not found\n ");
		return NULL;//provjeri šta vracas
	}
	while (start->next != finish) {
		start = start->next;
	}
	return start;

}
int findNumOfDataInList(_position head) {
	//head = head->next;
	int i = 0;
	while (head != NULL) {
		head=head->next;
		i++;
	}

	return i;
}
int isNumThere(int size, int n, int* arr) {
	int here = 0;
	for (int i = 0;i < size;i++) {
		if (n == *(arr + i)) {
			here++;
		}
	}
	
	if (here > 1) {
		//printf("number %d is found more than 1 time\n",n);
		return -1;
	}
	else if (here == 1) {
		//printf("number %d is found \n",n);
		return 0;
	}
	else if (here < 1) {
		//printf("number %d is not found \n", n);
		return -1;
	}
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
