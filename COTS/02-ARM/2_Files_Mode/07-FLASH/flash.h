/**********************************************************************************************
Author :Mohamed Ibrahem, Mahmoud Gamal
Version:1.0
Date:20 May 2020
Description:This Header file is used to interface with the FLASH module in STM32f10x evaluation kit
***********************************************************************************************/
#ifndef FLASH_INTERFACE_H
#define FLASH_INTERFACE_H

#define FLASH_LOCKED				6

void FLASH_unlockRegisters(void);
void FLASH_lockRegisters(void);

ErrorStatus FLASH_eraseSection(u16* startAddress);
void FLASH_eraseFlash(void);

ErrorStatus FLASH_writeHalfWord(u16* destinationAddress, u16* sourceAddress);
ErrorStatus FLASH_writeData(u16* destinationAddress, u16* sourceAddress, u16 size);
ErrorStatus FLASH_writeDataStaticSource(u16* destinationAddress, u16* sourceAddress, u16 size);



#endif