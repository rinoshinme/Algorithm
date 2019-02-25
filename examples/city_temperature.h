#ifndef CITY_TEMPERATURE_H
#define CITY_TEMPERATURE_H

#include <string>

struct Node
{
	char* city;
	int temp;
	struct Node* next;
};

typedef struct Node* Link;

/* functions for linked list */
int AddNodeAscend(Link);
void CreateList(void);
int DeleteNode(Link);
int DuplicateNode(Link, Link);
void FreeNode(Link);
void ShowNodes(void);
int NodeCmp(Link, Link);

void testCityTemp(const std::string& input_file);

#endif
