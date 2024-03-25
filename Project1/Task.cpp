#include <iostream>

using namespace std;

void filling_in_the_vectors
(int* vector, bool* vector_of_values_used, int min, int max);
string convert_to_string(int* vector, bool* vector_of_values_used, int min, int max);
void randomly_initialized_vector
(int* randomly_init_vector, int* vector, bool* vector_of_values_used, int min, int max);

int main() {
	
	int min, max;
	do {
		system("cls");
		cout << "Input range of integer values of vector (min and max): ";
		cin >> min >> max;
	} while (min > max);

	bool* vector_of_values_used;
	int* vector;
	int* randomly_init_vector;
	if (min == max) {
		vector_of_values_used = new bool[1];
		vector = new int[1];
		randomly_init_vector = new int[1];
	}
	else {
		int min_temp = min < 0 ? -min : min;
		int max_temp = max < 0 ? -max : max;
		vector_of_values_used = new bool[min_temp + max_temp + 1];
		vector = new int[min_temp + max_temp + 1];
		randomly_init_vector = new int[min_temp + max_temp + 1];
	}

	filling_in_the_vectors(vector, vector_of_values_used, min, max);

	cout << "Vector elements - "
		 << convert_to_string(vector, vector_of_values_used, min, max) << endl << endl;

	randomly_initialized_vector
	(randomly_init_vector, vector, vector_of_values_used, min, max);

	cout << "elements of a randomly initialized vector:\n"
		<< convert_to_string(randomly_init_vector, vector_of_values_used, min, max) << endl;

	return 0;
}