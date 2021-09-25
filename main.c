#include <stdio.h>
#include <string.h>
#include "header.h"
#include "RyanTrinh.c"

int numDays;

void main(int argc, char*argv[])
{
    numDays = getDays(argc, argv);  
    int parkingFee = getParkingFee(argc, argv);
}

