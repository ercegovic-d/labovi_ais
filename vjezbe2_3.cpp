// vjezbe2_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
void printing(position);
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
int main()
{
	p head;
	head.next = NULL;
	int o;
	scanf_s(" %d", &o);
	if (o == 2) {
		pushFront(&head);
		printf("back insert\n");
		pushBack(&head);
		printing(&head);


		printf("enter lastname you want to find inside a list\n");
		char lstName[32];
		scanf_s(" %31s", lstName, (unsigned)_countof(lstName));
		
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


		char lName1[32];
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


	return 0;
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
		(unsigned)_countof(prez), &god) == 3) {

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
	
	int choice;

	do {
		position pp = (position)malloc(sizeof(p));//------> ALOKACIJA UVIK UNUTRA (AKO JE VAN NEMA SMISLA!)
		if (pp == NULL) {
			printf("error\nneuspjesna alokacija\n");
			return head;

		}
		

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
		

	} while (choice == 1);

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
		return head;
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
		return NULL;
	}
	while (start->next != finish) {
		start = start->next;
	}
	return start;

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
		fprintf_s(f, "%31s %31s %d\n", temp->name, temp->lastname,
			temp->yearOfBirth);
		temp = temp->next;
	}
	fclose(f);
	return head;
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
