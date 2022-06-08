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
 * @file  basic_types.h
 * @brief basic_types
 */
#ifndef BASIC_TYPES_H_
#define BASIC_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include "stdint.h"

/*******************************************************************************
 *    MICRO DEFINITIONS
 ******************************************************************************/
#ifndef TRUE
    #define TRUE 1u
#endif

#ifndef FALSE
    #define FALSE 0u
#endif

#ifndef NULL
    #define NULL ((void *) 0)
#endif

#ifndef ARRAY_SIZE
    #define ARRAY_LENGTH(a) (sizeof(a) / sizeof(a[0]))
#endif

#ifndef MAX
    #define MAX(a, b) ((a) > (b)) ? (a) : (b)
#endif

#ifndef MIN
    #define MIN(a, b) ((a) > (b)) ? (b) : (a)
#endif


#define TIME_MAX 0xFFFFFFFFu
#define TIME_PASSED(now, since) ((now) >= (since)) ? ((now) -(since)) : ((now) + (1 + TIME_MAX - (since)))




/*******************************************************************************
 *    TYPEDEF TYPES
 ******************************************************************************/



/*******************************************************************************
 *    CONSTANT VARIABLE DECLARATIONS
 ******************************************************************************/


/*******************************************************************************
 *    GLOBAL VARIABLE DECLARATIONS
 ******************************************************************************/


/*******************************************************************************
 *    GLOBAL FUNCTION DECLARATIONS
 ******************************************************************************/


#ifdef __cplusplus
}
#endif

#endif
