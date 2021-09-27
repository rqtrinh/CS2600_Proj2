/*expenses incurred - money that we spent
excess that must be reimbursed - money that you have to pay for yourself
total allowable expenses - money that the company is giving you
*/

#include <stdio.h>
#include "header.h"

//Function that will determine how much you need overall after all the price changes
int getOverallMealPrice(int argc, char*argv[]){
    double overallMealPrice = 0;
    double tempMealPrice = 0;
    printf("DISCLAIMER: Any meals eaten before leaving or coming back will NOT be covered by the company.\n");
    for(int day = 1; day < numDays+1; day++){
        for(int meal = 1; meal < 4; meal++){
            printf("For day %d, how much did meal %d of the day cost? ", day, meal);
            scanf("%lf", &tempMealPrice);

            if(tempMealPrice < 0){ //no negatives checker
                do{
                    printf("Invalid amount, please re-enter: ");
                    scanf("%lf", &tempMealPrice);
                }while(tempMealPrice < 0);
            }

            if(day == 1){ //first day price exceptions
            //anything before leaving is full price, anything during leaving is free, anything on the day of leaving afterward has a discount
                if(firstDepartureTime < 7 && meal == 1){ //free breakfast
                    allowableExpenses += tempMealPrice;
                    tempMealPrice = 0;
                }
                if(firstDepartureTime < 7 && meal == 2){ //gets discounted lunch
                    allowableExpenses += 12;
                    tempMealPrice -= 12;
                }
                if(firstDepartureTime < 7 && meal == 3){ //gets discounted dinner
                    allowableExpenses += 16;
                    tempMealPrice -= 16;
                }
                
                //breakfast has no discount
                if(firstDepartureTime >= 7 && firstDepartureTime < 12 && meal == 2){ //free lunch
                    allowableExpenses += tempMealPrice;
                    tempMealPrice = 0;
                }
                if(firstDepartureTime >= 7 && firstDepartureTime < 12 && meal == 3){ //gets discounted dinner
                    allowableExpenses += 16;
                    tempMealPrice -= 16;
                }

                //breakfast and lunch have no discount
                if(firstDepartureTime >= 12 && firstDepartureTime < 18 && meal == 3){ //free dinner
                    allowableExpenses += tempMealPrice;
                    tempMealPrice = 0;
                }
            }

            if(day == numDays){ //last day exceptions, anything "outside" the trip isnt what the company owes, it's your own money
                //lunch and dinner have no discount
                if(lastArrivalTime > 8 && lastArrivalTime <= 13 && meal == 1){ //free breakfast
                    allowableExpenses += tempMealPrice;
                    tempMealPrice = 0;
                }

                //dinner has no discount
                if(lastArrivalTime > 13 && lastArrivalTime <= 19 && meal == 2){ //free lunch
                    allowableExpenses += tempMealPrice;
                    tempMealPrice = 0;
                }
                if(lastArrivalTime > 13 && lastArrivalTime <= 19 && meal == 1){ //gets discounted breakfast
                    allowableExpenses += 9;
                    tempMealPrice -= 9;
                }

                if(lastArrivalTime > 19 && meal == 3){ //free dinner
                    allowableExpenses += tempMealPrice;
                    tempMealPrice = 0;
                }
                if(lastArrivalTime > 19 && meal == 1){ //get discounted breakfast
                    allowableExpenses += 9;
                    tempMealPrice -= 9;
                }
                if(lastArrivalTime > 19 && meal == 2){ //gets discounted lunch
                    allowableExpenses += 12;
                    tempMealPrice -= 12;
                }
            }
            
            if(day != 1 && day != numDays){
                if(meal == 1){ //everyday that's not the first and last days has the easy equation
                    tempMealPrice -= 9;
                    allowableExpenses += 9;
                }
                if(meal == 2){
                    tempMealPrice -= 12;
                    allowableExpenses += 12;
                }
                if(meal == 3){
                    tempMealPrice -= 16;
                    allowableExpenses += 16;
                }
            }

            //because the meals before the trip and after the trip dont get covered by the company, they remain full price

            if(tempMealPrice < 0){ //negative checker because the company "allows up to" instead of paying you 9, 12, or 16 each time
                tempMealPrice = 0;
            }
        }
        overallMealPrice += tempMealPrice; //add to overallMealPrice each time all the adjustments (or lack thereof on certain occasions) are finished
    }

    return overallMealPrice; //this is what is incurred at the end for this method
}