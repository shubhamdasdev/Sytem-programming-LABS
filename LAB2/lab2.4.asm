.data 
var1:   .word 0x003E  #value '62' in hex
var2:   .word 0x0053  #value '83' in hex

.extern ext1 4 #create variable with 4 bytes 'word'
.extern ext2 4 #create variable with 4 bytes 'word'
.text
.globl main
main:   addu $s0, $ra, $0   #save $31 in $16
    lw $t0, var1   # load var1 to register $t0
    lw $t1, var2    # load var2 to register $t1
    sw $t0, ext1		# store value in register #t0 to ext1
    sw $t1, ext2    	# store value in register #t1 to ext2
    #restore the return address in $ra and return from main
    addu $ra, $0, $s0   #return address back in $31
    jr $ra  #return from main

