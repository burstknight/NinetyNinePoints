#ifndef UTILS_NODE_H
#define UTILS_NODE_H

#include <stddef.h>

/**
 * @brief This struct can represent a node for the linked list.
 *
 * @see Node_new
 * @see Node_release
 * @see Node_setData
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
	 * @brief This field can store the size of the data.
	 */
	size_t m_ulSizeOfData;

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
 * data of the field m_pData before calling this function. Also, if you need copy the data of the node,
 * you can call the function Node_cloneData() before calling this function.
 *
 * @param pNode Give the point of the instance to release.
 *
 * @see Node_cloneData
 */
void Node_release(Node_s* pNode);

/**
 * @brief Copy the given data into the node.
 *
 * This function can copy the given data into this node. If you want to change the data for a node,
 * you should call this function.
 *
 * @param pNode Give the node to set the data.
 * @param pNewData Give the new data to copy into the node.
 * @param ulSize Give the size of the new data.
 *
 * @return Return the size of the new data if this function succeeds to set data of the node. Otherwise, this function will return zero.
 */
size_t Node_setData(Node_s* pNode, void* pNewData, size_t ulSize);

/**
 * @brief Clone the data of the node.
 *
 * This function can clone the data of the node. Note, if you don't want to use the cloned data,
 * you have to call the function free() to release the cloned data.
 *
 * @param pNode Give the node to clone the data.
 *
 * @return Return the point the cloned data if this function succeeds to clone the data from the given node. Otherwise, this function will retun NULL.
 */
void* Node_cloneData(Node_s* pNode);

#endif // End of UTILS_NODE_H
