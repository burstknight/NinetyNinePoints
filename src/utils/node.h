#ifndef UTILS_NODE_H
#define UTILS_NODE_H

#include <stddef.h>

/**
 * @brief This struct can represent a node for the linked list.
 *
 * @see Node_new
 */
typedef struct Node_s Node_s;
struct Node_s {
	/**
	 * @brief This field can point to the previous node in a linked list.
	 */
	Node_s* m_pPreNode;

	/**
	 * @brief This filed can store a data.
	 */
	void* m_pData;

	/**
	 * @brief This field can point the the next node in a linked list.
	 */
	Node_s* m_pNextNode;
};

/**
 * @brief Create an instance of the struct Node_s.
 *
 * This function can create an instance of the struct Node_s, and then return the point of the
 * instance.
 *
 * @param pData: Give a data to store into this node. You also give NULL if you know what you do, and then this function will set the field m_pData to NULL.
 * @param ulSize Give the size of the given data. Note, if you give zero, this function will have to set the field m_pData to NULL no matter what the parameter pData is NULL or not.
 *
 * @return Return an instance of the struct Node_s.
 */
Node_s* Node_new(void* pData, size_t ulSize);

/**
 * @brief Release the given instance of the struct Node_s.
 *
 * This function can release a given instance of the struct Node_s if you don't use the instance.
 * Note, if you want to use the data of the field m_pData of the struct Node_s, you should copy the
 * data of the field m_pData before calling this function.
 *
 * @param pNode Give the point of the instance to release.
 */
void Node_release(Node_s* pNode);

#endif // End of UTILS_NODE_H
