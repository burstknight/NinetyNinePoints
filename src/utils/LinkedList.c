#include "LinkedList.h"
#include "utils/node.h"
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

int LinkedList_addNodeFront(LinkedList_s* pLinkedList, void* pData, size_t ulSizeOfData) {
	if (NULL == pLinkedList) {
		return -1;
	} // End of if-condition

	Node_s* pNode = Node_new(pData, ulSizeOfData);
	if (NULL == pNode) {
		return -1;
	} // End of if-condition

	if (NULL == pLinkedList->m_pHeadNode) {
		pLinkedList->m_pTailNode = pNode;
	} else {
		pNode->m_pNextNode = pLinkedList->m_pHeadNode;
		pLinkedList->m_pHeadNode->m_pPreNode = pNode;
	} // End of if-condition

	pLinkedList->m_pHeadNode = pNode;
	pLinkedList->m_ulNumOfNode++;

	return (ulSizeOfData > 0 && NULL != pData) ? 0 : 1;
} // End of LinkedList_addNodeFront

Node_s* LinkedList_popNodeFront(LinkedList_s* pLinkedList) {
	if (NULL == pLinkedList) {
		return NULL;
	} // End of if-condition

	if (NULL == pLinkedList->m_pHeadNode) {
		return NULL;
	} // End of if-condition

	/*
	 * Draw out the head node from the linked list.
	 */
	Node_s* pPoppedNode = pLinkedList->m_pHeadNode;

	pLinkedList->m_pHeadNode = pLinkedList->m_pHeadNode->m_pNextNode;
	if (NULL != pLinkedList->m_pHeadNode) {
		pLinkedList->m_pHeadNode->m_pPreNode = NULL;
	} // End of if-condition

	pPoppedNode->m_pNextNode = NULL;
	(pLinkedList->m_ulNumOfNode)--;
	return pPoppedNode;
} // End of LinkedList_popNodeFront

void LinkedList_removeNodeFront(LinkedList_s* pLinkedList) {
	/*
	 * Draw out the head node from the linked list to remove.
	 */
	Node_s* pRemovedNode = LinkedList_popNodeFront(pLinkedList);

	Node_release(pRemovedNode);
	pRemovedNode = NULL;
} // End of LinkedList_removeNodeFront
