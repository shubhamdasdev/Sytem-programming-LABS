        .data 0x10010000
var1:   .word 0x10
var2:   .word 0x20
var3:   .word 0x30
var4:   .word 0x40
first:  .byte 'C'
last:   .byte 'L'

        .text
        .globl main
main:   addu $s0, $ra, $0   #save $31 in $16
        lui $t6, 0x1001     #load variable start address
        lw $t0, 0($t6)   # load var1 to register $t0
        lw $t1, 4($t6)    # load var2 to register $t1
        lw $t2, 8($t6)    # load var3 to register $t2
        lw $t3, 12($t6)    # load var4 to register $t3
        lb $t4, 16($t6)   # load first to register $t4
        lb $t5, 17($t6)    # load last to register $t5
        sw $t3, 0($t6)		# store value in register #t3 to var1
        sw $t2, 4($t6)		# store value in register #t2 to var2
        sw $t1, 8($t6)		# store value in register #t1 to var3
        sw $t0, 12($t6)		# store value in register #t0 to var4

#restore now the return address in $ra and return from main
        addu $ra, $0, $s0   #return address back in $31
        jr $ra  #return from main
        sll $0, $0, 0 #nop 
