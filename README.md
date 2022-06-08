# 软件定时器说明  



## 1. 背景

前后台程序中没有如RTOS中的软件定时器支持。为避免定时器代码与应用代码混杂到一起，将定时器功能独立实现

参考了以下三个资源

* [AtmelASF  hal_timer.c](https://onlinedocs.microchip.com/pr/GUID-2A8AADED-413E-4021-AF0C-D99E61B8160D-en-US-4/index.html?GUID-E2199A86-03E7-4269-B532-372B3F8307D8)  可以通过[Atmel Start](https://start.atmel.com/) 生成这部分参考代码
* [MultiTimer](https://github.com/0x1abin/MultiTimer) 作者0x1abin已将代码升至V2版本，增加了对定时器定时时间排序功能
* 《嵌入式系统设计与实践》Elecia White著 5.4.4  一个极小型调度器 p138



## 2. 实现原理

* 使用链表连接每个定时器

* 只有链表中的定时器才进行检测运行。'"在链表中这个属性表达了定时器正在运行的信息，不用另外再设标志

* 每个定时器由使用者编码时分配静态空间，至少有两个好处

  * 不在空间有限的芯片上使用malloc，避免引起内存碎片问题

  * 定时器模块仅提供了运行功能，不用考虑定时器资源问题

    

## 3. 使用说明

```c
#include "soft_timer.h"

#define REPEAT_TIME 500 /* ms */

/* 定义软件定时器实例 */
static soft_timer_t s_example_timer;

/* 定义定时器回调 */
static void timer_cb(soft_timer_t * p_timer)
{
    ; 
}

/* 在任务初始化 */
void example_5ms_task_init(void)
{
    soft_timer_init(&s_example_timer, SOFT_TIMER_MODE_REPEAT, REPEAT_TIME, timer_cb);
    soft_timer_start(&s_example_timer);
}

/* 周期调用定时管理器 */
void example_5ms_task(void)
{
    soft_timer_manager(5);
}

```



## 4. 示例说明

示例中在ubuntu中运行，使用usleep提供10ms 时间基准给定时器模块，但是通用操作系统的在ms级别的时间不准确。

1. 安装依赖

```c
sudo apt install gcc g++
```

2. 运行程序

```shell
cd ./examples
make
./test
```

3. 清除数据

```shell
make clean
```







---------------------------

# Soft-Timer Specification

## 1. Backgound

There is no soft-timer in Bare metal system like that in RTOS. The lack of the soft-timer make the soft-timer codes mixed with application codes, which leads a chaos in the program. To avoid this , an independent soft-timer module is necessary.

Three resources are refered to:

* [Atmel ASF hal_timer.c](https://onlinedocs.microchip.com/pr/GUID-2A8AADED-413E-4021-AF0C-D99E61B8160D-en-US-4/index.html?GUID-E2199A86-03E7-4269-B532-372B3F8307D8) the hal_code can be generated by [Atmel Start](https://start.atmel.com/)
* [MultiTimer](https://github.com/0x1abin/MultiTimer) the author 0x1abin has updated the code to version V2, which adds the feature of timer sorted by it timeout value
* 《Making Embedded Systems》by  *Elecia White* 5.4.4
* 

## 2. How it work

* Singly linked list is used to link every soft-timer
* Only the timer in the list can run. The attribute 'in the list' provide the information that the timer is active, so no more flag is eeded.
* The static memory of timer is allocated by the user when code, it provides at least 2 benefits
  * malloc is not used on the embedded chip, avoid the possibility of memory fragmentation
  * soft-timer module only provides the functions and no need to consider the resource limitation.



## 3. How to use



```c
#include "soft_timer.h"

#define REPEAT_TIME 500 /* ms */

/* definition of the soft-timer */
static soft_timer_t s_example_timer;

/* definition of the callback function */
static void timer_cb(soft_timer_t * p_timer)
{
    ; 
}

/* init */
void example_5ms_task_init(void)
{
    soft_timer_init(&s_example_timer, SOFT_TIMER_MODE_REPEAT, REPEAT_TIME, timer_cb);
    soft_timer_start(&s_example_timer);
}

/* periodic call */
void example_5ms_task(void)
{
    soft_timer_manager(5);
}

```



## 4. Run the demo

The demo is run in ubuntu and using the **usleep** function to provide a timebase of 10ms. But the timebase is not accurate in general purpose OS.

1. dependency

```c
sudo apt install gcc g++
```

2. run

```shell
cd ./examples
make
./test
```

3. clean

```shell
make clean
```





### 版本记录 Version 

#### v0.0.1

1. add soft-timer and demo.
