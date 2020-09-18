/*
 * Census Bureau of Greater Toronto Area
 * Author: Divjot S. Chawla
 * Date: 19 June, 2020
 * Description: This is a assignment for Data Structure in C and is based on census of the GTA. ( worth 7.5%)
 * Version: 2.7
 */

//
// Created by div on 2020-06-19.
//
// source file
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bureau.h"


/*
 * This will put the entries in input
 */
void clearingData() {
    int clear;
    while ((clear = getchar()) != '\n' && clear != EOF) //  End of File
    {}
}

/* Force the user to input an integer between a range */
int readInt(int min, int max) {
    int value;

    while (TRUE) {
        if (scanf("%d", &value) == 1 && value >= min && value <= max)
            return value;

        clearingData();
        printf("Error: Input is invalid. Please try again: ");
    }
}

/* Create a new entry from user input. Will be done using five different inputs.
 * That are region, town, number of member, race and income
 */
data_struct scanInput() {
    data_struct data;
    int choice;

    /* Select a region */
    printf("\n");
    printf("Select region (0-Durham, 1-Peel, 2-York): ");
    choice = readInt(0, 2);

    if (choice == 0)
        data.region = durham;
    else if (choice == 1)
        data.region = peel;
    else if (choice == 2)
        data.region = york;


    if (data.region == peel) {
        printf("\n");
        printf("Select town (0-Brampton, 1-Mississauga): ");
        choice = readInt(0, 1);

        if (choice == 0)
            data.town = brampton;
        else
            data.town = mississauga;
    } else if (data.region == york) {
        printf("\n");
        printf("Select town (0-Maple, 1-Vaughan): ");
        choice = readInt(0, 1);

        if (choice == 0)
            data.town = maple;
        else
            data.town = vaughan;
    } else if (data.region == durham) {
        printf("\n");
        printf("Select town (0-Whitby, 1-Oshawa): ");
        choice = readInt(0, 1);

        if (choice == 0) {
            data.town = whitby;
            printf("running or no");
        } else {
            data.town = oshawa;
            printf("running or no");
        }
    }


    printf("\n");
    printf("Select a race (0-Caucasian, 1-Indigenous, 2-African American, 3-Asian, 4-Other): ");
    choice = readInt(0, 4);

    if (choice == 0)
        data.race = caucasian;
    else if (choice == 1)
        data.race = indigenous;
    else if (choice == 2)
        data.race = african_american;
    else if (choice == 3)
        data.race = asian;
    else if (choice == 4)
        data.race = other;


    printf("\n");
    printf("Enter number of people in household: ");
    data.numMember = readInt(1, INT_MAX);


    printf("\n");
    printf("Enter annual income of household: ");
    data.yearlyEarning = readInt(1, INT_MAX);

    return data;
}


/* Generate a random value between min and max */
int generatingInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/*
 * Create a random entry - This will generate entries which is:
 * Income, Family Size, Race, Region and Town.
 */
data_struct generatingEntries() {
    data_struct data;

    data.region = generatingInt(0, 2);
    data.town= generatingInt(0,5);
    data.race = generatingInt(0, 4);
    data.numMember = generatingInt(1, 10);
    data.yearlyEarning = generatingInt(1, 1000000);

    return data;
}

/*
 * Function 1- Number of households by region
 */
void sumByRegion(data_struct *data) {
    int counts[3];
    int i;

    /* Reset the counts */
    for (i = 0; i < 3; i++)
        counts[i] = 0;

    /* Now do counting */
    for (i = 0; i < RANDOM_ENTRIES; i++)
        counts[data[i].region]++;

    /* Print it out */
    printf("Peel Region  : %d\n", counts[0]);
    printf(" York Region  : %d\n", counts[1]);
    printf(" Durham Region: %d\n", counts[2]);
    printf("\n");
}

/*
 * Function 2- Number of households by race
 */
void sumByRace(data_struct *data) {
    int counts[5];
    int i;

    // Refreshing the counts
    for (i = 0; i < 5; i++)
        counts[i] = 0;


    for (i = 0; i < RANDOM_ENTRIES; i++)
        counts[data[i].race]++;

    /* Print it out */
    printf("Caucasian       : %d\n", counts[0]);
    printf(" Indigenous      : %d\n", counts[1]);
    printf(" African American: %d\n", counts[2]);
    printf(" Asian           : %d\n", counts[3]);
    printf(" Other           : %d\n", counts[4]);
    printf("\n");
}

/*
 * Function 3- Calculation of average income
 */
void sumAvgIncome(data_struct *data) {
    int total;
    int i;

    total = 0;

    /* Sum up the incomes */
    for (i = 0; i < RANDOM_ENTRIES; i++)
        total += data[i].yearlyEarning;

    /* Display and count the averages */
    printf("The average household income: %d\n", total / RANDOM_ENTRIES);
    printf("\n");
}

/*
 * Function 4- Calculation of average income by town and region
 */
void avgTownRegion(data_struct *data) {
    int totals[6];
    int counts[6];
    int i;

    // Refreshing the count
    for (i = 0; i < 6; i++) {
        totals[i] = 0;
        counts[i] = 0;
    }

    //Sum up the incomes of town
    for (i = 0; i < RANDOM_ENTRIES; i++) {
        totals[data[i].town] += data[i].yearlyEarning;
        counts[data[i].town]++;
    }

    // Display and calculate the averages
    printf("Peel Region:\n");
    printf("    Average annual income of Brampton   : %d\n", totals[0] / counts[0]);
    printf("    Average annual income of Mississauga: %d\n", totals[1] / counts[1]);
    printf("\n");

    printf(" York Region:\n");
    printf("    Average annual income of Maple  : %d\n", totals[2] / counts[2]);
    printf("    Average annual income of Vaughan: %d\n", totals[3] / counts[3]);
    printf("\n");

    printf(" Durham Region:\n");
    printf("    Average annual income of Whitby: %d\n", totals[4] / counts[4]);
    printf("    Average annual income of Oshawa: %d\n", totals[5] / counts[5]);
    printf("\n");
}

/*
 * Function 5- Calculation of average income by race
 */
void avgRace(data_struct *data) {
    int totals[5];
    int counts[5];
    int i;

    /* Reset the totals */
    for (i = 0; i < 5; i++) {
        totals[i] = 0;
        counts[i] = 0;
    }

    /* Sum up the incomes by race and their counts */
    for (i = 0; i < RANDOM_ENTRIES; i++) {
        totals[data[i].race] += data[i].yearlyEarning;
        counts[data[i].race]++;
    }

    /* Display and calculate the averages */
    printf("Average annual income of Caucasians       : %d\n", (totals[0] / counts[0]));
    printf(" Average annual income of Indigenous       : %d\n", (totals[1] / counts[1]));
    printf(" Average annual income of African Americans: %d\n", (totals[2] / counts[2]));
    printf(" Average annual income of Asians           : %d\n", (totals[3] / counts[3]));
    printf(" Average annual income of Others           : %d\n", (totals[4] / counts[4]));
    printf("\n");
}

/*
 * Poverty Validator- Function to check if the data is below poverty or not
 */
int povertyValidator(data_struct entry) {
    return ((entry.numMember == 1 && entry.yearlyEarning < 15000)
            || (entry.numMember == 2 && entry.yearlyEarning < 20000)
            || (entry.numMember == 3 && entry.yearlyEarning < 25000)
            || (entry.numMember == 4 && entry.yearlyEarning < 30000)
            || (entry.numMember >= 5 && entry.yearlyEarning < 40000));
}

/*
 * Function 6- Calculation of % below poverty.
 */
void belowPoverty(data_struct *data) {
    double numPoverty;
    int i;

    numPoverty = 0;

    for (i = 0; i < RANDOM_ENTRIES; i++)
        if (povertyValidator(data[i]))
            numPoverty++;

    printf("Number of households below poverty line are: %.2f%%\n", numPoverty / RANDOM_ENTRIES * 100);
    printf("\n");
}

/*
 * Function 7- Calculation of % below poverty line by race.
 */
void belowPoverty_race(data_struct *data) {
    double numPoverty[5];
    int counts[5];
    int i;

    // Refreshing the count
    for (i = 0; i < 5; i++) {
        numPoverty[i] = 0;
        counts[i] = 0;
    }

    // calculation regarding how many are below poverty line by race
    for (i = 0; i < RANDOM_ENTRIES; i++) {
        if (povertyValidator(data[i]))
            numPoverty[data[i].race]++;

        counts[data[i].race]++;
    }

    // Display and calculate the averages
    printf("Number of households below poverty line of Caucasians       : %.2f%%\n",
           (numPoverty[0] / counts[0]) * 100);
    printf(" Number of households below poverty line of Indigenous       : %.2f%%\n",
           (numPoverty[1] / counts[1]) * 100);
    printf(" Number of households below poverty line of African Americans: %.2f%%\n",
           (numPoverty[2] / counts[2]) * 100);
    printf(" Number of households below poverty line of Asians           : %.2f%%\n",
           (numPoverty[3] / counts[3]) * 100);
    printf(" Number of households below poverty line of Others           : %.2f%%\n",
           (numPoverty[4] / counts[4]) * 100);
    printf("\n");
}

/*
 * Function 8- Calculation of % below poverty line by town and region.
 */
void belowPoverty_townRegion(data_struct *data) {
    double numPoverty[6];
    int counts[6];
    int i;

    // Refreshing the count
    for (i = 0; i < 6; i++) {
        numPoverty[i] = 0;
        counts[i] = 0;
    }

    // calculation regarding how many are below poverty line
    for (i = 0; i < RANDOM_ENTRIES; i++) {
        if (povertyValidator(data[i]))
            numPoverty[data[i].town]++;

        counts[data[i].town]++;
    }

  //  Display and calculate the averages by region
    printf("Peel Region:\n");
    printf("    Brampton   : %.2f%%\n", numPoverty[0] / counts[0] * 100);
    printf("    Mississauga: %.2f%%\n", numPoverty[1] / counts[1] * 100);

    printf(" York Region:\n");
    printf("     Maple  : %.2f%%\n", numPoverty[2] / counts[2] * 100);
    printf("     Vaughan: %.2f%%\n", numPoverty[3] / counts[3] * 100);

    printf(" Durham Region:\n");
    printf("     Whitby: %.2f%%\n", numPoverty[4] / counts[4] * 100);
    printf("     Oshawa: %.2f%%\n", numPoverty[5] / counts[5] * 100);
    printf("\n");
}

/*
 * Print the house holds in a formatted manner - with proper spaces and indentation
 */
void tabularData(data_struct *data) {
    int i;
    printf("\n");
    printf("%10s%15s%15s", "NUMBER", "INCOME", "FAMILY SIZE");
    printf("%20s%10s%20s\n", "RACE", "REGION", "TOWN");
    printf("==========================================================================================");
    printf("\n");
    for (i = 0; i < RANDOM_ENTRIES; i++) {
        printf("%10d%15d%15d", i + 1, data[i].yearlyEarning, data[i].numMember);

        if (data[i].race == caucasian)
            printf("%20s", "Caucasian");
        else if (data[i].race == indigenous)
            printf("%20s", "Indigenous");
        else if (data[i].race == african_american)
            printf("%20s", "African American");
        else if (data[i].race == asian)
            printf("%20s", "Asian");
        else if (data[i].race == other)
            printf("%20s", "Other");

        if (data[i].region == durham)
            printf("%10s", "Durham");
        else if (data[i].region == peel)
            printf("%10s", "Peel");
        else if (data[i].region == york)
            printf("%10s", "York");

        if (data[i].region == whitby)
            printf("%20s", "Whitby");
        if (data[i].region == brampton)
            printf("%20s", "Brampton");
        if (data[i].region == mississauga)
            printf("%20s", "Mississauga");
        if (data[i].region == vaughan)
            printf("%20s", "Vaughan");
        if (data[i].region == oshawa)
            printf("%20s", "Oshawa");
        if (data[i].region == maple)
            printf("%20s", "Maple");

        printf("\n");
    }
}
