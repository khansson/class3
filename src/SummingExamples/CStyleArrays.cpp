
#include <cmath>

#include "SummingExamples.hpp"

double CStyle()
{

    /* defintatly don't want this

double TestArray[1000];

for( int i = 0; i < 1000 ; i ++)
{
    etc...
}


You will make a typo if you manually track the 1000
    */

    /*This will not compile
     const int Size
        double TestArray[Size];

        */

    // need constexpr
    constexpr int Size = 1000;
    double TestArray[Size];

    // need for loop to fill

    for (int i = 0; i < Size; i++)
    {
        TestArray[i] = std::sqrt(2) * i;
    }

    //blow up your code in a way you can debug  
    // TestArray[2000] = 5; 

    // need a loop to do the sum
    double sum{0};

    for (int i = 0; i < Size; i++)
    {
        sum += TestArray[i];
    }

    return sum;
}




double CStyle(int Size)
{


    double * TestArray =   new double[Size];

    // need for loop to fill

    for (int i = 0; i < Size; i++)
    {
        TestArray[i] = std::sqrt(2) * i;
    }

    //blow up your code in a way you can debug  
    // TestArray[2000] = 5; 

    // need a loop to do the sum
    double sum{0};

    for (int i = 0; i < Size; i++)
    {
        sum += TestArray[i];
    }

    delete[] TestArray;

    return sum;
}

