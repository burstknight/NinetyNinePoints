#ifndef UTILS_LINKEDLIST_H
#define UTILS_LINKEDLIST_H

#include "utils/node.h"
#include <stddef.h>

/**
 * @brief This struct can represent a linked list.
 */
typedef struct LinkedList_s LinkedList_s;
struct LinkedList_s {
	/**
	 * @brief This field can store the head node of the linked list.
	 */
	Node_s* m_pHeadNode;

	/**
	 * @brief This field can store the tail node of the linked list.
	 */
	Node_s* m_pTailNode;

	/**
	 * @brief This field can store the number of the node for the linked list.
	 */
	size_t m_ulNumOfNode;
};

#endif // End of UTILS_LINKEDLIST_H
