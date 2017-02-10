#include <stdio.h>
#include <stdbool.h>	// need this for use of booleans under C99 
#include <limits.h>		// need this for MAX_types
#include <stdint.h>		// integer types per http://en.cppreference.com/w/c/types/integer

// SCHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX, LLONG_MAX(C99) – maximum possible value of signed integer types: signed char, signed short, signed int, signed long, signed long long. Similarly, _MIN.


int main(void) {

	short sum = 0;	// running total
	int amount = 0; // user input
	char c; // error handling

	printf("Integer Overflow example\n\nTo end program, press Ctrl-C\n\n"); // Ctrl-C works on PC, may be OS dependent
	printf("Signed short Max/Min values:  %d to %d.\n", SHRT_MAX, SHRT_MIN);
	printf("Signed int   Max/Min values:  %d to %d.  Size is platform dependent.\n", INT_MAX, INT_MIN); // could be short or long
	printf("Signed long  Max/Min values:  %d to %d.\n", LONG_MAX, LONG_MIN);
	
	while (true) { // prompt until user kills program 
		printf("Sum(short) is %d.", sum);
		printf("\nEnter a value to add to sum: ");

		// scanf() returns the number of arguments of data type(s) successfuly read [ 0 = false] ; all whitespace is stripped including \n so empty input of Return key only causes buffer to continue waiting for non-whitespace input -- a user interface issue with scanf()

		if (scanf("%d", &amount)) { // if a number was entered
			sum += amount;
		}
		else { // no numeric input returned from above scanf. give user diagnostic msg and retry input
			printf("==> ");
			while ((c = getchar()) != '\n') { printf("%c", c); };
			printf(" is not a number. Press Ctrl-C to end program.\n");
		}
	}
	return 0;
}
