/*
-The time of departure on the first day of the trip, and the time of arrival back home on the last day of the trip
-Miles driven, if a private vehicle was used. Calculate the vehicle expense as $0.27 per mile driven
-Taxi fees, if a taxi was used anytime during the trip (The company allows up to $10 per day, for each day a taxi was used. Anything more than this must be paid by the employee.)
-Conference or seminar registration fees
-Hotel expenses (The company allows up to $90 per night for lodging. Anything more than this must be paid by the employee.)
*/

#include <stdio.h>
#include "header.h"

// static int firstDepartureTime;
// static int lastArrivalTime;

void setDepartureTime(){
   
   int x, y;
   
   printf("What was the departure time of the trip?: ");
   scanf("%d", &x);
   if(x<1||x>24){
      do{
         printf("Invalid time, please re-enter: ");
         scanf("%d", &x);
      }while(x<1||x>24);
   }
   firstDepartureTime = x;

   printf("What was the arrival time of the trip?: ");
   scanf("%d", &y);
   if(y<1||y>24){
      do{
         printf("Invalid time, please re-enter: ");
         scanf("%d", &y);
      }while(y<1||y>24);
   }
   lastArrivalTime = y;
}


void setMilesDriven(){

   double mileTax = 0.27;
   double mileFees;
   int x;

   printf("How many miles did you drive with a private vehicle?: ");
   scanf("%d", &x);
   // printf("%d\n", x);
   mileFees = x * mileTax;
   
   totalExpenses += mileFees;
   // printf("%f", mileFees);
}


void setTaxiFees(){

   double taxiFees, taxiFeesCovered;

   printf("What is the total amount of taxi fees?: ");
   scanf("%lf", &taxiFees);
   taxiFeesCovered = numDays * 10;

   totalExpenses += taxiFees;
   allowableExpenses += taxiFeesCovered;
}


void setRegistrationFees(){

   double registrationFees;

   printf("What is the total amount of conference or seminar registration fees?: ");
   scanf("%lf", &registrationFees);

   totalExpenses += registrationFees;
}


void setHotelFees(){
   
   double hotelFees, hotelFeesCovered;

   printf("What is the total amount of hotel fees?: ");
   scanf("%lf", &hotelFees);
   hotelFeesCovered = (numDays-1) * 90;

   totalExpenses += hotelFees;
   allowableExpenses += hotelFeesCovered;
}


// This is for testing
// void main(){
   // setDepartureTime();
   // printf("Departure: %d & Arrival: %d", firstDepartureTime, lastArrivalTime);
   // setMilesDriven();
// }
