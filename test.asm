.ORIG	x3000
	LD		R1, E
	LD R2, B
	LD R0, G
	LD R3, F
	LD R4, D
	LD R5, A
	LD R6, C
	
	MLT R2, R1, R2
	;
	MLT R6, R2, R0
	;

	SUB R6, R4, R7
	;; 
	SUB R0, R2, R3
	;; 
	SUB R3, R4, R6
	;;
	SUB R1, R1, #-5
	;;
	SUB R2, R5, #1
	;; 
	RST R4
	;; 
	RST R6
	;; 
	RST R3
	;; 
	ABS R3, R5
	;; 
	ABS R4, #-5
	;; 
	ABS R3, #23
	;; 
	ORR R1, R2, R3
	;; 
	ORR R3, R3, R6		
	;; 
	NEG R5
	;; 
	NEG R7
	;; 
	NEG R8
	;; 
	NAND R1, R2, R3		
	;; 
	NAND R5, R5, R6
	;; 
	NAND R4, R3, R2
	
	   HALT
;
	A	   .FILL	5
	B .FILL 7
	C .FILL 10
	D .FILL -4
	E .FILL -292
	F .FILL -43
	G .FILL 78
	
;
	   .END
