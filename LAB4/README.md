# CS402 - LAB 4 - Register Usage and Procedures
## By: Shubham Das

<br>
Test plan for the C/C++ Ackermann’s function

|x|y|A(x,y)|
|-|-|:---:|
|0|0|1|
|0|2|3|
|1|0|2|
|2|3|9|
|2|4|11|
|2|5|13|
|2|6|15|
|3|1|13|
|3|2|29|
|3|3|61|

<br>
Test plan for the MIPS assembly Ackermann’s function

|x|y|A(x,y)|
|-|-|:---:|
|0|0|1|
|0|2|3|
|1|0|2|
|2|3|9|
|2|4|11|
|2|5|13|
|2|6|15|
|3|1|13|
|3|2|29|
|3|3|61|

<br>

## Q1. How many recursive calls are made to calculate A(2, X) where X is 6?

<br>
RA(2,n)=2n^2+7n+5
<br>
A(2,4) results in 119 recursive calls
<br>
<br>

## Q2. Every time a recursive call is made, the stack grows by how many bytes per call?

<br>

8 bytes per call