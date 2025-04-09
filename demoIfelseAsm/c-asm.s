	.file	"c-asm.c"
	.option nopic
	.attribute arch, "rv32i2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	decode
	.type	decode, @function
decode:
	addi	sp,sp,-32
	sw	s0,28(sp)
	addi	s0,sp,32
	li	a5,10
	sw	a5,-24(s0)
	li	a5,2
	sw	a5,-20(s0)
	lw	a4,-24(s0)
	li	a5,11
	bne	a4,a5,.L2
	lw	a5,-20(s0)
	addi	a5,a5,2
	sw	a5,-20(s0)
	j	.L3
.L2:
	lw	a4,-24(s0)
	li	a5,10
	bne	a4,a5,.L4
	lw	a5,-20(s0)
	addi	a5,a5,3
	sw	a5,-20(s0)
	j	.L3
.L4:
	sw	zero,-20(s0)
.L3:
	lw	a5,-20(s0)
	mv	a0,a5
	lw	s0,28(sp)
	addi	sp,sp,32
	jr	ra
	.size	decode, .-decode
	.ident	"GCC: () 9.3.0"
