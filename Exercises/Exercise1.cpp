#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <valarray>

//Exercise1
void PrintDynamicArray(std::vector<int> arr) {
    std::cout << "(";

    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i != arr.size() - 1) {
            std::cout << ", ";
        }
    }

    std::cout << ")" << std::endl;
}
//Exercise2
std::vector<int> Fibonacci(unsigned int amount) {
    std::vector<int> fibSeq;
    if (amount == 0) {
        return fibSeq;
    }

    fibSeq.push_back(0);
    if (amount == 1) {
        return fibSeq;
    }

    fibSeq.push_back(1);

    for (unsigned int i = 2; i < amount; ++i) {
        int nextFib = fibSeq[i - 1] + fibSeq[i - 2];
        fibSeq.push_back(nextFib);
    }

    return fibSeq;
}
//Exercise3
int Maximum(std::vector<int> numbers) {
    if (numbers.empty()) {
        return std::numeric_limits<int>::min();
    }
    int max = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    return max;
}

//Exercise4
struct Results
{
    float mean, median, variance, standardDeviation, min, max;
};

Results AnalyzeData(std::vector<float> data) {
    Results results{};

    if (data.empty()) {
        results.mean = results.median = results.variance = results.standardDeviation = results.min = results.max = NAN;
        return results;
    }

    float sum = 0.0f;
    for (float value : data) {
        sum += value;
    }
    results.mean = sum / data.size();

    std::sort(data.begin(), data.end());
    if (data.size() % 2 == 0) {
        results.median = (data[data.size() / 2 - 1] + data[data.size() / 2]) / 2.0f;
    } else {
        results.median = data[data.size() / 2];
    }

    float mean = results.mean;
    float variance = 0.0f;
    for (float value : data) {
        variance += (value - mean) * (value - mean);
    }
    results.variance = variance / data.size();

    results.standardDeviation = std::sqrt(results.variance);

    results.min = *std::min_element(data.begin(), data.end());
    results.max = *std::max_element(data.begin(), data.end());

    return results;
}
int main() {
    //Exercise1
    std::vector<int> test2 = {1, 2, 3, 4, 5};
    std::cout << "Exercise1"<< std::endl;
    PrintDynamicArray(test2);
    std::cout << ""<< std::endl;


    //Exercise2
    std::cout << "Exercise2"<< std::endl;
    unsigned int amount = 10;
    std::vector<int> fibonacciSequence = Fibonacci(amount);

    for (int num : fibonacciSequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << ""<< std::endl;


    //Exercise3
    std::cout << "Exercise3"<< std::endl;
    std::vector<int> test3 = {-1, 2, 3, 4, -5};
    int max = Maximum(test3);
    std::cout << max << std::endl;
    std::cout << ""<< std::endl;


    //Exercise4
    std::cout << "Exercise4"<< std::endl;
    std::vector<float> test5 = {-1.5, 2.9, 3.9, 4.4, -5.5,7.7777,55.2};

    Results results = AnalyzeData(test5);

    std::cout << "\nResults:\n";
    std::cout << "Mean: " << results.mean << std::endl;
    std::cout << "Median: " << results.median << std::endl;
    std::cout << "Variance: " << results.variance << std::endl;
    std::cout << "Standard Deviation: " << results.standardDeviation << std::endl;
    std::cout << "Min: " << results.min << std::endl;
    std::cout << "Max: " << results.max << std::endl;

    return 0;

}