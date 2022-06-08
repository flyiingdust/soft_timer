
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
 * @file  main.c
 * @brief soft-timer test file.
 *        One oneshot timer is started with timerout value 500ms
 *        Three repeat timer are started with repeat time 1000ms.  At the the 5th cycle of the repeat, remove the timer at the middle.
 */

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "../src/soft_timer.h"


/*******************************************************************************
 *    MICRO DEFINITIONS
 ******************************************************************************/
#define REPEAT_TIME 1000 /* ms */
#define ONESHOT_TIME 500

/*******************************************************************************
 *    STATIC FUNCTION DECLARATIONS
 ******************************************************************************/
static void timer_cb(soft_timer_t* p_timer);


/*******************************************************************************
 *    STATIC VARIABLE DEFINITIONS
 ******************************************************************************/
static soft_timer_t s_soft_timer[3];
static soft_timer_t s_oneshot_timer;
static uint32_t s_time;

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
 * @brief get the time counted in ms, range [0, 60 000] ms
 * @param[in] void
 * @return time
 */
uint32_t get_time_with_ms(void)
{
    uint32_t ms;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    ms = ((tv.tv_sec%60) *1000) + (tv.tv_usec/1000);

}


/* definition of the callback function */
static void timer_cb(soft_timer_t* p_timer)
{
    if(p_timer == &s_soft_timer[0])
    {
        printf("timer_0 is called, %d\n", get_time_with_ms());
    }
    else if(p_timer == &s_soft_timer[1])
    {
        static uint8_t s_stop_count;
        s_stop_count++;
        if(s_stop_count >= 5)
        {
            /* delete the timer at the middle postion */
            soft_timer_stop(p_timer);
            printf("timer_1 is stopped\n");
        }
        else
        {
            printf("timer_1 is called \n");
        }
    }
    else if(p_timer == &s_soft_timer[2])
    {
        printf("timer_2 is called \n\n");
    }
    else if(p_timer == &s_oneshot_timer)
    {
        printf("oneshot timer is called\n\n");
    }
    else
    {

    }

}



int main()
{
    /* init timers */
    soft_timer_init(&s_soft_timer[0], SOFT_TIMER_MODE_REPEAT, REPEAT_TIME, timer_cb);
    soft_timer_init(&s_soft_timer[1], SOFT_TIMER_MODE_REPEAT, REPEAT_TIME, timer_cb);
    soft_timer_init(&s_soft_timer[2], SOFT_TIMER_MODE_REPEAT, REPEAT_TIME, timer_cb);
    /*start timer */
    soft_timer_start(&s_soft_timer[0]);
    soft_timer_start(&s_soft_timer[1]);
    soft_timer_start(&s_soft_timer[2]);

    soft_timer_init(&s_oneshot_timer, SOFT_TIMER_MODE_ONESHOT, ONESHOT_TIME, timer_cb);
    soft_timer_start(&s_oneshot_timer);

    while (1)
    {
        /* usleep is not accurate, */
        usleep(10000);
        soft_timer_manager(10);
    }

    return 0;
}

