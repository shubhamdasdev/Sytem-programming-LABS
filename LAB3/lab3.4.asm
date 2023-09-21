.data 0x10010000
my_array: .space 40 # 10x4 = 40, space reserved for array
.text
main: 
    addu $s0, $ra, $0
    add $t0, $0, $0  # initialize the loop counter -value 'i'
    add $t8, $0, 2  # value of 'j'
    lui $s1, 0x1001 
    ori $s1, $s1, 0x0000 # the base address for my_array[] is in $s1 

loop: 
    slti $t1, $t0, 10 
    blez $t1, exit  # test for loop termination 
    sll $t2, $t0, 2 # $t4 <- i*4 - for word length
    add $s1, $s1, $t2 # address of my_array[i] into $s1
    sw $t8, 0($s1) # store j value into my_array[i]
    addi $t0, $t0, 1 # increment loop counter 
    addi $t8, $t0, 1 # increment j value by 1
    j loop
exit:
    addu $ra, $0, $s0
    jr $ra
