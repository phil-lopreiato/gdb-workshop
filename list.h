/**
 * Neel Shah
 * nshah95@gwmail.gwu.edu
 */

/**
 * Simple stack based linked list in C with the following functions
 *
 * struct linked_list* ll_create(void) <-- returns a pointer to a linked list,
 *      if can't create, returns NULL
 * void ll_destroy(struct linked_list *ll) <-- deallocates a list
 * void ll_add(struct linked_list *ll, void *value) <-- inserts a value at the
 *      head of the list
 * int ll_length(struct linked_list *ll) <-- returns the total number of values
 *      in the list
 * void* ll_remove_first(struct linked_list *ll) <-- removes and returns value
 *      at head of the list. if the list is empty, it returns NULL
 * int ll_contains(struct linked_list *ll, void *value) <-- searches list and
 *      returns 1 if it is found and 2 if it is not found
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Simple node struct.
 * Contains a data value which is a void* and 
 * it contains a pointer to the next node.
 */
struct node {
    void *data;
    struct node *next;
};

/*
 * Linked list sruct contains a head pointer for the first node.
 */
struct linked_list {
    struct node *head;
};

/*
 * Method creates a linked list and returns the pointer to it.
 */
struct linked_list*
ll_create(void)
{
    struct linked_list *ll = malloc( sizeof(struct linked_list) );
    
    if (ll == NULL) {
	   return NULL;
    }

    ll->head = NULL;
 
    return ll;
}

/*
 * This method frees all nodes in the linked list
 * therefore destroying it.
 */
void
ll_destroy(struct linked_list *ll)
{
    if (ll == NULL || sizeof(ll) != sizeof(struct linked_list)) {
        return 1;
    }
    if (ll->head == NULL){
        return 1;
    } else {
        while (ll->head != NULL){
            struct node *temp;
            temp = ll->head;
            ll->head = temp->next;
            free(temp);
        }
    }
}

/*
 * This method adds values to the linked list in a stack
 * order. So the value to be added gets added to the top
 * of the list. It follows FILO order.
 */
void
ll_add(struct linked_list *ll, void *value)
{
    if (ll == NULL || sizeof(ll) != sizeof(struct linked_list)){
        return NULL;
    }

    struct node *temp = malloc( sizeof(struct node) );
    temp->data = value;
    temp->next = ll->head;
    ll->head = temp;
}

/*
 * This method returns the length of the linked list. 
 * It iterates through it and counts each node.
 */
int
ll_length(struct linked_list *ll)
{
    if (ll == NULL || sizeof(ll) != sizeof(struct linked_list)) {
        return NULL;
    }

    int length;
    struct node *move = ll->head;

    length = 0;

    while (move != NULL) {
        length++;
        move = move->next;
    }

    return length;
}

/*
 * This method frees the first node and before doing so, 
 * it sets the head node's pointer to point to the
 * second node.
 */
void*
ll_remove_first(struct linked_list *ll)
{
    if (ll == NULL || sizeof(ll) != sizeof(struct linked_list)) {
	return NULL;
    } 

    if (ll->head == NULL || ll_length(ll) == 0) {
        return NULL;
    } else {
        void *num = ll->head->data;
        struct node *del = ll->head;

        ll->head = ll->head->next;
        free(del);
      
        return num;
    }
}

/*
 * This iterates through the list and counts each node.
 * Whenever a node containing the value is found, it will
 * return the position that it is in. 
 */
int
ll_contains(struct linked_list *ll, void *value)
{
    if (ll == NULL || sizeof(ll) != sizeof(struct linked_list)) {
        return NULL;
    }

    int pos;

    struct node *temp = ll->head;
    pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            return pos;
        } else {
            pos++;
	    temp = temp->next;
        }
    }
    return 0;
}
