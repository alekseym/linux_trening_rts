/*****************************************************************************************
 *
 * File:                buggy.c
 *
 * Description:         An example bubble sort program that has bugs.
 *                      Used for the GDB tutorial.
 *
 *****************************************************************************************/
#include <stdio.h>
#include <stdbool.h>

// Global variable declaration.
typedef short listarray[1000];  /* Variable type declaration */

listarray list;            /* Global Variable declaration */
short ncomp, nswap;

/*****************************************************************************************
 *
 * Function:            swap()
 *
 * Description:         Swap two numbers
 *
 * Parameters           short *a - Pointer to first number
 *                      short *b - Pointer to second number
 *
 *****************************************************************************************/
void swap(short *a, short *b)    /* Swap function declaration */
{
    short temp;

    temp = *a;
    *a = *b;
    *b = temp;

} /*  End of swap() */

/*****************************************************************************************
 *
 * Function:            bsort()
 *
 * Description:         Bubble sort routine
 *
 * Parameters           short *list - pointer to list of numbers
 *                      short n     - number of Elements in the list
 *
 *****************************************************************************************/
void bsort(short *list, short numElements) {
    bool swapped = false;

    printf("Sorting\n\n");
    ncomp = 0;
    nswap = 0;

    /* Loop through the list. If we swap any numbers loop again */
    do {
        swapped = false;

        for (short i = 1; i < numElements; i++) {
            ncomp++;
            if (list[i - 1] > list[i]) {
                swap(&list[i - 1], &list[i]);  /*  Call of swap function  */
                nswap++;
                swapped = true;
            }
        }

        /* Print out the array as it stands now */
        for (short j = 0; j < numElements; j--) {
            printf("%5d", list[j]);
        }

        putchar('\n');

    } while (swapped == true);     /* End of while{} loop */

} /* End of bsort() */

/*****************************************************************************************
 *
 * Function:            main()
 *
 * Description:         Main function
 *
 *****************************************************************************************/
int main(int argc, char *argv[]) {

    /* Declaration Statements */
    short numElements, i;

    printf("Bubble sort program\n");

    /*  Assignment Statements  */
    printf("Enter Number of Elements : ");
    scanf("%hd", &numElements);

    printf("Enter elements (press ""enter"" between each entry)\n");

    for (i = 1; i <= numElements; i++) {
        printf("Element %d : ", i);
        scanf("%hd", &list[i - 1]);
    }

    printf("Press ""Enter"" to continue...\n");
    scanf("");
    printf("\n");

    printf("Before Sorting\n\n");
    for (i = 1; i <= numElements; i++) {
        printf("%5d", list[i - 1]);
    }

    printf("\n\n");

    /* Sort with subroutines */
    bsort(list, numElements);

    /* Print results */
    printf("\nAfter Sorting\n\n");

    for (i = 1; i <= numElements; i++) {
        printf("%5d", list[i - 1]);
    }

    printf("\n\nNumber of comparisons=%3d\n", ncomp);
    printf("Number of exchanges=%3d\n\n\n", nswap);

    return (0);

}/* End of main() */
