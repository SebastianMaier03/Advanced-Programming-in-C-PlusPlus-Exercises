![img.png](img.png)s
# Exercise 1: Basics

- These exercises are somewhat similar to Coding Bat exercises and cover basic logic, loops and branches.
- Implement all of the following exercises in a single `.cpp` file
- Make sure to name all of the functions, classes, structs and members exactly the same as described in the exercises. This makes it much easier for us to test your code, since we can just paste some lines calling your functions and look at the results.

## 1. Print dynamic array
 
 - Write a function `void PrintDynamicArray(std::vector<int> arr)`. 
 - The function should print the contents of `arr` to the console in the following format `(x0, x1, x2, x3, x4, ...)` with `xi` being the integers stored in `arr` at index `i`.
 - The function should also add a new line character at the end

 ## 2. Fibonacci Sequence
- Write a function `std::vector<int> Fibonacci(unsigned int amount)`that calculates the Fibonacci Sequence
- The argument `amount` determines how many Fibonacci numbers should be calculated before returning.
- The function returns an `std::vector<int>` that contains the calculated Fibonacci numbers

## 3. Calculate Maximum
 - Write a function `int Maximum(std::vector<int> numbers)`
 - The function should return the maximum number within `numbers`
 - `numbers` can contain any integers, including negative ones.
 - `numbers` is of an arbitrary size
 - If there are no elements within `numbers`, the function should return the minimum value an integer can hold

## 4. Analyze data
- Write a function `Results AnalyzeData(std::vector<float> data)`.
- The function should calculate the following properties for that dynamic array:
    - mean
    - median
    - variance (population)
    - standard deviation (population)
    - minimum value
    - maximum value

- If you are unfamiliar with some of these properties, their formula can easily be found online ;)

- Paste the following code over your function. This struct has six `float` members, that  correspond to the six calculated properties.
```cpp
struct Results
{
    float mean, median, variance, standardDeviation, min, max;
};
```
- Create an instance of this struct at the end of your function, fill it in with your calculated properties and return it.
- **Hint:** to calculate the median, you need to order your vector in ascending order. Since this is a little bit complicated, here is a line of code that does that for you:
  `std::sort(vector.begin(),vector.end());` This requires you to include the algorithm header from the standard library into your cpp file:  `#include <algorithm>`
- **Hint:** Also think about what should happen, when the array has 0 or 1 members.
 
 ## Bonus

 Write the previous functions without using loops`. This exercise is just for practice and is not mandatory, so don't stress too much about it ;)

 # Submission

 Submission is due until 21.04. 23:59. 
 (We are currently looking into a comfortable way for you to submit your exercises and will update this later)