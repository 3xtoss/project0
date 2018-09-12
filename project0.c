/////////////////////////////////////////////////////
/*
@author: Jared Mulhausen
@project: 0
*/////////////////////////////////////////////////////


//Import some libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//macro that defines maximum table size, I'm not sure that I actually use it but whatever
//#define ASCII_ARRAY_SIZE 25



/*
    Full Character table that will keep track of the occurence of character occurences.
    other helpful global values that help with everything else.
*/
int full_character_table[256];
int conversion_character;
const char *beginning = NULL;
const char *ending = NULL;


/*
More global values that will help with table creation.
*/
int table_start;
int table_end;
//int TABLE_SIZE;



/*
@function:
@purpose:
@params:
*/
void create_hashes(int amount) {
  if(amount>0) {
    for(int i = 0; i < amount; i++) {
      printf("#");
    }
  }
  printf("\n");
}

/*
@function:
@purpose:
@params:
*/

void print_table(int a[]) {
  for (int i = 0; i < 256; i++) {
    printf("%d\n", a[i]);
  }
}
/*
@function:
@purpose:
@params:
*/
void print_range(int begin, int end) { printf("Range: "); printf("%c-%c\n",(char) begin, (char) end);}

/*
@function:
@purpose:
@params:
*/

void print_table_with_boundaries(int a[], int begin, int end) {
  for (int i = begin; i <= end; i++) {
    char convert = (char) i;
    printf("%c:    %d ", convert,a[i]);
    create_hashes(a[i]);
  }
}

/*
@function:
@purpose:
@params:
*/

int main(int argc, char *argv[])
{
  /*
          Beginning condition, checking to see if arguments were passed to the compiler
  */
  if (argc <= 1) {
    fprintf(stderr, "Invalid number of arguments: EXITING NOW %d\n", argc);
    exit(-1);
  }

  /*
          Second condition, checking to see if arguments passed to the compiler were of correct size
  */
  else if (strlen(argv[1]) && strlen(argv[2]) != 1) {
    fprintf(stderr, "Invalid argument size(s): '%s' '%s'\n",argv[1],argv[2]);
    exit(-1);
  }
/*
        Successful condition, begin creation.
*/
  else {

    //test casing....
    beginning = argv[1];
    //printf("'%s'\n", beginning);
    ending = argv[2];
    //printf("'%s'\n", ending);

    //starting ascii value
    table_start = (int) *beginning;
    //printf("%d\n",table_start);

    //ending ascii value
    table_end = (int) *ending;
    //printf("%d\n", table_end);

    //computing table size.
    //TABLE_SIZE = table_end - table_start;
    //printf("%d\n", TABLE_SIZE);


    //creating a table of the correct size and setting appropriate values;
    /*
    example of default array values.
    a[0] = table_start, a[1],a[2],......, a[TABLE_SIZE] = table_end
    */
    //int ascii_print[TABLE_SIZE];
    //ascii_print[0] = table_start;
    //ascii_print[TABLE_SIZE] = table_end;


    //test cases
    //printf("%d\n", ascii_print[0]);
    //printf("%d\n", ascii_print[TABLE_SIZE - 1]);


    //temporary variable that will go to the next ascii value in the table.
    //int temp = table_start + 1;

    /*
    Loops through and stores the appropriate ascii values into the table.

    */
    //for(int i = 1; i < TABLE_SIZE; i++) {
      //ascii_print[i] = temp;

      //test case
      //printf("ASCII: %d\t VALUE INSERTED: %d\n", ascii_print[i], temp);
      //temp += 1;
    //}

    //for(int i = 0; i <= TABLE_SIZE; i++) {
      //printf("TABLE POSITION: %d\t Character Value: %c\n", i, (char) ascii_print[i]);
    //}
  //}
    }
    //return 0;

    //helper variable
    char character_read;


    //beginning of file parsing Loop
    //converts characters and accurately stores them.
    //also prints off the table at the end of the file.
    do  {
      character_read = fgetc(stdin);
      conversion_character = (int) character_read;
    //  printf("Character read: %c\t Decimal Conversion: %d\n",character_read, conversion_character);

      if(conversion_character == -1 || conversion_character > 255) {
        print_range(table_start, table_end);
        print_table_with_boundaries(full_character_table, table_start, table_end);
      }
      else {
        full_character_table[conversion_character] += 1;
        //printf("Successful update");
      }
      //putchar(character_read);
    } while(character_read != EOF);
    //end of program.
    return 0;
}
