#ifndef LEON3_TYPES_H
#define	LEON3_TYPES_H

#ifndef NULL
	#define NULL 0
#endif
#ifndef __cplusplus
	typedef unsigned char bool_t;
#define true 1
#define false 0
#endif

typedef unsigned char			byte_t;
typedef unsigned short int		word16_t;
typedef unsigned int 			word32_t;
typedef unsigned long int 		word64_t;
typedef signed char				int8_t;
typedef signed short int 		int16_t;
typedef signed int 				int32_t;
typedef signed long int 		int64_t;
typedef unsigned char 			uint8_t;
typedef unsigned short int 		uint16_t;
typedef unsigned int 			uint32_t;
typedef unsigned long int 		uint64_t;

#endif

