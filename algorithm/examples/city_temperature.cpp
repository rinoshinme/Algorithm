#include "city_temperature.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>

Link head;
int nodeCount;

int AddNodeAscend(Link to_add)
{
	Link pn, prev, curr;
	struct Node dummy;
	int i = 0;

	pn = (Link)malloc(sizeof(struct Node));
	if (pn == NULL)
		return 0;
	memcpy(pn, to_add, sizeof(struct Node));

	dummy.next = head;
	prev = &dummy;
	curr = head;

	for (;; prev = curr, curr = curr->next)
	{
		if (curr == NULL)
			break;
		i = NodeCmp(pn, curr);
		if (i <= 0)
			break;
	}

	if (curr && i == 0)
	{
		if (DuplicateNode(curr, pn) == 0)
			return 1;
	}

	prev->next = pn;
	pn->next = curr;
	head = dummy.next;
	return 1;
}

int DuplicateNode(Link inlist, Link duplicate)
{
	FreeNode(duplicate);
	return 0;
}

int DeleteNode(Link to_delete)
{
	Link curr = NULL;
	Link prev = NULL;
	int i = 0;
	if (head == NULL)
		return 0;

	for (prev = NULL, curr = head;
		curr != NULL && (i = NodeCmp(to_delete, curr)) > 0;
		prev = curr, curr = curr->next)
		;
	// found a match
	if (curr != NULL && i == 0)
	{
		if (prev)
			prev->next = curr->next;
		else
			head = curr->next;
		FreeNode(curr);
		nodeCount -= 1;
		return 1;
	}
	return 0;
}

int NodeCmp(Link a, Link b)
{
	if (a->temp != b->temp)
		return (a->temp - b->temp);
	return strcmp(a->city, b->city);
}

void CreateList()
{
	head = NULL;
	nodeCount = 0;
}

void FreeNode(Link n)
{
	free(n->city);
	free(n);
}

void ShowNodes()
{
	Link pn;
	int count, median;
	for (count = 0, pn = head; pn; pn = pn->next)
		count += 1;

	median = count / 2 + 1;
	if (count)
	{
		count = 0;
		for (pn = head; pn; pn = pn->next)
		{
			printf("%-20s: %3d", pn->city, pn->temp);
			count += 1;
			if (count == median)
				printf(" --Median-- ");
			printf("\n");
		}
	}
	else
		printf("Empty List\n");
}

void testCityTemp(const std::string& input_file)
{
	FILE* fin;
	char buffer[128];
	struct Node n;

	fin = fopen(input_file.c_str(), "rt");
	if (fin == NULL)
		exit(EXIT_FAILURE);

	CreateList();

	while (!feof(fin))
	{
		if (fgets(buffer, 127, fin) == NULL)
			break;

		// get rid of carriage return
		buffer[strlen(buffer) - 1] = '\0';
#ifdef _WIN32
		n.city = _strdup(buffer + 3);
#else
        n.city = strdup(buffer + 3);
#endif
		buffer[3] = '\0';
		n.temp = atoi(buffer);
		if (AddNodeAscend(&n) == 0)
		{
			fprintf(stderr, "error adding a node\n");
			exit(EXIT_FAILURE);
		}
	}
	ShowNodes();

	// delete something
	printf("\n");
	DeleteNode(head);
	ShowNodes();

	while (head && head->next)
	{
		printf("\n");
		DeleteNode(head->next);
		ShowNodes();
	}

	printf("\n");
	DeleteNode(head);
	ShowNodes();

	fclose(fin);
	exit(EXIT_SUCCESS);
}
