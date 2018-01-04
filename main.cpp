#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <cstring>
#include <ctime>
#include "Search.h"  // With value_type defined as an int

using namespace std;

void printArray(Search s);

int main( )
{
    int loopCount = 10000;
    int secToMicro = 1000000;
    Search s(10000);
    int size = s.getSize();
    int r = rand() % size;

    s.set_seed(10);

    //unsorted array search
    s.init_array();

    //sequential search
    clock_t start = clock();
    bool usFinding = false;
    for (int i = 0; i < loopCount; i++){
        usFinding = s.sequential_find(r);
    }
    clock_t end = clock();
    float usDiff = static_cast<float>(end - start)/ CLOCKS_PER_SEC * secToMicro;

    //recursive binary search
    start = clock();
    bool urFinding = false;
    for (int i = 0; i < loopCount; i++){
        urFinding = s.recursive_binary_find(r);
    }
    end = clock();
    float urDiff = static_cast<float>(end - start)/ CLOCKS_PER_SEC * secToMicro;

   //iterative binary search
    start = clock();
    bool uiFinding = false;
    for (int i = 0; i < loopCount; i++){
        uiFinding = s.iterative_binary_find(r);
    }
    end = clock();
    float uiDiff = static_cast<float>(end - start)/ CLOCKS_PER_SEC * secToMicro;

   //sorted array search
    s.init_sorted_array();

   //sequential search
    start = clock();
    bool ssFinding = false;
    for (int i = 0; i < loopCount; i++){
        ssFinding = s.sequential_find(r);
    }
    end = clock();
    float ssDiff = static_cast<float>(end - start)/ CLOCKS_PER_SEC * secToMicro;

    //recursive binary search
    start = clock();
    bool srFinding = false;
    for (int i = 0; i < loopCount; i++){
        srFinding = s.recursive_binary_find(r);
    }
    end = clock();
    float srDiff = static_cast<float>(end - start)/ CLOCKS_PER_SEC * secToMicro;

    //iterative binary search
    start = clock();
    bool siFinding = false;
    for (int i = 0; i < loopCount; i++){
        siFinding = s.iterative_binary_find(r);
    }
    end = clock();
    float siDiff = static_cast<float>(end - start)/ CLOCKS_PER_SEC * secToMicro;

    cout << "Results:" << endl;
    cout << "Loop Count: " << loopCount << endl;
    cout << "Array Size: " << size << endl;
    cout << "Search Value: " << r << "\n \n";

    cout << "Unsorted Array: " << endl;
    cout << "Sequential: " << usDiff << " microseconds" <<endl;
    cout << "Recursive Binary: " << urDiff << " microseconds" <<endl;
    cout << "Iterative Binary: " << uiDiff << " microseconds" <<"\n \n";

    cout << "Sorted Array: " << endl;
    cout << "Sequential: " << ssDiff << " microseconds" <<endl;
    cout << "Recursive Binary: " << srDiff << " microseconds" <<endl;
    cout << "Iterative Binary: " << siDiff << " microseconds" <<"\n \n";

    //printArray(s);


    return EXIT_SUCCESS;
}

void printArray(Search s){
    cout << s;

}
