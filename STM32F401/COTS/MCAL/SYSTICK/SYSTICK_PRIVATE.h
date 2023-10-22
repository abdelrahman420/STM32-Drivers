#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define SYSTICK_BASE_ADDRESS     0xE000E010


typedef struct
{

	volatile   u32     CTRL  ;
	volatile   u32     LOAD  ;
	volatile   u32     Val   ;
	volatile   u32     CALIB ;

}SYSTICK_MemMap_t;


#define SYSTICK       ((volatile SYSTICK_MemMap_t* )SYSTICK_BASE_ADDRESS)

#endif