#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bureau.h"
/*
 * Census Bureau of Greater Toronto Area
 * Author: Divjot S. Chawla
 * Date: 19 June, 2020
 * Description: This is a assignment for Data Structure in C and is based on census of the GTA. ( worth 7.5%)
 * Version: 2.7
 */

/*
 * main.c contains the main method only.
 * */
int main(int argc, char *averg[]) {
    int num_entries;
    int choice;
    data_struct data[RANDOM_ENTRIES];

    srand((unsigned) time(0));
    num_entries = 0;  // Doing the random entry

    while (num_entries < RANDOM_ENTRIES) {
        printf("Tired? Would you like to fill up the rest of the entries randomly? (0-Yes, 1-No): ");
        choice = readInt(0, 1);

        if (choice == 0)
            break;

        data[num_entries++] = scanInput();
    }

    // Randomly filling up the other entries 
    for (0; num_entries < RANDOM_ENTRIES; num_entries++)
        data[num_entries] = generatingEntries();

    tabularData(data);


    /*
     * This is a menu that will display the menu and do the calculations by calling appropiate functions
     */

    while (TRUE) {
        printf(" MENU:\n");
        printf(" 1. Households by region\n");
        printf(" 2. Households by race\n");
        printf(" 3. Average household income\n");
        printf(" 4. Average household by town and region\n");
        printf(" 5. Average household income by race\n");
        printf(" 6. Percentage of households below poverty\n");
        printf(" 7. Percentage of households below poverty by race\n");
        printf(" 8. Percentage of households below poverty by town and region\n");
        printf(" 0. Exit\n");
        printf(" Option: ");
        choice = readInt(0, 8);

        // operation of the display menu
        if (choice == 0)
            break;

        if (choice == 1)
            sumByRegion(data);
        else if (choice == 2)
            sumByRace(data);
        else if (choice == 3)
            sumAvgIncome(data);
        else if (choice == 4)
            avgTownRegion(data);
        else if (choice == 5)
            avgRace(data);
        else if (choice == 6)
            belowPoverty(data);
        else if (choice == 7)
            belowPoverty_race(data);
        else if (choice == 8)
            belowPoverty_townRegion(data);
        else
            printf("Error: Invalid choice.\n");
    }
    return 0;
}