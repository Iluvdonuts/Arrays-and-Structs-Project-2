#include <iostream>
#include <fstream>
#include <iomanip>

const int NUM_RUNNERS = 5;
const int DAYS_IN_WEEK = 7;

struct Runner {
	std::string name;
	int milesRun[DAYS_IN_WEEK];
	int totalMiles;
	double averageMiles;
};

void readDataFromFile(Runner runners[]);
void calculateTotalsAndAverages(Runner runners[]);
void outputResults(const Runner runners[]);

int main() {
	Runner runners[NUM_RUNNERS];

	readDataFromFile(runners);
	calculateTotalsAndAverages(runners);
	outputResults(runners);

	return 0;
}

void readDataFromFile(Runner runners[]) {
	std::ifstream inputFile("input_data.txt");
	if (!inputFile) {
		std::cerr << "Error: Unable to open Input file. \n";
		exit(1);
	}

	for (int i = 0; i < NUM_RUNNERS; ++i) {
		inputFile >> runners[i].name;
		for (int j = 0; j < DAYS_IN_WEEK; ++j) {
			inputFile >> runners[i].milesRun[j];
			
		}
	}

	inputFile.close();
}

void calculateTotalsAndAverages(Runner runners[]) {
	for (int i = 0; i < NUM_RUNNERS; ++i) {
		runners[i].totalMiles = 0;
		for (int j = 0; j < DAYS_IN_WEEK; ++j) {
			runners[i].totalMiles += runners[i].milesRun[j];
		}
		runners[i].averageMiles = static_cast<double>(runners[i].totalMiles) / DAYS_IN_WEEK;
	}
}

void outputResults(const Runner runners[]) {
	std::cout << std::setw(15) << std::left << "Runner";
	for (int day = 0; day < DAYS_IN_WEEK; ++day) {
		std::cout << std::setw(8) << std::right << "Day " << day + 1;
	}
	std::cout << std::setw(12) << std::right << "Total";
	std::cout << std::setw(12) << std::right << "Average\n";

	for (int i = 0; i < NUM_RUNNERS; ++i) {
		std::cout << std::setw(15) << std::left << runners[i].name;
		for (int j = 0; j < DAYS_IN_WEEK; ++j) {
			std::cout << std::setw(8) << std::right << runners[i].milesRun[j];
		}
		std::cout << std::setw(12) << std::right << runners[i].totalMiles;
		std::cout << std::setw(12) << std::right << std::fixed << std::setprecision(2) << runners[i].averageMiles << "\n";
	}
}

