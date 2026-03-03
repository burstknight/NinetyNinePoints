#include "LinkedList.h"
#include "utils/node.h"
#include <stdbool.h>
#include <stddef.h>
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

void LinkedList_release(LinkedList_s* pLinkedList) {
	if (NULL == pLinkedList) {
		return;
	} // End of if-condition

	LinkedList_clearAllNodes(pLinkedList);
	free(pLinkedList);
} // End of LinkedList_release

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
	} else {
		pLinkedList->m_pTailNode = NULL;
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
	if (NULL == pRemovedNode) {
		return;
	} // End of if-condition

	Node_release(pRemovedNode);
	pRemovedNode = NULL;
} // End of LinkedList_removeNodeFront

void LinkedList_clearAllNodes(LinkedList_s* pLinkedList) {
	if (NULL == pLinkedList) {
		return;
	} // End of if-condition

	while (true) {
		if (0 == pLinkedList->m_ulNumOfNode) {
			break;
		} // End of if-condition

		LinkedList_removeNodeFront(pLinkedList);
	} // End of while-loop
} // End of LinkedList_clearAllNodes

int LinkedList_addNodeRear(LinkedList_s* pLinkedList, void* pData, size_t ulSizeOfData) {
	if (NULL == pLinkedList) {
		return -1;
	} // End of if-condition

	if (NULL == pLinkedList->m_pHeadNode) {
		return LinkedList_addNodeFront(pLinkedList, pData, ulSizeOfData);
	} // End of if-condition

	Node_s* pNewNode = Node_new(pData, ulSizeOfData);
	if (NULL == pNewNode) {
		return -1;
	} // End of if-condition

	pLinkedList->m_pTailNode->m_pNextNode = pNewNode;
	pNewNode->m_pPreNode = pLinkedList->m_pTailNode;
	pLinkedList->m_pTailNode = pNewNode;
	pLinkedList->m_ulNumOfNode++;

	return (NULL != pData && ulSizeOfData > 0) ? 0 : 1;
} // End of LinkedList_addNodeRear

Node_s* LinkedList_popNodeRear(LinkedList_s* pLinkedList) {
	if (NULL == pLinkedList) {
		return NULL;
	} // End of if-condition

	if (NULL == pLinkedList->m_pTailNode) {
		return NULL;
	} // End of if-condition

	Node_s* pNode = pLinkedList->m_pTailNode;
	if (pLinkedList->m_pHeadNode == pNode) {
		pLinkedList->m_pTailNode = NULL;
		pLinkedList->m_pHeadNode = NULL;
		pLinkedList->m_ulNumOfNode = 0;

		return pNode;
	} // End of if-condition

	pLinkedList->m_pTailNode = pLinkedList->m_pTailNode->m_pPreNode;
	pLinkedList->m_pTailNode->m_pNextNode = NULL;
	pLinkedList->m_ulNumOfNode--;

	pNode->m_pPreNode = NULL;

	return pNode;
} // End of LinkedList_popNodeRear

int LinkedList_cloneFromArray(LinkedList_s* pLinkedList, void* pData, size_t ulSizeOfData, size_t ulLength) {
	if (NULL == pLinkedList) {
		return 1;
	} // End of if-condition

	if (NULL == pData || 0 == ulSizeOfData || 0 == ulLength) {
		return -1;
	} // End of if-condition

	if (pLinkedList->m_ulNumOfNode > 0) {
		LinkedList_clearAllNodes(pLinkedList);
	} // End of if-condition

	void* pIter = pData;
	int iResult = 0;
	for (size_t i = 0; i < ulLength; i++) {
		pIter += i * ulSizeOfData;
		iResult |= LinkedList_addNodeFront(pLinkedList, pIter, ulSizeOfData);
	} // End of for-loop

	return (0 == iResult) ? 0 : -1;
} // End of LinkedList_cloneFromArray
