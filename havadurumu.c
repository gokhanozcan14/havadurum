#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define days 30
#define regions 7
            int toplam;

// random temp for region
void generateTemperature(float *sicaklik) {
    *sicaklik = (float)(rand() % 16) + 10.0; // random number generator
}

// function to fill the 2D array
void fillTemperature(float table[days][regions + 1])
{
	int i = 0; 
    for (i=0; i < days; i++) 
	{
        table[i][0] = i + 1; // set the day number in the first column
        int j;
        for (j = 1; j <= regions; j++) {
            float temp;
            generateTemperature(&temp); // generate random temperature for the region
            table[i][j] = temp; // assign the temperature to the table
        }
    }
}

//2D array table
void printTable(float table[days][regions + 1]) {
    printf("Day\tRegion 1\tRegion 2\tRegion 3\tRegion 4\tRegion 5\tRegion 6\tRegion 7\n");
    int i = 0;
    for (i=0; i < days; i++) {
        printf("%d\t", (int)table[i][0]); // print day number
        int j = 1;
        for (j=1; j <= regions; j++) {
            printf("%8.1f\t", table[i][j]); // print temperature for region j on day i
        }
        printf("\n");
    }
}

// max min and avg
void printReport(float table[days][regions + 1]) 
{
    printf("Region\tMax\tMin\tAverage\n");
    int i = 1;
    for (i=1; i <= regions; i++) {
        float max = -999.0, min = 999.0, sum = 0.0, avg;
        int j = 0;
        for (j=0; j < days; j++) {
            float sicaklik = table[j][i];
            if (sicaklik > max) max = sicaklik; // max temperature
            if (sicaklik < min) min = sicaklik; // min temperature
            toplam += sicaklik; // average temp
        }
        avg = toplam / days; // calculate average temperature
        printf("%d\t%.1f\t%.1f\t%.1f\n", i, max, min, avg); // print region statistics
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator

    float table[days][regions + 1]; // 2D array to store temperature data

    fillTemperature(table); // generate random temperatures for each day and region

    printTable(table); // print the table
    printReport(table); // print the region statistics

    return 0;
}
