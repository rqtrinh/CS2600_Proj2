//Include necessary libraries
#include <stdio.h>



//Function that will ask and return number of days on trip
int getDays(int argc, char*argv[]){
    int days; 
    printf("What was the total number of days spent on the trip?");
    scanf("%d", &days);
    return days;
}

//Function that will ask and return the amount of round-trip airfare
int getAirfare(int argc, char*argv[]){
    int airfare; 
    printf("What was your roundtrip airfare cost?");
    scanf("%d", &airfare);
    return airfare;
}

//Function that will ask and return the amount of any car rentals
int getCarRental(int argc, char*argv[]){
    int carRental; 
    printf("What was your car rental cost?");
    scanf("%d", &carRental);
    return carRental;
}