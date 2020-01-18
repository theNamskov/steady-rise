/** 
 * This program finds the minimum sub-array needed to be sorted to keep a super-array sorted entirely.
 * 
 * HOW IT IS APPROACHED
 * - We first find a wrong order in the ascending style of arrangement of the entire array
 *   that is also the least in value as compared to other wrong orders. e.g in [3, 8, 6, 9, 2, 10, 12],
 *   6 is supposed to come before 8, but more importantly 2 should come before 9 and even 3 for that matter.
 *   Hence, we choose 2 as the anomaly and return it, along with its location for iteration purposes.
 * 
 * - We find the wrong order in the descending style of arrangement of the entire array
 *   that is also the greatest in value as compared to other wrong orders. e.g in [25, 40, 32, 31, 35, 50, 60],
 *   32 is supposed to come after 35, but more importantly 40 should come after 32 and even 35 for that matter.
 *   Hence, we choose 40 as the anomaly and return it, along with its location for iteration purposes.
 * 
 * - With the location and value of the least anomaly in hand, we iterate towards the beginning of the super array
 *   to find the least index appropriate for the anomaly to lie, e.g in [3, 8, 6, 9, 2, 10, 12], 2 is appropriately
 *   supposed to be at the first position in the super array, which is index 0.
 * 
 * - We do similar with the value of the greatest anomaly and iterate towards the end of the super array to find the most
 *   appropriate location for the anomaly to rest, e.g in [25, 40, 32, 31, 35, 50, 60], 40 moves past 32, 31 and 35 and is
 *   appropriately supposed to rest at the last-but-twoth index(index 4).
 * 
 * - Program then returns the lower and upper boundaries of the sub-array needed to be sorted
 * 
 *  Complexity - O(n)
*/

#include <iostream>
#include <vector>


// Returns a vector(array) containing value and location of lowest inconsistency in order of arrangement
std::vector<int64_t> findLowestAnomaly(std::vector<int64_t> &unsorted, int unsortedSize) {

    std::vector<int64_t> lowestAnomalyAndIndex = { INT64_MAX, 0 };
    int currVal = 0, nextVal = 0;

    for(int i = 0; i < unsortedSize - 1; ++i) {
        
        currVal = unsorted[i];
        nextVal = unsorted[i + 1];

        if(nextVal < currVal && nextVal < lowestAnomalyAndIndex[0]) {
            lowestAnomalyAndIndex[0] = nextVal;
            lowestAnomalyAndIndex[1] = i + 1;
        }
    }
    
    return lowestAnomalyAndIndex;
};

// Returns a vector(array) containing value and location of largest inconsistency in arrangement
std::vector<int64_t> findHighestAnomaly(std::vector<int64_t> &unsorted, int unsortedSize) {

    std::vector<int64_t> highestAnomalyAndIndex = { INT64_MIN, 0 };
    int currVal = 0, nextVal = 0;

    for(int i = unsortedSize - 1; i > 0; i--) {
        
        currVal = unsorted[i];
        nextVal = unsorted[i - 1];

        if(nextVal > currVal && nextVal > highestAnomalyAndIndex[0]) {
            highestAnomalyAndIndex[0] = nextVal;
            highestAnomalyAndIndex[1] = i - 1;
        }
    }
    
    return highestAnomalyAndIndex;
};

// Returns lower boundary of minimum sub-array needed to be sorted
int findLowerBoundary(
        std::vector<int64_t> &unsorted, 
        int unsortedSize, 
        std::vector<int64_t> &lowAnomaly, 
        int lowAnomalySize
    ) {
    
    int lBound = 0,
        lowAnomaly_idx = lowAnomaly[1];

    for(int i = lowAnomaly_idx - 1; i >= 0; i--) {
        if(unsorted[i] > lowAnomaly[0])
            lBound = i;
    }

    return lBound;
};

// Returns upper boundary of minimum sub-array needed to be sorted
int findUpperBoundary(
        std::vector<int64_t> &unsorted, 
        int unsortedSize, 
        std::vector<int64_t> &highAnomaly, 
        int highAnomalySize
    ) {
    
    int hBound = 0,
        highAnomaly_idx = highAnomaly[1];

    for(int i = highAnomaly_idx + 1; i < unsortedSize; ++i) {
        if(unsorted[i] < highAnomaly[0])
            hBound = i;
    }
    
    return hBound;
};

// Main
int main( void ) {

    std::vector<int64_t> specimen = { 10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60 };
    int specimenSize = specimen.size();

    std::vector<int64_t> anomalyData_L = findLowestAnomaly(specimen, specimenSize);
    std::vector<int64_t> anomalyData_H = findHighestAnomaly(specimen, specimenSize);
    int anomalyDataSize = 2;

    int lowerBoundary = findLowerBoundary(specimen, specimenSize, anomalyData_L, anomalyDataSize),
        upperBoundary = findUpperBoundary(specimen, specimenSize, anomalyData_H, anomalyDataSize);

    std::cout << "\nLower Boundary: " << lowerBoundary 
              << ", Upper Boundary: " << upperBoundary 
              << '\n';

    return EXIT_SUCCESS;
}