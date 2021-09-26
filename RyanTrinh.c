//Include necessary libraries
#include <stdio.h>
#include "header.h"

//Function that will ask and return number of days on trip
int getDays(int argc, char*argv[]){
    int days = 0; 
    while (days<1)
    {
        printf("What was the total number of days spent on the trip? ");
        scanf("%d", &days);
        if(days<1)
        {
            printf("Sorry number of days can't be less than 1\n");
        }
    }
    return days;
}

//Function that will ask and return the amount of round-trip airfare
double getAirfare(int argc, char*argv[]){
    double airfare = -1; 
    while (airfare < 0)
    {
        printf("What was your total roundtrip airfare cost? ");
        scanf("%lf", &airfare);
        if(airfare<0)
        {
            printf("Sorry dollar amounts can't be negative\n");
        }
    }
    allowableExpenses += airfare;
    return airfare;
}

//Function that will ask and return the amount of any car rentals
double getCarRental(int argc, char*argv[]){
    double carRental = -1; 
    while(carRental < 0)
    {
        printf("What was your total car rental cost? ");
        scanf("%lf", &carRental);
        if(getCarRental<0)
            {
                printf("Sorry dollar amounts can't be negative\n");
            }
    }
    allowableExpenses += carRental;
    return carRental;
}

//Function that will ask for parking fees everyday and return total cost
double getParkingFee(int argc, char*argv[]){
    double totalParkingFee = 0; 
    double dailyParkingFee; 
    int check = 1;

    for(int i =1; i < numDays+1; i++)
    {
        do
        {
            printf("What was the parking fee for day %d? ", i);
            scanf("%lf", &dailyParkingFee);
            if (dailyParkingFee < 0)
            {
                printf("Sorry dollar amounts can't be negative\n");
                check = 0;
            }
            else
            {
                check = 1;
            }
        }while(check==0);
        totalParkingFee += dailyParkingFee;
    }
    allowableExpenses += (numDays*6);
    return totalParkingFee;
}

