.data 0x10010000
var1: .word 2

.text
.globl main
main:   addu $s0, $ra, $0
        lw $t0, var1
        li $a1, 100
        move $t1, $t0
loop:   ble $a1, $t1, exit
        addi $t0, $t0, 1
        addi $t1, $t1, 1
        j loop
exit:
        sw $t0, var1
        addu $ra, $0, $s0
        jr $ra