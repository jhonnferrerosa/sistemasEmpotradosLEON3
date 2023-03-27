
#include "../include/leon3_asm.h"

.section ".text"

    .globl leon3_trap_handler_disable_irqs
leon3_trap_handler_disable_irqs:
    mov %l2, %l1
    add %l2, 4, %l2

    or %l0, 0x0f00, %l4    ! set PIL=15
    mov %l4, %psr
    nop;nop;nop
    jmp %l1
    rett %l2

    .globl leon3_trap_handler_enable_irqs
leon3_trap_handler_enable_irqs:
    mov %l2, %l1
    add %l2, 4, %l2

    andn %l0, 0xf00, %l4
    mov %l4, %psr
    nop;nop;nop
    jmp %l1
    rett %l2

    .globl leon3_sys_call_enable_irqs
leon3_sys_call_enable_irqs:
    ta LEON3_SPARC_ENABLE_IRQ_TRAPNUM
    retl
    nop

    .globl leon3_sys_call_disable_irqs
leon3_sys_call_disable_irqs:
 	ta LEON3_SPARC_DISABLE_IRQ_TRAPNUM
    retl
    nop

    .globl leon3_sparc_isr
leon3_sparc_isr:
    /* Test for window overflow */

    rd %wim, %l4
    srl %l4, %l0, %l6
    cmp %l6, 1
    bne dont_do_the_window  /* no? then skip all this stuff */
    nop

    /* Perform window overflow  */

    mov %g5,%l5
    srl %l4,1,%l6
    sll %l4,7,%g5
    or  %g5,%l6,%g5
    and %g5,0xff,%g5

    save
    mov %g5,%wim
    nop;nop;nop

    std %l0, [%sp + CPU_STACK_FRAME_L0_OFFSET]
    std %l2, [%sp + CPU_STACK_FRAME_L2_OFFSET]
    std %l4, [%sp + CPU_STACK_FRAME_L4_OFFSET]
    std %l6, [%sp + CPU_STACK_FRAME_L6_OFFSET]
    std %i0, [%sp + CPU_STACK_FRAME_I0_OFFSET]
    std %i2, [%sp + CPU_STACK_FRAME_I2_OFFSET]
    std %i4, [%sp + CPU_STACK_FRAME_I4_OFFSET]
    std %i6, [%sp + CPU_STACK_FRAME_I6_FP_OFFSET]
    restore

    mov %l5,%g5

dont_do_the_window:
    sub %fp, 0x60, %sp
    /* save global registers */
    st  %g1, [%sp + 0x40]
    rd  %y, %g1
    st  %g1, [%sp + 0x44]
    std %g2, [%sp + 0x48]
    std %g4, [%sp + 0x50]
    std %g6, [%sp + 0x58]

    or %l0, 0x0f00, %l4    ! set PIL=15
    mov %l4, %psr
    nop;nop;nop
    or %l4, PSR_ET, %l4    ! enable traps
    mov %l4, %psr
    nop;nop;nop

    set leon3_sparc_irqhandler_entry, %l4  //jhon: Esta linea salte Error. No es un error.
    call %l4
    mov %l3, %o0

    mov %l0, %psr
    nop;nop;nop

    ld  [%sp + 0x44], %g1
    wr  %g1, %y
    ld  [%sp + 0x40], %g1
    ldd [%sp + 0x48], %g2
    ldd [%sp + 0x50], %g4
    ldd [%sp + 0x58], %g6

    jmp %l1
    rett %l2


