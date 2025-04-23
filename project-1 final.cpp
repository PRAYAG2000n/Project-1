#include <iostream>
#include <climits>
#include <algorithm>
#include <array>

const int MAX_N = 45;  // Maximum number of elements in array A
const int MAX_M = 55;  // Maximum number of groups

std::array<int, MAX_N + 1> A;  // Input array
std::array<std::array<int, MAX_M + 1>, MAX_N + 1> dpTable;  // DP table
std::array<std::array<int, MAX_M + 1>, MAX_N + 1> partitionTable;  // To store group partitions 

// Function to compute the sum of elements
int FindSum(int port, int dexter, const std::array<int, MAX_N + 1>& prefixSums) {
    return prefixSums[dexter] - prefixSums[port - 1];
}

// Dynamic programming function to solve the problem
int max_min_grouping(int N, int M) {
    std::array<int, MAX_N + 1> prefixSums = { 0 };  // Prefix sum array

    // Compute prefix sums
    for (int i = 1; i <= N; ++i) {
        prefixSums[i] = prefixSums[i - 1] + A[i];
    }

    // Initialize dp table
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            dpTable[i][j] = INT_MIN;
        }
    }
    dpTable[0][0] = INT_MAX;

    // Fill dp table 
    for (int j = 1; j <= M; ++j) {
        for (int i = 1; i <= N; ++i) {
            int max_min_v = INT_MIN;
            int optimal_p = 1;

            for (int k = j - 1; k < i; ++k) {
                int current_sum = FindSum(k + 1, i, prefixSums);
                int min_v = std::min(dpTable[k][j - 1], current_sum);

                if (min_v > max_min_v) {
                    max_min_v = min_v;
                    optimal_p = k;
                }
            }

            dpTable[i][j] = max_min_v;
            partitionTable[i][j] = optimal_p;
        }
    }

    // Construct the optimal sizes (G) and optimal sums (B) from the `groupTable`
    int i = N;
    int j = M;
    std::array<int, MAX_M + 1> G;  // Array for optimal sizes
    std::array<int, MAX_M + 1> B;  // Array for optimal sums
    while (j > 0) {
        int start = partitionTable[i][j] + 1;
        G[j] = i - start + 1;
        B[j] = FindSum(start, i, prefixSums);
        i = partitionTable[i][j];
        --j;
    }



    std::cout << "Optimal sizes: ";
    for (int k = 1; k <= M; ++k) {
        std::cout << G[k] << " ";
    }
    std::cout << std::endl;

    std::cout << "Optimal sums: ";
    for (int k = 1; k <= M; ++k) {
        std::cout << B[k] << " ";
    }
    std::cout << std::endl;

    return dpTable[N][M];
}

int main() {
    int N, M;

    // Prompt user for the size of array A
    std::cout << "Enter the size of array A: ";
    std::cin >> N;

    std::cout << "Enter the elements of array A: ";
    for (int i = 1; i <= N; ++i) {
        std::cin >> A[i];
    }

    std::cout << "Enter the number of groups (M): ";
    std::cin >> M;

    int result = max_min_grouping(N, M);
    std::cout << "The maximum minimum sum is: " << result << std::endl;

    // Pause the program before it closes
    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}