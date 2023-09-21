# Lab 2 - Postlab write-up
Name: Shubham Das
<br>
Section: cs402-V02: Fall 2023	
<br>
Date: September 20, 2023
<br>
<br>

## Q1: What is the number of instructions executed? Count only instructions between the label ‘main’ and the last instruction executed from your program.
<br>
Instruction count = 25
<br>
<br>

## Q2: What are the displacements of ext1 and ext2 from the global pointer ($gp) value?
<br>

| Variable | Displacement (Decimal) | Displacement (Hex) |
|:----------:|:----------------------:|:------------------:|
|ext1| -32768| -8000 |
|ext2| -32764| -7FFC |

<br>
The global pointer ($gp) is stored at 0x10008000

<br>
<br>

## Q3: What exactly are the addresses where variables are stored in memory?
<br>

| Variable | Address (Hex) |
|:----------:|:----------------------:|
|var1|10010000|
|var2|10010004|
|ext1|10000000|
|ext2|10000004|

<br>
<br>

## Q4: How many native instructions are needed for each of the following memory accesses?
<br>

| Memory Access | Native Instructions|
|:----------:|:----------------------|
|lw $t0, var1|lui $t1, 0x1001|
|            |lw $t0, 0($t1)|
|sw $t0, ext1|lui $t1, 0x1008|
|            |sw $t0, -32768($t1)|

<br>

https://github.com/shubhamdasdev/Sytem-programming-LABS/blob/main/LAB2/README.md
