/*************************************************/
/*  Title        : DIO peripheral BIT MATH file */
/*  Auther       : Ahmed Mohey Eldeen            */
/*  Release      : 1.0                           */
/*  Last Update  : Aug 15, 2021                  */
/*************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Var,BitNo)    (Var) = ( (Var) | (1 << BitNo) )
#define CLEAR_BIT(Var,BitNo)  (Var) = ( (Var) & ~(1 << BitNo) )
#define GET_BIT(Var,BitNo)   ((Var >> BitNo) & 0x01)
#define CONC_BIT(A7,A6,A5,A4,A3,A2,A1,A0)    CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)
#define CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)   0b##A7##A6##A5##A4##A3##A2##A1##A0
#define TOGGLE_BIT(Var,BitNo) (Var) = (Var) ^ (1<<(BitNo))
#define SET_BYTE(Var) Var = 0xFF
#define CLEAR_BYTE(Var) Var = 0x00
#define SET_NIBBLE_LOW(Var) Var = Var | 0x0F
#define SET_NIBBLE_HIGH(Var) Var = Var | 0xF0
#define CLEAR_NIBBLE_LOW(Var) Var = (Var & (0xF0))
#define CLEAR_NIBBLE_HIGH(Var) Var = (Var & (0x0F))

#endif
