#include "LinkedList.h"

static void _printStatus(LinkedListReturnCode status)
{
	if (status == 0)
	{
		printf("Ok\n");
	}
	else if (status == 1) {
		printf("EMPTY\n");
	}
	else if (status == 2) {
		printf("NOT_FOUND\n");
	}
	else if (status == 3) {
		printf("FULL\n");
	}
	else
	{
		printf("FOUND\n");
	}
}

int main(void) {
	LinkedList_t myList = create();
	push(myList, "strin");
	push(myList, "strang");
	printf("End\n");
	printf("Lenght : %i\n", linked_list_length(myList));
	printf("Peek : %s\n", peekItemByIndex(myList,1));
	_printStatus(containsItem(myList, "strin"));
	_printStatus(containsItem(myList, "strin"));
	_printStatus(containsItem(myList, "strang"));
	printf("Lenght : %i\n", linked_list_length(myList));
	printf("Pull : %s\n", pull(myList));
	_printStatus(removeItem(myList, "strin"));
	printf("Lenght : %i\n", linked_list_length(myList));
	_printStatus(containsItem(myList, "strin"));
	printf("Pull : %s\n", pull(myList));
	linked_list_clear(myList);
	_printStatus(containsItem(myList, "strang"));
	_printStatus(containsItem(myList, "string"));

}