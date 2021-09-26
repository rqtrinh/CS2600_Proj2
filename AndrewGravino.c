//hello
//this is where im working

#include <stdio.h>

//Function that will determine how much 
int getMealAmount(int argc, char*argv[]){
    int numDays;
    int firstDepartureTime;
    int lastDepartureTime;
    double overallMealPrice = 0;
    double tempMealPrice = 0;
    for(int day = 1; day < numDays+1; day++){
        for(int meal = 1; meal < 4; meal++){
            printf("For day %d, how much did meal %d of the day cost?: ", day, meal);
            scanf("%lf", tempMealPrice);

            if(tempMealPrice < 0){ //no negatives checker
                do{
                    printf("Invalid amount, please re-enter: ");
                    scanf("%lf", &tempMealPrice);
                }while(tempMealPrice < 0);
            }

            if(day == 0){ //first day price exceptions
            //regardless of number of meals when leaving, we start counting money once the trip begins
                if(firstDepartureTime < 7 && meal == 1){
                    tempMealPrice = 0;
                }
                if(firstDepartureTime >= 7 && firstDepartureTime < 12 && meal == 2){
                    tempMealPrice = 0;
                }
                if(firstDepartureTime >= 12 && firstDepartureTime < 18 && meal == 3){
                    tempMealPrice = 0;
                }
            }

            if(day == numDays){ //last day exceptions
            //regardless of number of meals when arriving, anything "outside" the trip isnt what the company owes, it's your own money
                if(lastDepartureTime > 8 && lastDepartureTime <= 13 && meal == 1){
                    tempMealPrice = 0;
                }
                if(lastDepartureTime > 13 && lastDepartureTime <= 19 && meal == 2){
                    tempMealPrice = 0;
                }
                if(lastDepartureTime > 19 && meal == 3){
                    tempMealPrice = 0;
                }
            }

            if(meal == 1){ //this accounts for the beginning and last days where they could leave
            //early in the day and their next meals like dinner are just discounted rather than fully covered
                tempMealPrice -= 9;
            }
            if(meal == 2){
                tempMealPrice -= 12;
            }
            if(meal == 3){
                tempMealPrice -= 16;
            }

            if(tempMealPrice < 0){ //negative checker because the company "allows up to" instead of paying you 9, 12, or 16 each time
                tempMealPrice = 0;
            }

        }
        overallMealPrice += tempMealPrice; //add to overallMealPrice each time the iteration finishes
    } //then after the loops terminates, we have all the added values we need
    return overallMealPrice; //this is what is incurred at the end for this method
}

//add a method that grabs you the original meal price without all the discounts
//like 2000 dollars you paid but it returns 3000

//add a method that shows you how much you saved via company expenses on meals
//like 2000 dollars paid and so it returns 1000