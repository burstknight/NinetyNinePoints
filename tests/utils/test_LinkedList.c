#include "unity.h"
#include "unity_internals.h"
#include "utils/LinkedList.h"
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

int main(int argc, char** argv) {
	UnityBegin("./test_LinkedList.c");

	RUN_TEST(test_LinkedList_new);

	return UnityEnd();
} // End of main
