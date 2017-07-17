//
//  main.c
//  hw04
//
//  Created by Morgan  McDowell on 3/1/17.
//  Copyright © 2017 Morgan  McDowell. All rights reserved.
//

/******************************************************************************
 * Assignment:  Homework 04
 * Lab Section: 69105
 * Description: This program determines what day tax day is in a given year
 * Programmers: Morgan McDowell mcdowel5@purdue.edu
 ******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//function declarations
int getDay();
int getYear();
int leapYear(int year);
int calcMonth(int day, int leap);
int calcDayMonth(int day, int leap, int month);
int calcTaxDayYear(int taxDay);
int calcTaxDayMonth(int year);
int calcCountdown(int day, int taxDay, int year1, int year2, int leap1);
int checkYear(int day, int year);
int displayResults(int month, int day, int year, int taxMonth, int taxDay, int countdown, int year2);

int main()
{
    //local variables
    int dayInYear;      //day out 366 or 365 in year
    int year1;          //year given by user
    int year2;          //year of tax day
    int leap1;          //checks if first year is a leap year
    int leap2;          //checks if year of tax day is a leap year
    int month;          //month of day given by user
    int dayInMonth;     //day within the month of the day given by the user
    int taxDayInMonth;  //day of tax day within April
    int taxDayInYear;   //day of tax day out of 365 or 366
    int countdown;      //number of days until nexy tax day
    int taxMonth = 04;  //month of tax day
    
    //Statements
    //Gets data from user
    dayInYear = getDay();
    year1 = getYear();
    
    //calcualtes the date the user gave
    leap1 = leapYear(year1);
    month = calcMonth(dayInYear, leap1);
    dayInMonth = calcDayMonth(dayInYear, leap1, month);
    
    //calculates if tax day falls on the next year
    year2 = checkYear(dayInYear, year1);
    leap2 = leapYear(year2);
    
    //calculates tax day date and countdown if tax day has already passed in the given year
    taxDayInMonth = calcTaxDayMonth(year2);
    taxDayInYear = calcTaxDayYear(taxDayInMonth);
    countdown = calcCountdown(dayInYear, taxDayInYear, year1, year2, leap2);
    
    //display results
    displayResults (month, dayInMonth, year1, taxMonth, taxDayInMonth, countdown, year2);
    
    return 0;
}

/******************************************************************************
 * Function:    getDay
 * Description: recives day from user
 * Parameters:  void
 * Return:      int, day, day number between 1-365 or 366
 ******************************************************************************/
int getDay()
{
    int day;
    printf("Enter the day: ");
    scanf("%d", &day);
    return day;
}

/******************************************************************************
 * Function:    getYear
 * Description: reives year from user
 * Parameters:  void
 * Return:      int, year, year the user inputs
 ******************************************************************************/
int getYear()
{
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);
    return year;
}

/******************************************************************************
 * Function:    leapYear
 * Description: decides whether the current year is a leap year
 * Parameters:  year, int, year of date
 * Return:      returns a value of 1 or 0 if tests case if true or false
 ******************************************************************************/
int leapYear(int year)
{
    int leap;
    leap = (!(year % 4) && (year % 10)) || !(year % 400);
    return leap;
}

/******************************************************************************
 * Function:    calcMonth
 * Description: function determines what month a day belongs to
 * Parameters:  leap, int, whether it is a leap year or not
 *              day, int, day out of 365 or 366 in year
 * Return:      int, month, month of given day
 ******************************************************************************/
int calcMonth(int day, int leap)
{
    int month;
    
    //calculates month
    if (leap == 0)
    {
        if (day >= 335)
            month = 12;
        else if (day >= 305)
            month = 11;
        else if (day >= 274)
            month = 10;
        else if (day >= 244)
            month = 9;
        else if (day >= 213)
            month = 8;
        else if (day >= 182)
            month = 7;
        else if (day >= 152)
            month = 6;
        else if (day >= 121)
            month = 5;
        else if (day >= 91)
            month = 4;
        else if (day >= 60)
            month = 3;
        else if (day >= 32)
            month = 2;
        else if (day >= 1)
            month = 1;
    }
    if (leap == 1)
    {
        if (day >= 336)
            month = 12;
        else if (day >= 306)
            month = 11;
        else if (day >= 275)
            month = 10;
        else if (day >= 246)
            month = 9;
        else if (day >= 214)
            month = 8;
        else if (day >= 183)
            month = 7;
        else if (day >= 153)
            month = 6;
        else if (day >= 122)
            month = 5;
        else if (day >= 92)
            month = 4;
        else if (day >= 61)
            month = 3;
        else if (day >= 32)
            month = 2;
        else if (day >= 1)
            month = 1; 
    }
    
    return month;
} 

/******************************************************************************
 * Function:    calcDayMonth
 * Description: determines day in the month of a date
 * Parameters:  day, int, numered day in the year
 *              leap, int, if the year is leap year
 *              month, int, month of the date
 * Return:      int, returns day in the month a date lands on
 ******************************************************************************/
int calcDayMonth(int day, int leap, int month)
{
    int dayMonth;
    
    //Calculates day in the month
    if (month == 1)
        dayMonth = day;
    else if (month == 2)
        dayMonth = day - 31;
    else if (month == 3)
        dayMonth = day - 59;
    else if (month == 4)
        dayMonth = day - 90;
    else if (month == 5)
        dayMonth = day - 120;
    else if (month == 6)
        dayMonth = day - 151;
    else if (month == 7)
        dayMonth = day - 181;
    else if (month == 8)
        dayMonth = day - 212;
    else if (month == 9)
        dayMonth = day - 243;
    else if (month == 10)
        dayMonth = day - 273;
    else if (month == 11)
        dayMonth = day - 304;
    else if (month == 12)
        dayMonth = day - 334;
    
    //Calculates day in month if its a leap year
    if (leap == 1 && (month == 3 || month == 4 || month == 5 || month == 6 || month == 7 || month == 8 || month == 9 || month == 10 || month == 11 || month == 12))
    {
        dayMonth -= 1;
    }
    
    return dayMonth;
}

/******************************************************************************
 * Function:    calcTaxDayMonth
 * Description: determines day tax day is
 * Parameters:  year, int, year of tax day
 * Return:      day, int, day of april tax day is
 ******************************************************************************/
int calcTaxDayMonth(int year)
{
    int day;
    int dayOfWeek;
    int decDay;
    
    //Calculates day of the week for december 31
    decDay = ((year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
    
    //Calculates day of the week of tax day
    dayOfWeek = decDay;
    
    //calculates day of week of tax day if its a leap year
    if (leapYear(year) == 1)
        dayOfWeek = dayOfWeek + 1;
    //sets reference back to 0
    if (dayOfWeek == 7)
        dayOfWeek = 0;
    
    //Calculates if tax day is the 15, 16, 17th
    if (dayOfWeek == 1 || dayOfWeek == 2 || dayOfWeek == 3 || dayOfWeek == 4 || dayOfWeek == 5)
        day = 15;
    else if (dayOfWeek == 0)
    {
        day = 16;
        if (leapYear(year) == 1)
            day = 17;
    }
    else if (dayOfWeek == 6)
        day = 17;
    
    return day;
}

/******************************************************************************
 * Function:    calcTAxDayYear
 * Description: determiines that day of the year tax day is
 * Parameters:  taxDay, int, tax day within month
 * Return:      day, int, day of tax day within the year
 ******************************************************************************/
int calcTaxDayYear(int taxDay)
{
    int day;
    
    //Calculates what number day tax day is out of 365 or 366
    if (taxDay == 15)
        day = 105;
    else if (taxDay == 16)
        day = 106;
    else if (taxDay == 17)
        day = 107;
    
    return day;
}

/******************************************************************************
 * Function:    CalcCountdown
 * Description: calculates number of days between tax day and date
 * Parameters:  day, int, numerical value of day given by user
 *              taxDay, int, numierical day in year tax day is
 *              leap1, int, whether its a leap year or not
 *              year1, int, year of given date
 *              year2, int, year of tax day
 * Return:      days, int, number of days until tax day
 ******************************************************************************/
int calcCountdown(int day, int taxDay, int year1, int year2, int leap1)
{
    int days;
    
    if (year1 == year2)
    {
        days = taxDay - day;
        
        if (leap1 == 1)
            days = days + 1;
    }
    
    else if(year2 > year1)
    {
        days = 366 - abs(taxDay - day);
        
        if (leapYear(year2) == 1)
            days = 366 + (taxDay - day);
    }
    
    return days;
}


/******************************************************************************
 * Function:    checkYear
 * Description: adds one to year if tax day is the next year
 * Parameters:  year, int, year given by user
 *              day, int, numeircal day of date
 * Return:      year
 ******************************************************************************/
int checkYear(int day, int year)
{
    if (day > 107 || leapYear(year + 1) == 1)
        year = year + 1;
    
    return year;
}

/******************************************************************************
 * Function:    displayResults
 * Description: prints results
 * Parameters:  month, int, given month
 *              day, int, given day
 *              year, given year
 *              taxMonth, month of tax day
 *              taxDay, day of tax day
 *              countdown, days left until tax day
 * Return:      void
 ******************************************************************************/
int displayResults(int month, int day, int year1, int taxMonth, int taxDay, int countdown, int year2)
{
    printf("\nDate input: %02d/%02d/%d \n", month, day, year1);
    printf("Next tax day: %02d/%02d/%d \n", taxMonth, taxDay, year2);
    if (countdown == 0)
    {
        printf("\nToday is tax day.\n");
        return 0;
    }
    else
    {
        printf("\nThe next tax day is in %d days.\n", countdown);
        return 0;
    }
}
