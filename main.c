#include <stdio.h>
#include <string.h>
#include "header.h"
#include "RyanTrinh.c"
#include "AndrewGravino.c"
#include "AaronLiban.c"

int numDays;

int main(int argc, char*argv[])
{
    /* Declaring variables */
    double airFare, carRental, parkingFee, mealPrice; 
    double totalExpenses;

    /* Calling functions */
    setDepartureTime();
    setMilesDriven();
    setRegistrationFees();
    numDays = getDays(argc, argv); 
    setTaxiFees(numDays);
    setHotelFees(numDays);
    airFare = getAirfare(argc, argv);
    carRental = getCarRental(argc, argv);
    parkingFee = getParkingFee(argc, argv);
    mealPrice = getOverallMealPrice(argc, argv);

    totalExpenses = airFare + carRental + parkingFee + mileFees + taxiFees + seminar_conferenceCosts + hotelFees + mealPrice; //Calculating total

    /* Printing everything acquired to the terminal for the user */
    printf("\n\n");
    printf("Total Trip Days: %d\n", numDays);
    printf("Departure Time: %d\n Arrival Time: %d\n", firstDepartureTime, lastArrivalTime);
    printf("Airfare: $%.2f\n", airFare);
    printf("Car Rentals: $%.2f\n", carRental);
    printf("Miles driven: %d, and cost: $%.2f\n", miles, mileFees);
    printf("Parking fees: $%.2f\n", parkingFee);
    printf("Taxi fees: $%.2lf\n", taxiFees);
    printf("Conference/Seminar registration fees: $%.2lf\n", seminar_conferenceCosts);
    printf("Hotel expenses: $%.2lf\n", hotelFees);
    printf("Meal costs: $%.2f\n", mealPrice);
    printf("Total expenses: $%.2f\n", totalExpenses);
    printf("Total allowable expenses: $%.2f\n", allowableExpenses);

    if(totalExpenses>allowableExpenses)
    {
        printf("You must reimburse: $%.2f\n",totalExpenses-allowableExpenses);
    }
    else
    {
        printf("You saved: $%.2f\n", allowableExpenses-totalExpenses);
    }
    
}