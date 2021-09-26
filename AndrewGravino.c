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
            //regardless of number of meals when leaving, anything "outside" the trip isnt what the company owes, it's your own money
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

            if(day != 0 && day != numDays){ //everyday exceptions
                if(meal == 1){
                    tempMealPrice -= 9;
                }
                if(meal == 2){
                    tempMealPrice -= 12;
                }
                if(meal == 3){
                    tempMealPrice -= 16;
                }

            }

            if(tempMealPrice < 0){ //negative checker because the company "allows up to" instead of paying you 9, 12, or 16 each time
                tempMealPrice = 0;
            }

        }
        overallMealPrice += tempMealPrice; //add overallMealPrice once the first for loop terminates
}