#include "LinkedList.h"
#include <stdlib.h>

LinkedList_s* LinkedList_new() {
	LinkedList_s* pLinkedList = malloc(sizeof(LinkedList_s));
	if (NULL == pLinkedList) {
		return NULL;
	} // End of if-condition

	pLinkedList->m_pHeadNode = NULL;
	pLinkedList->m_pTailNode = NULL;
	pLinkedList->m_ulNumOfNode = 0;

	return pLinkedList;
} // End of LinkedList_new
