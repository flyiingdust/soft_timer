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
 * @file  soft_timer.c
 * @brief soft_timer
 */

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "soft_timer.h"
#include "linked_list.h"


/*******************************************************************************
 *    MICRO DEFINITIONS
 ******************************************************************************/
static linked_list_t s_soft_timer_list;
static uint32_t s_soft_timer_time = 0 ; /**< counted by ms */

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
 * @brief initialize the soft timer
 * @param[in,out] p_timer timer to be initialized
 * @param[in] mode oneshot or repeated
 * @param[in] timeout the time of one cycle
 * @param[in] cb callback when timeout
 * @return void
 */
void soft_timer_init(soft_timer_t *p_timer, soft_timer_mode_e mode, uint32_t timeout, soft_timer_cb_t cb)
{
    if(p_timer)
    {
        p_timer->mode = mode;
        p_timer->timeout = timeout;
        p_timer->cb = cb;
    }
}

/**
 * @brief start the soft timer
 * @param[in] p_timer timer to be started
 * @return void
 */
void soft_timer_start(soft_timer_t * p_timer)
{
    if(p_timer)
    {
        p_timer->start_time = s_soft_timer_time;
        linked_list_add_element_at_tail(&s_soft_timer_list, &p_timer->element);
    }
}

/**
 * @brief stop the soft timer
 * @param[in] p_timer timer to be stopped
 * @return void
 */
void soft_timer_stop(soft_timer_t * p_timer)
{
    if(p_timer)
    {
        linked_list_delete_element(&s_soft_timer_list, &p_timer->element);
    }
}

/**
 * @brief soft timer manager drived by the timebase
 * @param[in] timebase
 * @return void
 */
void soft_timer_manager(uint32_t timebase)
{
    linked_list_element_t * it = s_soft_timer_list.head;
    soft_timer_t * p_timer;
    uint32_t gap;
    uint32_t cur_time;

    s_soft_timer_time += timebase;
    cur_time = s_soft_timer_time;

    while(it != NULL)
    {
        /* cast to timer instance */
        p_timer  = (soft_timer_t * )it;
        /* as the list has been used to get a timer and the current element may be removed from
        the list, move to next element */
        it = it->next;

        gap = TIME_PASSED(s_soft_timer_time, p_timer->start_time);
        if(gap >= p_timer->timeout)
        {
            p_timer->start_time = cur_time;

            /* oneshot timer should be stopped */
            if(p_timer->mode == SOFT_TIMER_MODE_ONESHOT)
            {
                soft_timer_stop(p_timer);
            }
            /* call the callback when it is valid */
            if(p_timer->cb != NULL)
            {
                p_timer->cb(p_timer);
            }
        }

    }

}
