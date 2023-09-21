.data 0x10010000
msg1:       .asciiz "Please enter an integer number: "
msg2:       .asciiz "I'm far away"
msg3:       .asciiz "I'm nearby"
.text
main: 
    addu $s0, $ra, $0
    # get first int
    li $v0, 4               # system call for print_str
    la $a0, msg1            # address of string to print
    syscall
    # now get an integer from the user
    li $v0, 5               # system call for read_int
    syscall                 # the integer placed in $v0
    addu $t0, $v0, $0       # move the number in $t0
    # get second int
    li $v0, 4               # system call for print_str
    la $a0, msg1            # address of string to print
    syscall
    # now get an integer from the user
    li $v0, 5               # system call for read_int
    syscall                 # the integer placed in $v0
    addu $t1, $v0, $0       # move the number in $t1

    bne $t0, $t1, else      # go to Else if $t0 != $t1
    j far                   # jump to a far label - more than 16 bit offset
else:
    li $v0, 4               # system call for print_str
    la $a0, msg3            # address of string to print
    syscall
exit:
    addu $ra, $0, $s0
    jr $ra
.text 0x0043a900
far: 
    li $v0, 4               # system call for print_str
    la $a0, msg2            # address of string to print
    syscall
    j exit     