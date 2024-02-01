#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// Using a namespace to prevent potential naming conflicts and to logically group
// associated functionalities.
namespace SalaryUtils {

    /**
    * @struct Employee
    * Represents an employee with their last name, first name, current salary, and percent pay increase.
    */
    struct Employee {
        std::string lastName;
        std::string firstName;
        double currentSalary;
        double payIncrease;
    };

    /**
    * Reads employee data from a file and updates their salaries based on the pay increase.
    *
    * @param inputFile The name of the input file containing employee data.
    * @param outputFile The name of the output file to store the updated employee data.
    * @throws std::runtime_error if there is an error opening or reading from the input file.
    */
    void UpdateSalaries(const std::string& inputFile, const std::string& outputFile) {
        std::ifstream input(inputFile);
        if (!input) {
            throw std::runtime_error("Failed to open input file: " + inputFile);
        }

        std::ofstream output(outputFile);
        if (!output) {
            throw std::runtime_error("Failed to open output file: " + outputFile);
        }

        std::string lastName;
        std::string firstName;
        double currentSalary;
        double payIncrease;

        while (input >> lastName >> firstName >> currentSalary >> payIncrease) {
            // Calculate the updated salary
            double updatedSalary = currentSalary + (currentSalary * payIncrease / 100);

            // Write the updated employee data to the output file
            output << std::fixed << std::setprecision(2) << firstName << " " << lastName << " " << updatedSalary << std::endl;
        }

        // Close the input and output files
        input.close();
        output.close();
    }
}

int main() {
    try {
        // Update the salaries and store the updated data in SalaryOut.txt
        SalaryUtils::UpdateSalaries("SalaryData.txt", "SalaryOut.txt");
        std::cout << "Salaries updated successfully." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}  