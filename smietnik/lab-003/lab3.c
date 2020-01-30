#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LINE_SIZE 64
#define PI 3.14159265

int main()
{
    /*
	* 0. Read the documentation of the stdio.h, stdlib.h, string.h, and math.h libraries
    * 1. Try to open the "data.csv" file for reading (look at this file in a text editor also) */

    FILE *infile = fopen("data.csv", "r");
    if (!infile)
        printf("File does not exist or did not open successfully");
    else {
        FILE *outfile = fopen("results.txt", "w");
        char line[LINE_SIZE] = {};
        fgets(line, LINE_SIZE, infile);


        char * f_name = strtok(line, ";");
        printf("F name: %s", f_name);

        char * _p1 = strtok(NULL , ";");
        double p1 = atoi(_p1);
        printf("\nParam 1: %f", p1);

        char * _p2 = strtok(NULL , ";");
        double p2 = atoi(_p2);
        printf("\nParam 2: %f", p2);


        if (strcmp(f_name, "power") == 0)
        {
            int result = pow((int) p1, (int) p2);
            printf("\nresult: %d",result);
        }

        if (strcmp(f_name, "sum") == 0)
        {
            double result = p1 + p2;
            printf("\nresult: %f",result);
        }






    }

    /*
    * 2. If it does not exist, print an appropriate message into the standard error stream
    * 3. Create and open the "results.txt" file for writing
	* 4. Create a character array for a single line of text (use a LINE_SIZE constant as its size)
	* 5. In a loop: read the "data.csv" file line by line and with each line:
	* 6. Split it into 3 substrings: function name, first argument and second argument (can be NULL)
	* 7. Depending on a first substring (function name) convert to double required number of arguments (one or two)
	* 8. Depending on a first substring (function name) use an appropriate math library function (or an arithmetic operator) to calculate the result
	* 9. Write the result using a *nice* formating to the "results.txt" file (with arguments and applied function)
	* 10. When a non-matching function is encountered (e.g. "test"), an appropriate message should be printed into the standard error stream
	* 11. Warning: the sine function uses radians and the "data.csv" file stores degrees -> they should be converted (see math.h documentation, use the PI constant )
	* 12. Close all files used in the program
    */

	/*
	* Examples:
	* a) the line "power;2;3" should be split into: "power", "2", "3" substrings and the result should be formatted as follows: "2.0^3.0 = 8.0"
	* b) the line "sine;30.0" should be split into: "sine", "30.0" substrings and the result should be formatted as follows: "sin 30.0 = 0.5"
	*/

	int iii;
	scanf("%d",iii);
    return 0;
}
