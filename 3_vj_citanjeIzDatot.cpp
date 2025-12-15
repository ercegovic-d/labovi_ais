// 3_vj_citanjeIzDatot.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
position readFromFile(char[], position);
position sortListByLastname(p*);
void printing(position);
void deleting(position);

int main()
{

	p head;
	head.next = NULL;

	char imeDat[] = "people.txt";
	readFromFile(imeDat, &head);
	printing(&head);
	printf("sort list by last name");
	sortListByLastname(&head);
	printing(&head);
	deleting(&head);

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
	
	while (now != NULL) {
		temp = now;
		now = now->next;
		free(temp);
	}
	head->next = NULL;
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


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
