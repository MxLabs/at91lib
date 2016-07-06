/* Standard definitions of Mode bits and Interrupt (I & F) flags in PSRs */
.equ	Mode_USR,			0x10
.equ	Mode_FIQ,			0x11
.equ	Mode_IRQ,			0x12
.equ	Mode_SVC,			0x13
.equ	Mode_ABT,			0x17
.equ	Mode_UND,			0x1B
.equ	Mode_SYS,			0x1F

.equ	I_Bit,				0x80            // when I bit is set, IRQ is disabled
.equ	F_Bit,				0x40            // when F bit is set, FIQ is disabled

/* Internal Memory Base Addresses */
.equ	FLASH_BASE,			0x00100000
.equ	RAM_BASE,			0x00200000

/*
// <h> Stack Configuration (Stack Sizes in Bytes)
//   <o0> Undefined Mode      <0x0-0xFFFFFFFF:8>
//   <o1> Supervisor Mode     <0x0-0xFFFFFFFF:8>
//   <o2> Abort Mode          <0x0-0xFFFFFFFF:8>
//   <o3> Fast Interrupt Mode <0x0-0xFFFFFFFF:8>
//   <o4> Interrupt Mode      <0x0-0xFFFFFFFF:8>
//   <o5> User/System Mode    <0x0-0xFFFFFFFF:8>
// </h>
*/
.equ	UND_Stack_Size,		0x00000000
.equ	SVC_Stack_Size,		0x00000008
.equ	ABT_Stack_Size,		0x00000000
.equ	FIQ_Stack_Size,		0x00000000
.equ	IRQ_Stack_Size,		0x00000080
.equ	USR_Stack_Size,		0x00000400

.equ	ISR_Stack_Size,		(UND_Stack_Size + SVC_Stack_Size + ABT_Stack_Size + FIQ_Stack_Size + IRQ_Stack_Size)

/* 启动步骤
// --------------------------
//	禁止看门狗 ->
//	在中断控制器中屏蔽所有中断 ->
//	系统时钟设置 ->
//	初始化端口 ->
//	DMA设置 ->
//	cashe和总线设置 ->
//	存储器设置，初始化SDRAM ->
//	初始化堆栈 ->
//	设置IRQ和FIQ的入口 ->
//	地址重映射
*/
