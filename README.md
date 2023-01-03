# AssemblerUpgrade
This is an upgrade to the LC3 assembler.
The file draft3.c is run along with test.asm (this file can obviously be changed but name/input file must be changed inside the draft3.c code).
The code can be run like this:

gcc -o draft3 draft3.c

./draft3

lc3as output.asm

The output.asm file is the new file that is generated which is a modification of test.asm.
output.obj can then be run directly inside LC3. 
test.asm has new functions in it which LC3 does not understand. draft3.c loops through the test.asm file and exchanges the unknown LC3 functions for functions that LC3 knows. 
