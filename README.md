
### Course Code Selection Problem Summary

1. **Problem Overview**:
   - I was tasked with processing course enrollment data to manage student choices and detect inversion counts for course selections.
   - The goal was to ensure the data handling was robust, accounting for various edge cases.

2. **Approach**:
   - I decided to implement two separate programs to solve the problem:
     - **Linear Approach**: A straightforward method to process the data, iterating through the course selections.
     - **Divide-and-Conquer Method**: A more efficient algorithm to handle larger datasets, leveraging the divide-and-conquer strategy.

3. **Data Structure**:
   - I planned to copy data from CSV files into a temporary 2D array for processing.
   - I would check for negative values, blank fields, and out-of-range values during the data processing.

4. **Edge Cases Handling**:
   - I suggested using `-1` as a placeholder for blank fields, which would lead to an output of 'N/A' if included in the data.
   - I identified specific edge cases to test, including:
     - Normal data inputs.
     - Duplicate entries.
     - Negative values (considered invalid).
     - Missing data (using `-1` as a placeholder).
     - Out-of-range values (course codes outside the valid range of 1001 to 1005).
     - Empty files.

5. **Output Requirements**:
   - I intended to create an output CSV file displaying 'N/A' for inversion counts in cases of negatives or other edge cases.
   - Additionally, I planned to print results in a console format using an unordered map to track inversion counts.
   - The output format would summarize counts of students with invalid choices, zero inversions, one inversion, etc.

6. **Implementation Goals**:
   - Ensure the code could handle all 100 student data effectively and count inversions accurately.
   - Cap inversion counts appropriately, with an understanding that a completely reverse-sorted array should yield a maximum of four inversions.

7. **Testing and Validation**:
   - I planned to rigorously test the implementation with various cases to ensure accuracy and robustness in handling the enrollment data.

### Integeer multiplication problem

1. **Integer Multiplication Program**:
   - I created a program to multiply large integers using a divide-and-conquer approach, specifically the Karatsuba algorithm.
   - I adjusted the program to handle large integers by using string representation to avoid overflow issues, as C++'s `int` and `long long` types can only handle numbers up to certain limits.

2. **Test Cases**:
   - I provided a comprehensive set of test cases for the multiplication program, covering:
     - **Normal Cases (1-4)**: Both numbers positive, different lengths, and even lengths.
     - **Negative Cases (5-7)**: Various combinations of positive and negative numbers.
     - **Zero Cases (8-10)**: Handling scenarios involving zero.
   - The final list of test cases included:
     ```cpp
     std::vector<std::pair<long long, long long>> testCases = {
         {1, 9},
         {1234567890, 1286608618},
         {12345678, 87},
         {100872863, 292842910},
         {-1234, 53212678},
         {123321234, -5678},
         {-1234567890, -9087654321},
         {0, 5231231678},
         {1232131134, 0},
         {0, 0}
     };
     ```

3. **Program Adjustments**:
   - I modified the program to remove unnecessary `cin` usage since I was providing all test cases in a vector.
   - We discussed potential arithmetic overflow and the need to convert numbers to strings for large integer multiplication.

4. **Debugging Results**:
   - I encountered unexpected results from the program, indicating arithmetic overflow with large numbers.
   - After analysis, I confirmed that the logic was correctly implemented, and we transitioned to using string multiplication to support larger integers appropriately.

5. **Final Program**:
   - The final program used strings for multiplication, correctly handled both positive and negative cases, and printed results for all test cases directly.

6. **Course Problem Discussion**:
   - I shared that I was working on a course problem involving processing course enrollment data.
   - The solution involved using both linear and divide-and-conquer methods to handle the data.
   - I planned to implement edge case handling, such as negative values, blank fields, and out-of-range values.
   - The requirement was to create an output CSV file to track inversion counts and display results in a specific format.

7. **Outcomes**:
   - The integer multiplication program successfully handled large integers and was verified against a calculator for correctness.
   - My approach to the course problem was structured and allowed for testing various edge cases to ensure robustness.
