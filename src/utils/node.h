#ifndef UTILS_NODE_H
#define UTILS_NODE_H

/**
 * @brief This struct can represent a node for the linked list.
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

#endif // End of UTILS_NODE_H
