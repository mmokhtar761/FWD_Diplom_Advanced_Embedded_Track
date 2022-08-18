/******************************************************************************/
/* Author        : Mohamed Mokhtar                                            */
/* Date          : 30 Sep 2021                                                */
/* Version       : V1.1                                                       */
/******************************************************************************/
#ifndef MANIPULATOR_H
#define MANIPULATOR_H
                      /* dealing with only 1 Bit */
#define MAN_BIT(VAR,BIT,_1BIT_VAL)                VAR=((VAR & ~(1<<BIT))|(_1BIT_VAL<<BIT))
#define BIT_H(VAR,BIT)                            VAR|=  (1<<BIT)
#define BIT_L(VAR,BIT)                            VAR&= ~(1<<BIT)
#define GET_BIT(VAR,BIT)                          ((VAR>>BIT)&1)
#define TOG_BIT(VAR,BIT)                          VAR^=  (1<<BIT)
/*Efficient bit handler*/
/*#define BIT_H_W0TOLERANT(VAR,BIT)                 (VAR=(1<<BIT))*/

                     /* dealing with nibble (4 Bit) */
#define MAN_NIBBLE(VAR,START_BIT,_4BIT_VAL)        VAR=((VAR & ~(0xF<<START_BIT))|(_4BIT_VAL<<START_BIT))
#define SET_NIBBLE(VAR,START_BIT)                  VAR|=  (0xF<<START_BIT)
#define CLR_NIBBLE(VAR,START_BIT)                  VAR&= ~(0xF<<START_BIT)
#define GET_NIBBLE(VAR,START_BIT)                  ((VAR&(0XF<<START_BIT))>>START_BIT)
#define TOG_NIBBLE(VAR,START_BIT)        	         VAR^= (0XF<<START_BIT)

                      /* dealing with byte (8 Bit) */
#define MAN_BYTE(VAR,START_BIT,_8BIT_VAL)         (VAR=((VAR & ~(0xFF<<START_BIT))|(_8BIT_VAL<<START_BIT)))
#define SET_BYTE(VAR,START_BIT)                    MAN_BYTE(VAR,START_BIT,0XFF)
#define CLR_BYTE(VAR,START_BIT)                    MAN_BYTE(VAR,START_BIT,0X00)
#define GET_BYTE(VAR,START_BIT)                    ((VAR&(0XFF<<START_BIT))>>START_BIT)
#define TOG_BYTE(VAR,START_BIT)                    MAN_BIT(VAR,START_BIT,~GET_BYTE(VAR,START_BIT))





#endif  /*MANIPULATOR_H end*/
