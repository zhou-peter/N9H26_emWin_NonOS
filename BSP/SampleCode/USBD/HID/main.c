/**************************************************************************//**
 * @file     main.c
 * @brief    Demo how to use USB Device & HID driver to implement HID Device
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "N9H26.h"
#include "HID.h"

int main(void)
{
    WB_UART_T uart;
    UINT32 u32ExtFreq;
    sysUartPort(1);
    u32ExtFreq = sysGetExternalClock();        /* Hz unit */
    uart.uiFreq = u32ExtFreq;
    uart.uiBaudrate = 115200;
    uart.uiDataBits = WB_DATA_BITS_8;
    uart.uart_no=WB_UART_1;
    uart.uiStopBits = WB_STOP_BITS_1;
    uart.uiParity = WB_PARITY_NONE;
    uart.uiRxTriggerLevel = LEVEL_1_BYTE;
    sysInitializeUART(&uart);

    sysprintf("Sample code Start\n");

#ifdef HID_KEYPAD
	kpi_init();
	kpi_open(3); // use nIRQ0 as external interrupt source
#endif
    /* Enable USB */
    udcOpen();
    hidInit();
    udcInit();
    while(1)
    {
#ifdef HID_KEYBOARD
        HID_SetInReport();
#endif
#ifdef HID_MOUSE
        HID_UpdateMouseData();
#endif
    };
}

