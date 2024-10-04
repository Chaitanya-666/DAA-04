#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Function to generate random course codes for each student
std::vector<int> generateRandomCourses(const std::vector<int>& course_pool, int num_courses) {
    std::vector<int> courses(course_pool);
    std::random_shuffle(courses.begin(), courses.end());  // Shuffle the pool
    std::vector<int> selected_courses(courses.begin(), courses.begin() + num_courses);  // Select the first 'num_courses' elements
    return selected_courses;
}

// Function to randomly introduce negative course codes
void introduceNegativeCourseCodes(std::vector<int>& courses, double probability_of_negative) {
    for (int& course : courses) {
        if ((std::rand() % 100) < (probability_of_negative * 100)) {
            course = -course;  // Make the course code negative
        }
    }
}

// Function to randomly remove course codes (simulate missing data)
void introduceMissingData(std::vector<int>& courses, double probability_of_missing) {
    for (int& course : courses) {
        if ((std::rand() % 100) < (probability_of_missing * 100)) {
            course = 0;  // Represent missing data with 0 (can be left empty too)
        }
    }
}

// Function to introduce out-of-range course codes
void introduceOutOfRangeCourses(std::vector<int>& courses, double probability_of_out_of_range) {
    for (int& course : courses) {
        if ((std::rand() % 100) < (probability_of_out_of_range * 100)) {
            course = 2000 + (std::rand() % 100);  // Assign an out-of-range code like 2000+
        }
    }
}

int main() {
    // Specify the custom file path
    std::string file_path = "C:\\Users\\Shree\\Documents\\Work and career\\DAA LAB\\DAA-04\\courses8.csv";
    std::ofstream file(file_path);

    if (!file.is_open()) {
        std::cerr << "Unable to open file for writing." << std::endl;
        return 1;
    }

    // Define course pool and number of students
    std::vector<int> course_pool = {1001, 1002, 1003, 1004, 1005};  // Only 5 course codes now
    int num_students = 100;
    int num_courses = 5;  // Each student normally gets exactly 5 courses
    double probability_of_negative = 0.2;  // 20% chance of negative course code
    double probability_of_missing = 0.1;   // 10% chance of missing data
    double probability_of_out_of_range = 0.1;  // 10% chance of out-of-range course code

    std::srand(std::time(0));  // Seed for randomness

    // Flags to control test cases
    bool create_empty_file = true;
    bool add_negative = false;  // Flag to add negative course codes
    bool add_missing = false;   // Flag to add missing data
    bool add_out_of_range = false;  // Flag to add out-of-range course codes

    // Write CSV header
    file << "StudentID,Course1,Course2,Course3,Course4,Course5\n";

    // If the empty file flag is false, generate data for students
    if (!create_empty_file) {
        // Generate data for each student
        for (int i = 1; i <= num_students; ++i) {
            file << "Student_" << i;  // Write Student ID

            // Get random courses
            std::vector<int> courses = generateRandomCourses(course_pool, num_courses);

            // Introduce negative course codes if flag is set
            if (add_negative) {
                introduceNegativeCourseCodes(courses, probability_of_negative);
            }

            // Introduce missing data if flag is set
            if (add_missing) {
                introduceMissingData(courses, probability_of_missing);
            }

            // Introduce out-of-range course codes if flag is set
            if (add_out_of_range) {
                introduceOutOfRangeCourses(courses, probability_of_out_of_range);
            }

            // Write each course to the file
            for (int course : courses) {
                if (course == 0) {
                    file << ",";  // Simulate missing data
                } else {
                    file << "," << course;  // Write the course or negative/out-of-range code
                }
            }
            file << "\n";  // New line for next student
        }
    }

    file.close();  // Close file
    std::cout << "CSV file has been generated and saved at: " << file_path << std::endl;

    return 0;
}
