#include "unity.h"
#include "unity_internals.h"
#include "utils/LinkedList.h"
#include "utils/node.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static LinkedList_s* s_pLinkedList = NULL;

void setUp() {
	s_pLinkedList = NULL;
} // End setUp

void tearDown() {
	free(s_pLinkedList);
	s_pLinkedList = NULL;
} // End of tearDown

/**
 * @brief Test the function LinkedList_new().
 */
void test_LinkedList_new(void) {
	s_pLinkedList = LinkedList_new();

	TEST_ASSERT(NULL != s_pLinkedList);
	TEST_ASSERT(NULL == s_pLinkedList->m_pHeadNode);
	TEST_ASSERT(NULL == s_pLinkedList->m_pTailNode);
	TEST_ASSERT(0 == s_pLinkedList->m_ulNumOfNode);
} // End of test_LinkedList_new

/**
 * @brief Test the function LinkedList_addNodeFront() for NULL data case.
 */
void test_LinkedList_addNodeFront_Null(void) {
	TEST_ASSERT(-1 == LinkedList_addNodeFront(s_pLinkedList, NULL, 0));

	s_pLinkedList = LinkedList_new();
	TEST_ASSERT(1 == LinkedList_addNodeFront(s_pLinkedList, NULL, 0));
	TEST_ASSERT(1 == s_pLinkedList->m_ulNumOfNode);
	TEST_ASSERT(NULL != s_pLinkedList->m_pHeadNode);
	TEST_ASSERT(NULL != s_pLinkedList->m_pTailNode);
	TEST_ASSERT(s_pLinkedList->m_pHeadNode == s_pLinkedList->m_pTailNode);

	TEST_ASSERT(NULL == s_pLinkedList->m_pHeadNode->m_pData);
	TEST_ASSERT(0 == s_pLinkedList->m_pHeadNode->m_ulSizeOfData);

	Node_release(s_pLinkedList->m_pHeadNode);
	s_pLinkedList->m_pHeadNode = NULL;
	s_pLinkedList->m_pTailNode = NULL;
	s_pLinkedList->m_ulNumOfNode = 0;
} // End of test_LinkedList_addNodeFront_Null

/**
 * @brief Test the function LinkedList_addNodeFront() for zero data size case.
 */
void test_LinkedList_addNodeFront_ZeroDataSize(void) {
	s_pLinkedList = LinkedList_new();
	int iData = 99;
	TEST_ASSERT(1 == LinkedList_addNodeFront(s_pLinkedList, &iData, 0));
	TEST_ASSERT(1 == s_pLinkedList->m_ulNumOfNode);
	TEST_ASSERT(NULL != s_pLinkedList->m_pHeadNode);
	TEST_ASSERT(NULL != s_pLinkedList->m_pTailNode);
	TEST_ASSERT(s_pLinkedList->m_pHeadNode == s_pLinkedList->m_pTailNode);

	TEST_ASSERT(NULL == s_pLinkedList->m_pHeadNode->m_pData);
	TEST_ASSERT(0 == s_pLinkedList->m_pHeadNode->m_ulSizeOfData);

	Node_release(s_pLinkedList->m_pHeadNode);
	s_pLinkedList->m_pHeadNode = NULL;
	s_pLinkedList->m_pTailNode = NULL;
	s_pLinkedList->m_ulNumOfNode = 0;
} // End of test_LinkedList_addNodeFront_ZeroDataSize

/**
 * @brief Test the function LinkedList_addNodeFront() for given real data case.
 */
void test_LinkedList_addNodeFront_RealData(void) {
	s_pLinkedList = LinkedList_new();
	for (int i = 1; i <= 3; i++) {
		TEST_ASSERT(0 == LinkedList_addNodeFront(s_pLinkedList, &i, sizeof(int)));
	} // End of for-loop

	TEST_ASSERT(3 == s_pLinkedList->m_ulNumOfNode);
	TEST_ASSERT(NULL != s_pLinkedList->m_pHeadNode);
	TEST_ASSERT(NULL != s_pLinkedList->m_pTailNode);
	TEST_ASSERT(s_pLinkedList->m_pHeadNode != s_pLinkedList->m_pTailNode);

	int iExpectedData = 3;
	Node_s* pIter = s_pLinkedList->m_pHeadNode;
	while (true) {
		if (NULL == pIter) {
			break;
		} // End of if-condition

		TEST_ASSERT(iExpectedData == *((int*)pIter->m_pData));
		TEST_ASSERT(sizeof(int) == pIter->m_ulSizeOfData);

		pIter = pIter->m_pNextNode;
		iExpectedData--;
	} // End of while-loop

	pIter = s_pLinkedList->m_pHeadNode;
	while (true) {
		if (NULL == pIter) {
			break;
		} // End of if-condition

		Node_s* pRemovedNode = pIter;
		pIter = pIter->m_pNextNode;
		Node_release(pRemovedNode);
	} // End of while-loop

	s_pLinkedList->m_pHeadNode = NULL;
	s_pLinkedList->m_pTailNode = NULL;
} // End of test_LinkedList_addNodeFront_RealData

/**
 * @brief Test the function LinkedList_popNodeFront() for NULL casees.
 */
void test_LinkedList_popNodeFront_Null(void) {
	TEST_ASSERT(NULL == LinkedList_popNodeFront(s_pLinkedList));

	s_pLinkedList = LinkedList_new();
	TEST_ASSERT(NULL == LinkedList_popNodeFront(s_pLinkedList));
} // End of test_LinkedList_popNodeFront_Null

/**
 * @brief Test the function LinkedList_popNodeFront() for given real data case.
 */
void test_LinkedList_popNodeFront_RealData(void) {
	s_pLinkedList = LinkedList_new();
	for (int i = 1; i <= 3; i++) {
		LinkedList_addNodeFront(s_pLinkedList, &i, sizeof(int));
	} // End of for-loop
	TEST_ASSERT(3 == s_pLinkedList->m_ulNumOfNode);

	for (int i = 3; i >= 1; i--) {
		Node_s* pExpectedNode = s_pLinkedList->m_pHeadNode;
		Node_s* pPoppedNode = LinkedList_popNodeFront(s_pLinkedList);

		TEST_ASSERT(pExpectedNode == pPoppedNode);
		TEST_ASSERT(NULL != pPoppedNode);
		TEST_ASSERT(i == *((int*)pPoppedNode->m_pData));
		TEST_ASSERT((size_t)i - 1 == s_pLinkedList->m_ulNumOfNode);

		Node_release(pPoppedNode);
		pPoppedNode = NULL;
		pExpectedNode = NULL;
	} // End of for-loop

	TEST_ASSERT(0 == s_pLinkedList->m_ulNumOfNode);
	TEST_ASSERT(NULL == s_pLinkedList->m_pHeadNode);
	TEST_ASSERT(NULL == s_pLinkedList->m_pTailNode);

	TEST_ASSERT(NULL == LinkedList_popNodeFront(s_pLinkedList));
} // End of test_LinkedList_popNodeFront_RealData

/**
 * @brief Test the function LinkedList_removeNodeFront().
 */
void test_LinkedList_removeNodeFront(void) {
	s_pLinkedList = LinkedList_new();
	for (int i = 1; i <= 3; i++) {
		LinkedList_addNodeFront(s_pLinkedList, &i, sizeof(int));
	} // End of for-loop
	TEST_ASSERT(3 == s_pLinkedList->m_ulNumOfNode);

	for (int i = 3; i >= 1; i--) {
		LinkedList_removeNodeFront(s_pLinkedList);
		TEST_ASSERT((size_t)i - 1 == s_pLinkedList->m_ulNumOfNode);
	} // End of for-loop

	TEST_ASSERT(0 == s_pLinkedList->m_ulNumOfNode);
} // End of test_LinkedList_removeNodeFront

int main(int argc, char** argv) {
	UnityBegin("./test_LinkedList.c");

	RUN_TEST(test_LinkedList_new);

	RUN_TEST(test_LinkedList_addNodeFront_Null);
	RUN_TEST(test_LinkedList_addNodeFront_ZeroDataSize);
	RUN_TEST(test_LinkedList_addNodeFront_RealData);

	RUN_TEST(test_LinkedList_popNodeFront_Null);
	RUN_TEST(test_LinkedList_popNodeFront_RealData);

	RUN_TEST(test_LinkedList_removeNodeFront);

	return UnityEnd();
} // End of main
