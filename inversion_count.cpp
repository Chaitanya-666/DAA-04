#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

// Function to read CSV and fill the 2D vector
bool readCSV(const std::string& file_path, std::vector<std::vector<int>>& data) {
    std::ifstream file(file_path);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return false;
    }

    // Skip the header
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<int> student_courses;

        // Read student ID (ignore for processing)
        std::getline(ss, token, ','); 

        while (std::getline(ss, token, ',')) {
            // Directly check for empty token and assign -1 if empty
            if (token.empty()) {
                student_courses.push_back(-1);  // Use -1 for missing data
            } else {
                // Convert to int
                int course_code = std::stoi(token);
                student_courses.push_back(course_code);
            }
        }

        data.push_back(student_courses);
    }

    return true;
}

// Check for invalid data
bool isInvalidData(const std::vector<int>& courses) {
    for (int course : courses) {
        if (course != -1 && (course < 1001 || course > 1005)) {
            return true;  // Invalid course code
        }
    }
    return false;
}

// Brute Force Inversion Count with bounds checking
int countInversionsBruteForce(const std::vector<int>& courses) {
    int inversions = 0;
    size_t size = courses.size();
    
    for (size_t i = 0; i < size; i++) {
        // Check if the index is within bounds for valid courses
        if (courses[i] == -1 || courses[i] < 1001 || courses[i] > 1005) {
            return -1; // Indicate invalid data
        }

        for (size_t j = i + 1; j < size; j++) {
            // Check if the index is within bounds for valid courses
            if (courses[j] == -1 || courses[j] < 1001 || courses[j] > 1005) {
                return -1; // Indicate invalid data
            }
            if (courses[i] > courses[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

// Main processing function
void processData(const std::string& input_file, const std::string& filename, int approach) {
    std::vector<std::vector<int>> data;
    if (!readCSV(input_file, data)) return;

    std::map<int, int> inversion_count_map;  // Use ordered map for sorted output
    int invalid_data_count = 0;

    for (auto& courses : data) {
        if (isInvalidData(courses)) {
            // Invalid data, count it as invalid
            invalid_data_count++;
            inversion_count_map[-1]++;  // Use -1 for invalid data in the map
            continue;
        }

        // Calculate inversions for valid data
        int inversions = countInversionsBruteForce(courses);
        if (inversions == -1) {
            invalid_data_count++;
            inversion_count_map[-1]++;  // Count as invalid data
            continue;
        }

        inversion_count_map[inversions]++;
    }

    // Ensure 0 inversions is accounted for
    if (inversion_count_map.find(0) == inversion_count_map.end()) {
        inversion_count_map[0] = 0;  // Add 0 inversion count if missing
    }

    // Output to CSV at the specified path
    std::string output_file = "C:\\Users\\Shree\\Documents\\Work and career\\DAA LAB\\DAA-04\\output_" + filename;
    std::ofstream outfile(output_file);
    outfile << "StudentID,InversionCount\n";
    int student_id = 1;
    for (auto& courses : data) {
        if (isInvalidData(courses) || countInversionsBruteForce(courses) == -1) {
            outfile << "Student_" << student_id++ << ",N/A\n";
        } else {
            int inversions = countInversionsBruteForce(courses);
            outfile << "Student_" << student_id++ << "," << inversions << "\n";
        }
    }

    // Console output
    std::cout << "Results via " << (approach == 0 ? "linear" : "divide and conquer") << " approach for file: " << filename << std::endl;
    std::cout << "Students with invalid choices: " << invalid_data_count << std::endl;
    for (const auto& entry : inversion_count_map) {
        if (entry.first == -1) {
            std::cout << "Students with invalid data: " << entry.second << std::endl;
        } else {
            std::cout << "Students with " << entry.first << " inversion count: " << entry.second << std::endl;
        }
    }
}

int main() {
    std::string input_file = "C:\\Users\\Shree\\Documents\\Work and career\\DAA LAB\\DAA-04\\courses8.csv";
    std::string filename = "courses8.csv"; // Modify this variable as needed
    int approach = 1; // 0 for linear, 1 for divide and conquer
    processData(input_file, filename, approach);
    return 0;
}
