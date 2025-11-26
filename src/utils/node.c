#include "node.h"
#include <stdlib.h>
#include <string.h>

Node_s* Node_new(void* pData, size_t ulSize) {
	Node_s* pNode = malloc(sizeof(Node_s));
	if (NULL == pNode) {
		return pNode;
	} // End of if-condition

	pNode->m_pPreNode = NULL;
	pNode->m_pData = NULL;
	pNode->m_pNextNode = NULL;

	if (NULL == pData || 0 == ulSize) {
		return pNode;
	} // End of if-condition

	pNode->m_pData = malloc(ulSize);
	memcpy(pNode->m_pData, pData, ulSize);

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
