    .data              
m: .asciiz "Ackermann function A(m,n)\nValue for m: "
n: .asciiz "Value for n: "
nl: .asciiz "\n"

    .text               
    .globl main         

main:
                        # print the first input prompt
    la $a0,m            # address of input prompt
    li $v0,4            # system call to print string
    syscall             
                        # read an integer (m)
    li $v0,5            # system call to read integer
    syscall             # result will be stored in $v0
    move $t0,$v0        # copy to $t0

                        # print the second input prompt
    la $a0,n            # address of input prompt
    li $v0,4            # system call to print string
    syscall             
                        # read an integer (n)
    li $v0,5            # system call to read integer
    syscall             # result will be stored in $v0
    move $a1,$v0        # so copy it (n) to $a1
    move $a0,$t0        # and copy $t0 (m) to $a0

    jal Ackermann       # with m in a0 and n in a1, call Ackermann(m, n)
                        # once we return here, $v0 contains the result

                        # print the integer result
    move $a0,$v0        # copy result from $v0 (above) to $a0
    li $v0,1            # system call to print integer
    syscall             
                        # print a newline:
    la $a0,nl           # address of newline
    li $v0,4            # system call to print string
    syscall             
                        # exit program:
    li $v0,10           # system call to exit
    syscall             

Ackermann:
    sub $sp,$sp,8      # make room on the stack for the following 2 variables (4 bytes each)
    sw $s0,4($sp)       # store old $s0 at $sp+4
    sw $ra,0($sp)       # store old $ra at $sp+0

    bgtz $a0,A_1        # If m > 0, skip over these next instructions.
                        # Case for m = 0:
    addi $v0,$a1,1      # result = n+1
    j A_End             # jump to end of conditional
A_1:
    bgtz $a1,A_2        # if n > 0, skip over these next instructions.
                        # Case for m>0 and n=0:
    sub $a0,$a0,1      # prep m = m-1
    li $a1,1            # prep n = 1
    jal Ackermann       # with m-1 in $a0 and 1 in $a1, call Ackermann
    j A_End             # its result will be in $v0, just return it.
A_2:
    move $s0,$a0        # copy m to $s0
    sub $a1,$a1,1      # prep n = n-1. $a0 already contains m.
    jal Ackermann       # with m in $a0 and n-1 in $a1, call Ackermann
    move $a1,$v0        # prep n = result of A(m, n-1)
    sub $a0,$s0,1      # prep m = m-1
    jal Ackermann       # with m-1 in $a0 and A(m, n-1) in $a1, call Ackermann
                        # no need to jump, fall through to A_End

A_End:         
    lw $s0,4($sp)       # restore old $s0
    lw $ra,0($sp)       # restore old $ra
    addi $sp,$sp,8      # remove those from stack
    jr $ra              # return to caller    