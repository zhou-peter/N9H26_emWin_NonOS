/**************************************************************************//**
 * @file     N9H26_SPI_SecureIC.h
 * @version  V3.00
 * @brief    N9H26 series SPI Securic driver header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include "wblib.h"
unsigned int RPMC_ReadCounterData(void);
unsigned int RPMC_ReadRPMCstatus(unsigned int checkall);
unsigned int RPMC_WrRootKey(unsigned int cadr,unsigned char *rootkey);
unsigned int RPMC_UpHMACkey(unsigned int cadr,unsigned char *rootkey,unsigned char *hmac4,unsigned char *hmackey);
unsigned int RPMC_IncCounter(unsigned int cadr,unsigned char *hmackey,unsigned char *input_tag);
unsigned char RPMC_Challenge(unsigned int cadr,unsigned char *hmackey,unsigned char *input_tag);
void RPMC_ReqCounter(unsigned int cadr, unsigned char *hmackey,unsigned char *tag);
INT32 RPMC_ReadJEDECID(PUINT8 data);
INT16 RPMC_ReadUID(PUINT8 data);


