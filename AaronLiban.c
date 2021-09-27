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
   
   printf("What was the departure time of the trip in military time?: ");
   scanf("%d", &x);
   if(x<1||x>24){
      do{
         printf("Invalid time, please re-enter: ");
         scanf("%d", &x);
      }while(x<1||x>24);
   }
   firstDepartureTime = x;

   printf("What was the arrival time of the trip in military time?: ");
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
   int x;

   printf("How many miles did you drive with a private vehicle?: ");
   scanf("%d", &x);
   if(x<0){
      do{
         printf("Invalid number, please re-enter: ");
         scanf("%d", &x);
      }while(x<0);
   }
   miles = x;
   // printf("%d\n", x);
   mileFees = x * mileTax;
}


void setTaxiFees(numDays){

   double x;
   taxiFees = 0;

   for(int i=1;i<=numDays;i++){
      printf("What is the amount of taxi fees on day %d?: ", i);
      scanf("%lf", &x);
      if(x<0){
         do{
            printf("Invalid number, please re-enter: ");
            scanf("%lf", &x);
         }while(x<0);
      }
      if(x>0){
         taxiFees += x;
         taxiFeesCovered += 10;
      }
   }
   allowableExpenses += taxiFeesCovered;
}


void setRegistrationFees(){

   double registrationFees;

   printf("What is the total amount of conference or seminar registration fees?: ");
   scanf("%lf", &registrationFees);
   if(registrationFees<0){
      do{
         printf("Invalid number, please re-enter: ");
         scanf("%lf", &registrationFees);
      }while(registrationFees<0);
   }
   seminar_conferenceCosts = registrationFees;
}


void setHotelFees(numDays){
   
   double x;

   printf("What is the total amount of hotel fees?: ");
   scanf("%lf", &x);
   if(x<0){
      do{
         printf("Invalid number, please re-enter: ");
         scanf("%lf", &hotelFees);
      }while(hotelFees<0);
   }
   hotelFees = x;
   hotelFeesCovered = (numDays-1) * 90;

   allowableExpenses += hotelFeesCovered;
}


// This is for testing
// void main(){
   // setDepartureTime();
   // printf("Departure: %d & Arrival: %d", firstDepartureTime, lastArrivalTime);
   // setMilesDriven();
// }
