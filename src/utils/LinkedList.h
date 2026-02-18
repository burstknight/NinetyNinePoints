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

/**
 * @brief Create an instance of the struct LinkedList_s.
 *
 * This function can create an instance of the struct LinkedList_s, and then return the point of the
 * instance.
 *
 * @return Return the point of an instance of the struct LinkedList_s.
 */
LinkedList_s* LinkedList_new();

/**
 * @brief Release a given instance of the struct LinkedList_s.
 *
 * This function can clear all nodes of the given linked list, and then release the given linked
 * list. If you don't want to the linked list yet, you should call this function to release the
 * resource of the linked list.
 *
 * @param pLinkedList Give the instance of the linked list to release the resource.
 */
void LinkedList_release(LinkedList_s* pLinkedList);

/**
 * @brief Add a node at the front of the linked list.
 *
 * This function can create a node to store the given data, and then add the node at the front for
 * the linked list. Note, you also can give NULL as the data to add a node at the front unless what
 * you want to do. Otherwise, you shouldn't give NULL as the data. This function will create a node
 * that contains NULL as the data if you really give NULL as the data for the node.
 *
 * @param pLinkedList Give the point of the linked list to add a node at the front.
 * @param pData Give a data to add the node at the front.
 * @param ulSizeOfData Give the size of the given data.
 *
 * @return 0 Return this value if this function succeeds to add a new node at the front for the linked list.
 * @return 1 Return this value if this function succeeds to add a new node at the front for the linked list. However, the new node has no data.
 * @return -1 Return this value if this function fails to add a new node. The reason of this error is to give NULL for the parameter pLinkedList or fail to allocate the memory space for the new node.
 */
int LinkedList_addNodeFront(LinkedList_s* pLinkedList, void* pData, size_t ulSizeOfData);

/**
 * @brief Add a node at the rear for the linked list.
 *
 * This function can create a node to store the given data, and then add it at the rear for the
 * linked list. Note, you also can give NULL as the data to add a node at the rear unless what you
 * want to do. Otherwise, you shouldn't give NULL as the data. This function will create a node
 * that contains NULL as teh data if you really give NULL as the data for the node.
 *
 * @param pLinkedList Give the point of the linked list to add a node at the rear.
 * @param pData Give a data to add the node at the rear.
 * @param ulSizeOfData Give the size of the given data.
 *
 * @return 0 Return this value if this function succeeds to add a new node at the rear for the linked list.
 * @return 1 Return this value if this function succeeds to add a new node at the rear for the linked list. However, the new node has no data.
 * @return -1 Return this value if this function fails to add a new node. The reason of this error is to give NULL for the parameter pLinkedList or fail to allocate the memory space for the new node.
 */
int LinkedList_addNodeRear(LinkedList_s* pLinkedList, void* pData, size_t ulSizeOfData);

/**
 * @brief Pop the node at the front from the linked list.
 *
 * This function can pop the node at the front from the linked list.
 *
 * @param pLinkedList Give the linked list to pop the node at the front.
 *
 * @return Return the point of the node at the front if the given linked list isn't empty. Otherwise, this function will return NULL.
 */
Node_s* LinkedList_popNodeFront(LinkedList_s* pLinkedList);

/**
 * @brief Pop the node at the rear of the linked list.
 *
 * This function can pop the node at the rear of the linked list.
 *
 * @param pLinkedList Give the linked list to pop the node at the rear.
 *
 * @return Return the point of the popped node at the rear from the given linked list if the given linked list isn't empty. Otherwise, this function will return NULL.
 */
Node_s* LinkedList_popNodeRear(LinkedList_s* pLinkedList);

/**
 * @brief Remove the node at the front for the linked list.
 *
 * This function can remove the node at the front for the given linked list.
 *
 * @param pLinkedList Give the linked list to remove the node at the front.
 */
void LinkedList_removeNodeFront(LinkedList_s* pLinkedList);

/**
 * @brief Clear all nodes for the given linked list.
 *
 * This function can clear all nodes for the given linked list.
 *
 * @param pLinkedList Give the linked list to clear all nodes.
 */
void LinkedList_clearAllNodes(LinkedList_s* pLinkedList);

/**
 * @brief Clone each element of the given array to the linked list.
 *
 * This function can clone each element of the given array to the linked list.
 *
 * @param pLinkedList Give the linked list to clone the datum from the given array.
 * @param pData Give the array to clone datum to the linked list.
 * @param ulSizeOfData Give the size of each element for the given array.
 * @param ulLength Give the length of the given array.
 *
 * @return 0 Return this value if this function succeeds to clone the datum of the given array to the linked list.
 * @return 1 Return this value if the linked list is NULL.
 * @return -1 Return this value if this function fails to clone the datum of the given array to the linked list.
 */
int LinkedList_cloneFromArray(LinkedList_s* pLinkedList, void* pData, size_t ulSizeOfData, size_t ulLength);

#endif // End of UTILS_LINKEDLIST_H
