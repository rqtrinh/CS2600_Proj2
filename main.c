#include <stdio.h>
#include <string.h>
#include "header.h"
#include "RyanTrinh.c"
#include "AndrewGravino.c"
#include "AaronLiban.c"

int numDays;

void main(int argc, char*argv[])
{
    int airFare, carRental, parkingFee;
    double totalExpenses;


    numDays = getDays(argc, argv); 
    airFare = getAirfare(argc, argv);
    carRental = getCarRental(argc, argv);
    parkingFee = getParkingFee(argc, argv);

    totalExpenses = airFare + carRental + parkingFee;

    printf("Total expenses: $%f\n", totalExpenses);
    printf("Total allowable expenses: $%f\n", allowableExpenses);

    if(totalExpenses>allowableExpenses)
    {
        printf("You must reimburse: $%f\n",totalExpenses-allowableExpenses);
    }
    else
    {
        printf("You saved: $%f\n", allowableExpenses-totalExpenses);
    }
    


}

