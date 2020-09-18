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
// header file
#ifndef DIVJOTCHAWLAASSIGN2_BUREAU_H
#define DIVJOTCHAWLAASSIGN2_BUREAU_H

#define TRUE 1
#define RANDOM_ENTRIES 100  // Array structure of 100 households



/* Using enumerated data type for region, town and race */
enum E_region { peel, york, durham };    // region enum
enum E_town { brampton, vaughan, oshawa, mississauga, maple, whitby };  // town enum
enum E_race { caucasian, indigenous, african_american, asian, other };  // race enum

/* Information related to date */
typedef struct dating
{
    int month;
    int day;
    int year;
}
        dating;

/* The structure of information */
typedef struct data_struct
{
    dating collection_date;
    enum E_region region;
    enum E_town town;
    enum E_race race;
    int numMember;
    int yearlyEarning;
}
        data_struct;
/* This will put the entries in input */
void clearingData();

/* Force the user to input an integer between a range */
int readInt(int min, int max);

/*
 * Generate a random value between minimum and maximum
 */
int generatingInt(int min, int max);

/* Create a new entry from user input. Will be done using five different inputs.
 * That are region, town, number of member, race and income
 */
data_struct scanInput();

/*
 * Create a random entry - This will generate entries which is:
 * Income, Family Size, Race, Region and Town.
 */
data_struct generatingEntries();

/*
 * Function 1- Number of households by region
 */
void sumByRegion(data_struct *data);

/*
 * Function 2- Number of households by race
 */
void sumByRace(data_struct *data);

/*
 * Function 3- Calculation of average income
 */
void sumAvgIncome(data_struct *data);

/*
 * Function 4- Calculation of average income by town and region
 */
void avgTownRegion(data_struct *data);

/*
 * Function 5- Calculation of average income by race
 */
void avgRace(data_struct *data);

/*
 * Poverty Validator- Function to check if the data is below poverty or not
 */
int povertyValidator(data_struct entry);

/*
 * Function 6- Calculation of % below poverty.
 */
void belowPoverty(data_struct *data);

/*
 * Function 7- Calculation of % below poverty line by race.
 */
void belowPoverty_race(data_struct *data);

/*
 * Function 8- Calculation of % below poverty line by town and region.
 */
void belowPoverty_townRegion(data_struct *data);

/*
 * Print the house holds in a formatted manner - with proper spaces and indentation
 */
void tabularData(data_struct *data);

#endif //DIVJOTCHAWLAASSIGN2_BUREAU_H
