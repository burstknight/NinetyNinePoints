#include "unity.h"
#include "unity_internals.h"
#include "utils/node.h"
#include <string.h>

static Node_s* pNode = NULL;

void setUp() {
	pNode = NULL;
} // End of setUp

void tearDown() {
	Node_release(pNode);
	pNode = NULL;
} // End of tearDown

/**
 * @brief Test the case for giving NULL data.
 *
 * This function will test the case that tries to create a node wihout data.
 */
void test_Node_NullData(void) {
	pNode = Node_new(NULL, 0);

	TEST_ASSERT_NOT_NULL(pNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pPreNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pNextNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pData);
	TEST_ASSERT_EQUAL(0, pNode->m_ulSizeOfData);
} // End of test_Node_NullData

/**
 * @brief Test the case for giving zero data size.
 */
void test_Node_ZeroDataSize(void) {
	int iData = 9;
	pNode = Node_new(&iData, 0);

	TEST_ASSERT_NOT_NULL(pNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pPreNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pNextNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pData);
	TEST_ASSERT_EQUAL(0, pNode->m_ulSizeOfData);
} // End of test_Node_ZeroDataSize

void test_Node_setData(void) {
	int iData = 25;
	pNode = Node_new(NULL, 0);

	TEST_ASSERT_NOT_NULL(pNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pPreNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pNextNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pData);

	TEST_ASSERT(sizeof(int) == Node_setData(pNode, &iData, sizeof(int)));
	TEST_ASSERT(iData == *((int*)pNode->m_pData));
	TEST_ASSERT(&iData != (int*)pNode->m_pData);
} // End of test_Node_setData

/**
 * @brief Test the case for giving int data.
 */
void test_Node_Int(void) {
	int iData = 9;
	pNode = Node_new(&iData, sizeof(int));

	TEST_ASSERT_NOT_NULL(pNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pPreNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pNextNode);
	TEST_ASSERT_EQUAL(iData, *((int*)pNode->m_pData));
	TEST_ASSERT(&iData != (int*)pNode->m_pData);
} // End of test_Node_Int

/**
 * @brief Test the case for giving float data.
 */
void test_Node_Float(void) {
	float fData = 4.3;
	pNode = Node_new(&fData, sizeof(float));

	TEST_ASSERT_NOT_NULL(pNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pPreNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pNextNode);
	TEST_ASSERT_EQUAL_FLOAT(fData, *((float*)pNode->m_pData));
	TEST_ASSERT(&fData != (float*)pNode->m_pData);
} // End of test_Node_Float

/**
 * @brief Test the case for giving string data.
 */
void test_Node_String(void) {
	char* pcString = "Hello world!";
	pNode = Node_new(pcString, strlen(pcString) + 1);

	TEST_ASSERT_NOT_NULL(pNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pPreNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pNextNode);
	TEST_ASSERT(0 == strcmp(pcString, (char*)pNode->m_pData));
	TEST_ASSERT(pcString != (char*)pNode->m_pData);
} // End of test_Node_String

/**
 * @brief Test the case for giving struct.
 */
void test_Node_Struct(void) {
	typedef struct TestData_s TestData_s;
	struct TestData_s {
		int m_iId;
		float m_fData;
	};

	TestData_s oData = { .m_iId = 9, .m_fData = 3.4 };
	pNode = Node_new(&oData, sizeof(TestData_s));

	TEST_ASSERT_NOT_NULL(pNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pPreNode);
	TEST_ASSERT_EQUAL_PTR(NULL, pNode->m_pNextNode);
	TEST_ASSERT(&oData != (TestData_s*)pNode->m_pData);
	TEST_ASSERT(((TestData_s*)pNode->m_pData)->m_iId == oData.m_iId);
	TEST_ASSERT_EQUAL_FLOAT(oData.m_fData, ((TestData_s*)pNode->m_pData)->m_fData);
} // End of test_Node_Struct

int main(int argc, char** argv) {
	UnityBegin("./test_node.c");

	RUN_TEST(test_Node_NullData);
	RUN_TEST(test_Node_ZeroDataSize);
	RUN_TEST(test_Node_setData);
	RUN_TEST(test_Node_Int);
	RUN_TEST(test_Node_Float);
	RUN_TEST(test_Node_String);
	RUN_TEST(test_Node_Struct);

	return UnityEnd();
} // End of main
