#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char*argv[])
{
  FILE *fptr1;
  FILE *fptr2;
  fptr1 = fopen("test.asm","r");
  fptr2 = fopen("output.asm", "w+");
  if (fptr1 == NULL)
    {
      printf("Error!");
      exit(1);
    }
  
  char line[500];
  while(fgets(line, sizeof(line), fptr1)){

    char *sub;
    sub = strstr(line, "SUB");
    char *hashtag;
    hashtag = strstr(line, "#");
    char *rst;
    rst = strstr(line, "RST");
    char *abs;
    abs = strstr(line, "ABS");
    char *orr;
    orr = strstr(line, "ORR");
    char * mlt;
    mlt = strstr(line, "MLT");
    char *neg;
    neg = strstr(line, "NEG");
    char *nand;
    nand = strstr(line, "NAND");
    /*If line is a comment it'll start with a semi colon so delete that line*/
    if (line[0] == ';'){
      fprintf(fptr2, "\n");
    }
    /*De;ete everything after comment character... if see semi colon replace with \0 and done with comments printf("%s", line);*/
    else if (sub){
      /*Account for sub if it uses a number, so there'll be a #*/
      if (hashtag){
	char delim[] = " \t";
      char *ptr = strtok(line, delim);
      int count = 0;
      char *zero;
      char *one;
      char *two;
      char *three;
      while (count < 4){
        if (count == 0){
          zero = ptr;
          count ++;
        }
        else if (count == 1){
          one = ptr;
          count ++ ;
        }
        else if (count == 2){
          two = ptr;
          count ++;

        }
        else if (count == 3){
          three = ptr;
	  count ++;
	}

        ptr = strtok(NULL, delim);
      }
      /*Get rid of commas*/
      char *comma = strstr(one, ",");
      if (comma){
        int len = strlen(one);
        one[len-1] = '\0';
      }
      char *comma2 = strstr(two, ",");
      if (comma){
        int len = strlen(two);
        two[len-1] = '\0';
      }
      /*Now need to negate the number in the "third" part of the string*/
      char *hashremoved = three + 1;
      char *threeNew;
      fprintf(fptr2, "ADD %s, %s, #-%s\n", one, two, hashremoved);
      }
      else {
      char delim[] = " \t";
      char *ptr = strtok(line, delim);
      int count = 0;
      char *zero;
      char *one;
      char *two;
      char *three;
      while (count < 4){
	if (count == 0){
	  zero = ptr;
	  count ++;
	}
	else if (count == 1){
	  one = ptr;
	  count ++ ;
	}
	else if (count == 2){
	  two = ptr;
	  count ++;
	}
	else if (count == 3){
	  three = ptr;
	  count ++;
	}
	
	ptr = strtok(NULL, delim);
      }
      /*Get rid of commas*/
      char *comma = strstr(one, ",");
      if (comma){
	int len = strlen(one);
	one[len-1] = '\0';
      }

      char *comma2 = strstr(two, ",");
      if (comma){
	int len = strlen(two);
	two[len-1] = '\0';
      }
      /*This does not work if there is a number
	only works for registers */
      
      fprintf(fptr2, "NOT %s, %s\n", one, three);
      fprintf(fptr2, "ADD %s, %s, #1\n", one, one);
      fprintf(fptr2, "ADD %s, %s, %s\n", one, one, two);
    }
      }
    else if (rst){
      char delim[] = " \t";
      char *ptr = strtok(line, delim);
      int count = 0;
      char *zero;
      char *one;
      while (count < 2){
        if (count == 0){
          zero = ptr;
          count ++;
        }
        else if (count == 1){
          one = ptr;
	  count ++;
        }

	ptr = strtok(NULL, delim);	
      }
      /*Get rid of white space*/
      int len = strlen(one);
        one[len-1] = '\0';
      fprintf(fptr2, "AND %s, %s, #0\n", one, one);
    }
    else if (abs){
       /*Account for absilute value if it uses a number, so there'll be a #*/
      if (hashtag){
        char delim[] = " \t";
      char *ptr = strtok(line, delim);
      int count = 0;
      char *zero;
      char *one;
      char *two;
      while (count < 3){
        if (count == 0){
          zero = ptr;
          count ++;
        }
        else if (count == 1){
          one = ptr;
          count ++ ;
        }
        else if (count == 2){
          two = ptr;
          count ++;

        }
        ptr = strtok(NULL, delim);
      }

      /*Get rid of commas*/
      char *comma = strstr(one, ",");
      if (comma){
        int len = strlen(one);
        one[len-1] = '\0';
      }

      
      /*Now need to negate the number in the "third" part of the string*/
      char *hashremoved = two + 1;
      char *negative;
      negative = strstr(hashremoved, "-");
      if (negative){
	/*Get rid of negative sign*/
	char *positive = negative + 1;
	/*Make the register be set to 0 when we begin*/
	fprintf(fptr2, "AND %s, %s, #0\n", one, one);
	fprintf(fptr2, "ADD %s, %s, #%s\n", one, one, positive);
      }
      else {
	fprintf(fptr2, "ADD %s, %s, #0\n", one, hashremoved);
      }
      }
      else{
      char delim[] = " \t";
      char *ptr = strtok(line, delim);
      int count = 0;
      char *zero;
      char *one;
      char *two;
      while (count < 3){
      /* while (ptr != NULL){*/
        if (count == 0){
          zero = ptr;
          count ++;
	 
        }
        else if (count == 1){
          one = ptr;
	  count ++;
	  
        }
	else if (count == 2){
	  two = ptr;
	  count ++;
	  printf("TWO IS %s\n", two);
	}
	

        ptr = strtok(NULL, delim);
      }

      /* So if it's abs R1, R2*/
      /*Get rid of white space at end of second input*/
      /*      int len = strlen(two);
	      one[len-1] = '\0';*/

       /*Get rid of commas*/
      char *comma = strstr(one, ",");
      if (comma){
        int len = strlen(one);
        one[len-1] = '\0';
      }
     
      
      fprintf(fptr2, "ADD %s, %s, #0\n", one, two);
      fprintf(fptr2, "BRzp AB\n");
      fprintf(fptr2, "NOT %s, %s\n", one, one);
      fprintf(fptr2, "ADD %s, %s, #1\n", one, one);
      fprintf(fptr2, "AB ADD %s, %s, #0\n", one, one);
    }
      }
    else if (orr){
      /*This or function only works for registers, not a register or a number*/
      
      char delim[] = " \t";
      char *ptr = strtok(line, delim);
      int count = 0;
      char *zero;
      char *one;
      char *two;
      char *three;
      while (count < 4){
        if (count == 0){
          zero = ptr;
          count ++;
        }
        else if (count == 1){
          one = ptr;
          count ++ ;
        }
        else if (count == 2){
          two = ptr;
          count ++;
        }
	else if (count == 3){
	  three = ptr;
	  count ++;
	}

        ptr = strtok(NULL, delim);
      }
      /*Get rid of commas*/
      char *comma = strstr(one, ",");
      if (comma){
        int len = strlen(one);
        one[len-1] = '\0';
      }

      char *comma2 = strstr(two, ",");
      if (comma){
        int len = strlen(two);
        two[len-1] = '\0';
      }
      /*This does not work if there is a number                                                                                                                                                          
        only works for registers */

      fprintf(fptr2, "NOT %s, %s\n", two, two);
      fprintf(fptr2, "NOT %s, %s\n", three, three);
      fprintf(fptr2, "AND %s, %s, %s\n", one, two, three);
      fprintf(fptr2, "NOT %s, %s\n", one, one);
      }
    else if (neg){
      char delim[] = " \t";
      char *ptr = strtok(line, delim);
      int count = 0;
      char *zero;
      char *one;
      while (count < 2){
        if (count == 0){
          zero = ptr;
          count ++;
        }
        else if (count == 1){
          one = ptr;
          count ++;
        }

        ptr = strtok(NULL, delim);
      }
      /*Get rid of white space*/
      int len = strlen(one);
        one[len-1] = '\0';
      fprintf(fptr2, "NOT %s, %s\n", one, one);
      fprintf(fptr2, "ADD %s, %s, #1\n", one, one);
    }
    /*This is implementation of nand, which is not and*/
    else if (nand){
      char delim[] = " \t";
      char *ptr = strtok(line, delim);
      int count = 0;
      char *zero;
      char *one;
      char *two;
      char *three;
      while (count < 4){
        if (count == 0){
          zero = ptr;
          count ++;
        }
        else if (count == 1){
          one = ptr;
          count ++ ;
        }
        else if (count == 2){
          two = ptr;
          count ++;
        }
        else if (count == 3){
           three = ptr;
          count ++;
        }

        ptr = strtok(NULL, delim);
      }
      /*Get rid of commas*/
      char *comma = strstr(one, ",");
      if (comma){
        int len = strlen(one);
        one[len-1] = '\0';
      }

      char *comma2 = strstr(two, ",");
      if (comma){
        int len = strlen(two);
        two[len-1] = '\0';
	}
      /*Actual implementation of nand*/
      fprintf(fptr2, "AND %s, %s, %s\n", one, two, three);
      fprintf(fptr2, "NOT %s, %s\n", one, one);
    }
    else if (mlt){
       char delim[] = " \t";
      char *ptr = strtok(line, delim);
      int count = 0;
      char *zero;
      char *one;
      char *two;
      char *three;
      while (count < 4){
        if (count == 0){
          zero = ptr;
          count ++;
        }
        else if (count == 1){
          one = ptr;
          count ++ ;
        }
        else if (count == 2){
          two = ptr;
          count ++;
        }
        else if (count == 3){
          three = ptr;
          count ++;
        }

        ptr = strtok(NULL, delim);
      }
      /*Get rid of commas*/
      char *comma = strstr(one, ",");
      if (comma){
        int len = strlen(one);
        one[len-1] = '\0';
      }
        char *comma2 = strstr(two, ",");
      if (comma){
        int len = strlen(two);
        two[len-1] = '\0';
      }
       /*Get rid of white space*/
      int len = strlen(three);
        three[len-1] = '\0';
	 /*Get rid of white space*/
      int len2 = strlen(two);
        two[len2-1] = '\0';
      /*For this implementation R0 and R7 need to be empty otherwise values get lost*/
      fprintf(fptr2, "AND R0, R0, #0\n");
      fprintf(fptr2, "ADD R0, R0, #1\n");
      /*R0 is meant to keep track of the sign*/
      /*Make R7 equal to whatever is in second register specified*/
      fprintf(fptr2, "AND R7, R7, #0\n");
      fprintf(fptr2, "ADD R7, R7, %s\n", three);
      fprintf(fptr2, "AND %s, %s, #0\n", three, three);
      fprintf(fptr2, "ADD %s, %s, #0\n", two, two);
      /*If register i positive skip this*/
      /*Otherwise make it positive and make register keeping track of sign negative*/
      fprintf(fptr2, "BRp next\n");
      fprintf(fptr2, "NOT %s, %s\n", two, two);
      fprintf(fptr2, "ADD %s, %s, #1\n", two, two);
      fprintf(fptr2, "NOT R0, R0\n");
      fprintf(fptr2, "ADD R0, R0, #1\n");
      fprintf(fptr2, "next ADD %s, %s, #0\n", three, three);
      fprintf(fptr2, "BRp positive\n");
      /*If pos skip this otherwise turn it positive and turn negative tracker*/
      fprintf(fptr2, "NOT %s, %s\n", three, three);
      fprintf(fptr2, "ADD %s, %s, #1\n", three, three);
      fprintf(fptr2, "NOT R0, R0\n");
      fprintf(fptr2, "ADD R0, R0, #1\n");
      fprintf(fptr2, "NOT R7, R7, #1\n");
      fprintf(fptr2, "BRz DONE\n");
      fprintf(fptr2, "ADD %s, %s, R7\n", three, three);
      fprintf(fptr2, "ADD %s, %s, #-1\n", two, two);
      fprintf(fptr2, "BR positive\n");
      fprintf(fptr2, "DONE ADD %s, %s, #0\n", three, three);
      fprintf(fptr2, "ADD %s, %s, #0\n", three, three);
      fprintf(fptr2, "BRp FINISH\n");
      fprintf(fptr2, "NOT %s, %s\n", three, three);
      fprintf(fptr2, "ADD %s, %s, #1\n", three, three);
      fprintf(fptr2, "FINISH ADD %s, %s, #1\n", three, three);
            
    }    
    else{
      fprintf(fptr2, "%s", line);
    }
    }
    fclose(fptr1);
    fclose(fptr2);
    return 0; 
}
