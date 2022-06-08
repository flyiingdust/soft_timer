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
 * @file  slist.c
 * @brief slist
 */

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "linked_list.h"

/*******************************************************************************
 *    MICRO DEFINITIONS
 ******************************************************************************/


/*******************************************************************************
 *    STATIC FUNCTION DECLARATION
 ******************************************************************************/


/*******************************************************************************
 *    STATIC VARIABLE DEFINITIONS
 ******************************************************************************/


/*******************************************************************************
 *    CONSTANT VARIABLE DEFINITIONS
 ******************************************************************************/


/*******************************************************************************
 *    GLOBAL VARIABLE DEFINITIONS
 ******************************************************************************/


/*******************************************************************************
 *    FUNCTION DEFINITIONS
 ******************************************************************************/

/**
 * @brief query if an element is in the list
 * @param[in] p_list pointer to the list stuct, which contain its head position
 * @param[in] p_element pointer to the element to be queried
 * @return TRUE  - the element is in the list
 *         FALSE - the element is not in the list
 */
uint8_t linked_list_is_element_in_list(linked_list_t * p_list, linked_list_element_t * p_element)
{
    uint8_t status  = FALSE;
    linked_list_element_t * it = p_list->head;

    while(it != NULL)
    {
        if(it == p_element)
        {
            status = TRUE;
            break;
        }
        else
        {
            it = it->next;
        }
    }

    return status;
}

/**
 * @brief add element to the head of the list
 * @param[in] p_list pointer to the list stuct, which contain its head position
 * @param[in] p_element pointer to the element to be added
 * @return void
 */
void linked_list_add_element_at_head(linked_list_t * p_list, linked_list_element_t *p_element)
{
    if((p_element == NULL)|| (linked_list_is_element_in_list(p_list, p_element) == TRUE))
    {
        return;
    }

    p_element->next = p_list->head;
    p_list->head = p_element;
}

/**
 * @brief add element to the tail of the list
 * @param[in] p_list pointer to the list stuct, which contain its head position
 * @param[in] p_element pointer to the element to be added
 * @return void
 */
void linked_list_add_element_at_tail(linked_list_t * p_list, linked_list_element_t *p_element)
{
    linked_list_element_t * it = p_list->head; /* it means iterator */

    if((p_element == NULL)|| (linked_list_is_element_in_list(p_list, p_element) == TRUE))
    {
        return;
    }

    if(p_list->head == NULL)
    {
        p_list->head = p_element;
    }
    else
    {
        while(it->next != NULL)
        {
            it = it->next;
        }
        it->next = p_element;
    }

    p_element->next = NULL;
}

/**
 * @brief delete element in the list
 * @param[in] p_list pointer to the list stuct, which contain its head position
 * @param[in] p_element pointer to the element to be deleted
 * @return void
 */
void linked_list_delete_element(linked_list_t * p_list, linked_list_element_t *p_element)
{
    linked_list_element_t * it = p_list->head; /* it means iterator */

    if(p_element == NULL)
    {
        return;
    }

    if(p_list->head == p_element)
    {
        p_list->head = p_element->next;
    }
    else
    {
        while((it != NULL) && (it->next != p_element))
        {
            it = it->next;
        }

        if(it != NULL)
        {
            it->next = p_element->next;
        }
    }
}


