#include "node.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

Node_s* Node_new(void* pData, size_t ulSize) {
	Node_s* pNode = malloc(sizeof(Node_s));
	if (NULL == pNode) {
		return pNode;
	} // End of if-condition

	pNode->m_pPreNode = NULL;
	pNode->m_pData = NULL;
	pNode->m_ulSizeOfData = 0;
	pNode->m_pNextNode = NULL;

	Node_setData(pNode, pData, ulSize);

	return pNode;
} // End of Node_new

void Node_release(Node_s* pNode) {
	if (NULL == pNode) {
		return;
	} // End of if-condition

	if (NULL != pNode->m_pData) {
		free(pNode->m_pData);
	} // End of if-condition
	pNode->m_pData = NULL;

	free(pNode);
} // End of Node_release

size_t Node_setData(Node_s* pNode, void* pNewData, size_t ulSize) {
	if (NULL == pNode) {
		return 0;
	} // End of if-condition

	if (NULL == pNewData || 0 == ulSize) {
		return 0;
	} // End of if-condition

	/*
	 * Clear old data if the data is not empty.
	 */
	if (NULL != pNode->m_pData) {
		free(pNode->m_pData);
		pNode->m_pData = NULL;
	} // End of if-condition

	pNode->m_pData = malloc(ulSize);
	if (NULL == pNode->m_pData) {
		return 0;
	} // End of if-condition

	pNode->m_ulSizeOfData = ulSize;
	memcpy(pNode->m_pData, pNewData, ulSize);

	return ulSize;
} // End of Node_setData

void* Node_cloneData(Node_s* pNode) {
	if (NULL == pNode) {
		return NULL;
	} // End of if-condition

	if (NULL == pNode->m_pData || 0 == pNode->m_ulSizeOfData) {
		return NULL;
	} // End of if-condition

	void* pCloneData = malloc(pNode->m_ulSizeOfData);
	if (NULL == pCloneData) {
		return NULL;
	} // End of if-condition

	memcpy(pCloneData, pNode->m_pData, pNode->m_ulSizeOfData);

	return pCloneData;
} // End of Node_cloneData
