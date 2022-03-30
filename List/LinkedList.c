#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


typedef struct Node {
	void* item;
	Node_t next;
} Node;

typedef struct LinkedList {
	Node_t root;
} LinkedList;

LinkedList_t create() {
	LinkedList_t _newList = calloc(sizeof(LinkedList), 1);

	if (NULL == _newList) { // There was not enough memory
		return NULL;
	}
	Node_t _newNode = calloc(sizeof(Node), 1);
	_newList->root = _newNode;
	return _newList;
};

uint16_t linked_list_length(LinkedList_t self) {
	uint16_t i = 0;
	Node_t _checkedNode;
	for (_checkedNode = self->root; _checkedNode->item != NULL; _checkedNode = _checkedNode->next) {
		i++;
	}
	return i;
	//while (1) {
	//	if (_checkedNode->next != NULL) {
	//		i++;
	//		_checkedNode = _checkedNode->next;
	//	}
	//	else if (_checkedNode->next == NULL) {
	//		return i;
	//	}
	//}
	//return i;
};


LinkedListReturnCode destroy(LinkedList_t self) {
	if (NULL != self) {
		free(self);
	}
	return 3;
};

LinkedListReturnCode push(LinkedList_t self, void* item) {
	Node_t _checkedNode = self->root;
	while (1)
	{
		if (_checkedNode->item == NULL)
		{
			_checkedNode->item = item;
			_checkedNode->next = calloc(sizeof(Node), 1);
			printf("Insert\n");
			return 1;
		}
		else
		{
			_checkedNode = _checkedNode->next;
			printf("Going next\n");
		}
	}

};
void* pull(LinkedList_t self) {
	Node_t _checkedNode = self->root;
	while (1)
	{
		printf("Pulled : %s\n", _checkedNode->item);
		if (_checkedNode->next->item != NULL) {
			printf("Mike : %s\n", _checkedNode->item);
			_checkedNode = _checkedNode->next;
		}
		else
		{
			printf("Yoink : %s\n", _checkedNode->item);
			return _checkedNode->item;
		}
	};
}

LinkedListReturnCode containsItem(LinkedList_t self, void* item) {
	Node_t _checkedNode = self->root;
	while (1)
	{
		if (_checkedNode == NULL)
		{
			return 1;
		}
		else if (_checkedNode->item == item)
		{
			return 4;
		}

		else if (_checkedNode->next == NULL) {
			return 2;
		}
		else
		{
			_checkedNode = _checkedNode->next;

		}
	}
};
LinkedListReturnCode removeItem(LinkedList_t self, void* item) {
	Node_t _checkedNode = self->root;
	while (1)
	{
		if (_checkedNode->item == item)
		{
			_checkedNode->item = _checkedNode->next->item;
			if (_checkedNode->next->next == NULL)
			{
				_checkedNode->next = NULL;
				return 0;
			}
			else {
				_checkedNode->next = _checkedNode->next->next;
				return 0;
			}
		}
		else if (_checkedNode->next == NULL)
		{
			return 2;
		}
		else
		{
			_checkedNode = _checkedNode->next;

		}
	}
};
void* peekItemByIndex(LinkedList_t self, uint16_t index) {
	int i = 0;
	Node_t _checkedNode = self->root;
	while (i != index) {
		_checkedNode = _checkedNode->next;
		i++;
	}
	return _checkedNode->item;
};



void linked_list_clear(LinkedList_t self) {
	self->root = NULL;
};
//LinkedListIterator getIterator();
//void* iteratorNext(LinkedListIterator iterator);