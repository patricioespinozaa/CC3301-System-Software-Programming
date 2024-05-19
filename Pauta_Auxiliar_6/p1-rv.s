    .text
    .align 8
    .globl start
    .type start, @function
start: # tipo start() 
    lui a5, %hi(n)
    lw a5, %lo(n)(a5) # int a5 = *n
    li a4, 1
    li a0, 1
    ble a5, a4, .L1
.L3:
    mul a0, a0, a5
    addi a5, a5, -1
    bne a5, zero, .L3 # if (a5 != 0) { => L3 };
.L1:
    ret
    .globl n
    .section .sdata, "aw"
    .align 2
    .type n, @object
    .size n, 4
n:
    .word 4 # global: int n = 4;
