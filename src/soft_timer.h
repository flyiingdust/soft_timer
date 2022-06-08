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
 * @file  soft_timer.h
 * @brief soft_timer
 */
#ifndef soft_timer_H_
#define soft_timer_H_

#ifdef __cplusplus
extern "C" {
#endif
/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "basic_types.h"
#include "linked_list.h"

/*******************************************************************************
 *    MICRO DEFINITIONS
 ******************************************************************************/


/*******************************************************************************
 *    TYPEDEF TYPES
 ******************************************************************************/
struct soft_timer_struct;

typedef void (*soft_timer_cb_t)(struct soft_timer_struct * p_timer);

typedef enum
{
    SOFT_TIMER_MODE_ONESHOT = 0x00,
    SOFT_TIMER_MODE_REPEAT   = 0x01
}soft_timer_mode_e;

typedef struct soft_timer_struct
{
    linked_list_element_t element;
    uint32_t start_time;
    uint32_t timeout;
    soft_timer_mode_e mode;
    soft_timer_cb_t cb;
}soft_timer_t;

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
 * @brief initialize the soft timer
 * @param[in,out] p_timer timer to be initialized
 * @param[in] mode oneshot or repeated
 * @param[in] timeout the time of one cycle
 * @param[in] cb callback when timeout
 * @return void
 */
extern void soft_timer_init(soft_timer_t *p_timer, soft_timer_mode_e mode, uint32_t timeout, soft_timer_cb_t cb);

/**
 * @brief start the soft timer
 * @param[in] p_timer timer to be started
 * @return void
 */
extern void soft_timer_start(soft_timer_t * p_timer);

/**
 * @brief stop the soft timer
 * @param[in] p_timer timer to be stopped
 * @return void
 */
extern void soft_timer_stop(soft_timer_t * p_timer);

/**
 * @brief soft timer manager drived by the timebase
 * @param[in] timebase
 * @return void
 */
extern void soft_timer_manager(uint32_t timebase);

#ifdef __cplusplus
}
#endif

#endif
