/**
 * MIT License
 *
 * Copyright (c) 2022 flying dust
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.

/**
 * @file  slist.h
 * @brief singly linked list implemetation, include add, delete, query
 */
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "basic_types.h"

/*******************************************************************************
 *    MICRO DEFINITIONS
 ******************************************************************************/


/*******************************************************************************
 *    TYPEDEF TYPES
 ******************************************************************************/


typedef struct linked_list_element_struct
{
    struct linked_list_element_struct * next;
}linked_list_element_t;

typedef struct linked_list_struct
{
    linked_list_element_t * head; /**< head position is the most important attribute of the list */
}linked_list_t ;



/*******************************************************************************
 *    CONSTANT VARIABLE DECLARATIONS
 ******************************************************************************/


/*******************************************************************************
 *    GLOBAL VARIABLE DECLARATIONS
 ******************************************************************************/


/*******************************************************************************
 *    GLOBAL FUNCTION DECLARATIONS
 ******************************************************************************/
/**
 * @brief query if an element is in the list
 * @param[in] p_list pointer to the list stuct, which contain its head position
 * @param[in] p_element pointer to the element to be queried
 * @return TRUE  - the element is in the list
 *         FALSE - the element is not in the list
 */
extern uint8_t linked_list_is_element_in_list(linked_list_t * p_list, linked_list_element_t * p_element);

/**
 * @brief add element to the head of the list
 * @param[in] p_list pointer to the list stuct, which contain its head position
 * @param[in] p_element pointer to the element to be added
 * @return void
 */
extern void linked_list_add_element_at_head(linked_list_t * p_list, linked_list_element_t *p_element);

/**
 * @brief add element to the tail of the list
 * @param[in] p_list pointer to the list stuct, which contain its head position
 * @param[in] p_element pointer to the element to be added
 * @return void
 */
extern void linked_list_add_element_at_tail(linked_list_t * p_list, linked_list_element_t *p_element);

/**
 * @brief delete element in the list
 * @param[in] p_list pointer to the list stuct, which contain its head position
 * @param[in] p_element pointer to the element to be deleted
 * @return void
 */
extern void linked_list_delete_element(linked_list_t * p_list, linked_list_element_t *p_element);

#ifdef __cplusplus
}
#endif

#endif
