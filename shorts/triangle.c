#include <cs50.h>
#include <stdio.h>


bool valid_triangle(float i, float j, float k);

int main(void)
{
    // printf("Enter the length of one side: ");
    float i;
    i = get_float("Enter the length of one side: ");
    // printf("Enter the length of side 2: ");
    float j;
    j = get_float("Enter the length of side 2: ");
    // printf("Enter the length of side 3: ");
    float k;
    k = get_float("Enter the length of side 3: ");

    bool triangle = valid_triangle(i, j, k);

    if (triangle)
    {
        printf("This is a valid triangle.\n");
    }
    else
    {
        printf("This is not a valid triangle.\n");
    }

}

bool valid_triangle(float i, float j, float k)
{
    bool positive;
    bool sides;

    if (i > 0 && j > 0 && k > 0)
    {
        positive = true;
    }
    else
    {
        positive = false;
    }
    if (i + j > k && i + k > j && j + k > i)
    {
        sides = true;
    }
    else
    {
        sides = false;
    }


    if (positive == true && sides == true)
    {
        return true;

    }
    else
    {
        return false;
    }
}
