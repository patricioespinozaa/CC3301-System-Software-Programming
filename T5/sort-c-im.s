	.file	"sort-c-im.c"
	.option nopic
	.attribute arch, "rv32i2p0_m2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	strCmp
	.type	strCmp, @function
strCmp:
	li	a2,25
	j	.L7
.L2:
	addi	a3,a4,-65
	andi	a3,a3,0xff
	bgtu	a3,a2,.L5
.L3:
	addi	a4,a4,32
	andi	a4,a4,0xff
.L5:
	beq	a5,zero,.L6
.L4:
	bne	a5,a4,.L6
	addi	a0,a0,1
	addi	a1,a1,1
.L7:
	lbu	a5,0(a0)
	lbu	a4,0(a1)
	addi	a3,a5,-65
	andi	a3,a3,0xff
	bgtu	a3,a2,.L2
	addi	a5,a5,32
	andi	a5,a5,0xff
	addi	a3,a4,-65
	andi	a3,a3,0xff
	bleu	a3,a2,.L3
	j	.L4
.L6:
	sub	a0,a5,a4
	ret
	.size	strCmp, .-strCmp
	.align	2
	.globl	sort
	.type	sort, @function
sort:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	sw	s1,20(sp)
	sw	s2,16(sp)
	sw	s3,12(sp)
	sw	s4,8(sp)
	slli	s3,a1,2
	addi	s3,s3,-4
	add	s3,a0,s3
	bgeu	a0,s3,.L8
	mv	s4,a0
	mv	s0,a0
	j	.L12
.L10:
	sw	s2,0(s0)
	sw	s1,4(s0)
	mv	s0,s4
.L12:
	lw	s1,0(s0)
	lw	s2,4(s0)
	mv	a1,s2
	mv	a0,s1
	call	strCmp
	bgt	a0,zero,.L10
	addi	s0,s0,4
	bgtu	s3,s0,.L12
.L8:
	lw	ra,28(sp)
	lw	s0,24(sp)
	lw	s1,20(sp)
	lw	s2,16(sp)
	lw	s3,12(sp)
	lw	s4,8(sp)
	addi	sp,sp,32
	jr	ra
	.size	sort, .-sort
	.ident	"GCC: (GNU) 11.1.0"
