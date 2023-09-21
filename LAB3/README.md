# Lab 3 - Postlab write-up
Name: Shubham Das
<br>
Section: cs402-V03: Fall 2023	
<br>
Date: September 20, 2023
<br>
<br>
|Synthetic Instruction|Native Instructions|Effect|
|---------------------|-------------------|------|
|bne $t0, $t1, else|bne $8, $9, 8 [else-0x00400058]| if (Rs != Rt) PC←label|
|j far| j 0x0043a900 [far]  | PC←jlabel
|jr $ra| jr $31  | PC←Rs|

https://github.com/shubhamdasdev/Sytem-programming-LABS/tree/main/LAB3
