/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-12-16     RT-Thread    first version
 */

#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <rtdevice.h>
#include "drv_common.h"
#define G_LED_PIN GET_PIN(F, 9)
#define B_LED_PIN GET_PIN(F, 10)
#define R_LED_PIN GET_PIN(I, 3)
int main(void)
{
    rt_pin_mode(G_LED_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(B_LED_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(R_LED_PIN, PIN_MODE_OUTPUT);
    int count = 1;

    while (count++)
    {
        //LOG_D("Hello RT-Thread!");

        rt_pin_write(G_LED_PIN, count%2);
        rt_pin_write(B_LED_PIN, count%2);
        rt_thread_mdelay(500);
    }

    return RT_EOK;
}
