#include "unity.h"
#include "unity_internals.h"
#include "utils/LinkedList.h"
#include "utils/node.h"
#include <stdbool.h>
#include <stdlib.h>

static LinkedList_s* pLinkedList = NULL;

void setUp() {
	pLinkedList = NULL;
} // End setUp

void tearDown() {
	free(pLinkedList);
	pLinkedList = NULL;
} // End of tearDown

/**
 * @brief Test the function LinkedList_new().
 */
void test_LinkedList_new(void) {
	pLinkedList = LinkedList_new();

	TEST_ASSERT(NULL != pLinkedList);
	TEST_ASSERT(NULL == pLinkedList->m_pHeadNode);
	TEST_ASSERT(NULL == pLinkedList->m_pTailNode);
	TEST_ASSERT(0 == pLinkedList->m_ulNumOfNode);
} // End of test_LinkedList_new

/**
 * @brief Test the function LinkedList_addNodeFront() for NULL data case.
 */
void test_LinkedList_addNodeFront_Null(void) {
	TEST_ASSERT(-1 == LinkedList_addNodeFront(pLinkedList, NULL, 0));

	pLinkedList = LinkedList_new();
	TEST_ASSERT(1 == LinkedList_addNodeFront(pLinkedList, NULL, 0));
	TEST_ASSERT(1 == pLinkedList->m_ulNumOfNode);
	TEST_ASSERT(NULL != pLinkedList->m_pHeadNode);
	TEST_ASSERT(NULL != pLinkedList->m_pTailNode);
	TEST_ASSERT(pLinkedList->m_pHeadNode == pLinkedList->m_pTailNode);

	TEST_ASSERT(NULL == pLinkedList->m_pHeadNode->m_pData);
	TEST_ASSERT(0 == pLinkedList->m_pHeadNode->m_ulSizeOfData);

	Node_release(pLinkedList->m_pHeadNode);
	pLinkedList->m_pHeadNode = NULL;
	pLinkedList->m_pTailNode = NULL;
	pLinkedList->m_ulNumOfNode = 0;
} // End of test_LinkedList_addNodeFront_Null

/**
 * @brief Test the function LinkedList_addNodeFront() for zero data size case.
 */
void test_LinkedList_addNodeFront_ZeroDataSize(void) {
	pLinkedList = LinkedList_new();
	int iData = 99;
	TEST_ASSERT(1 == LinkedList_addNodeFront(pLinkedList, &iData, 0));
	TEST_ASSERT(1 == pLinkedList->m_ulNumOfNode);
	TEST_ASSERT(NULL != pLinkedList->m_pHeadNode);
	TEST_ASSERT(NULL != pLinkedList->m_pTailNode);
	TEST_ASSERT(pLinkedList->m_pHeadNode == pLinkedList->m_pTailNode);

	TEST_ASSERT(NULL == pLinkedList->m_pHeadNode->m_pData);
	TEST_ASSERT(0 == pLinkedList->m_pHeadNode->m_ulSizeOfData);

	Node_release(pLinkedList->m_pHeadNode);
	pLinkedList->m_pHeadNode = NULL;
	pLinkedList->m_pTailNode = NULL;
	pLinkedList->m_ulNumOfNode = 0;
} // End of test_LinkedList_addNodeFront_ZeroDataSize

/**
 * @brief Test the function LinkedList_addNodeFront() for given real data case.
 */
void test_LinkedList_addNodeFront_RealData(void) {
	pLinkedList = LinkedList_new();
	for (int i = 1; i <= 3; i++) {
		TEST_ASSERT(0 == LinkedList_addNodeFront(pLinkedList, &i, sizeof(int)));
	} // End of for-loop

	TEST_ASSERT(3 == pLinkedList->m_ulNumOfNode);
	TEST_ASSERT(NULL != pLinkedList->m_pHeadNode);
	TEST_ASSERT(NULL != pLinkedList->m_pTailNode);
	TEST_ASSERT(pLinkedList->m_pHeadNode != pLinkedList->m_pTailNode);

	int iExpectedData = 3;
	Node_s* pIter = pLinkedList->m_pHeadNode;
	while (true) {
		if (NULL == pIter) {
			break;
		} // End of if-condition

		TEST_ASSERT(iExpectedData == *((int*)pIter->m_pData));
		TEST_ASSERT(sizeof(int) == pIter->m_ulSizeOfData);

		pIter = pIter->m_pNextNode;
		iExpectedData--;
	} // End of while-loop

	pIter = pLinkedList->m_pHeadNode;
	while (true) {
		if (NULL == pIter) {
			break;
		} // End of if-condition

		Node_s* pRemovedNode = pIter;
		pIter = pIter->m_pNextNode;
		Node_release(pRemovedNode);
	} // End of while-loop

	pLinkedList->m_pHeadNode = NULL;
	pLinkedList->m_pTailNode = NULL;
} // End of test_LinkedList_addNodeFront_RealData

int main(int argc, char** argv) {
	UnityBegin("./test_LinkedList.c");

	RUN_TEST(test_LinkedList_new);
	RUN_TEST(test_LinkedList_addNodeFront_Null);
	RUN_TEST(test_LinkedList_addNodeFront_ZeroDataSize);
	RUN_TEST(test_LinkedList_addNodeFront_RealData);

	return UnityEnd();
} // End of main
