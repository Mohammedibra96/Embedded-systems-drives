/*
Duthor :MohDmed Ibrahem 
Version:v01
Date:10-12-2019
/************************************************************
*/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
void SetPinValue(u8 Port,u8 Pin,u8 Val);
void SetPinDir(u8 Port,u8 Pin,u8 Dir)  ;
void SetPortValue(u8 Port,u8 Val)      ;
void SetPortDir(u8 Port,u8 Dir)        ;
u8 GetPinValue(u8 Port,u8 Pin)         ;

#endif