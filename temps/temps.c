// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
} avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
int city_count = NUM_CITIES, MAX_TEMP = 200; // all temperatures must be lower than 200 degrees
void sort_cities(void)
{
    string low_city;
    int low_temp = MAX_TEMP, low_index;
    // checks if search is complete
    if (city_count == 0)
    {
        return;
    }
    for (int i = 0; i < city_count; i++)
    {
        // finds lowest temperature
        if (temps[i].temp < low_temp)
        {
            low_temp = temps[i].temp;
            low_city = temps[i].city;
            low_index = i;
        }
    }
    // swaps value in highest remaining position with lowest value
    temps[low_index].temp = temps[city_count - 1].temp;
    temps[low_index].city = temps[city_count - 1].city;
    // swaps value of lowest city and temp with highest index position
    temps[city_count - 1].temp = low_temp;
    temps[city_count - 1].city = low_city;
    // eliminates last position from next search and performs next iteration
    city_count -= 1;
    sort_cities();
}
