#include <iostream>
#include <string>

using namespace std;

void filling_in_the_vectors
		(int* vector, bool* vector_of_values_used, int min, int max) {
	if (min > max) {
		int t = min;
		min = max;
		max = t;
	}
	for (int i = min; i <= max; i++) {
		*(vector + i - min) = i;
		*(vector_of_values_used + i - min) = true;
	}
}

string convert_to_string(int* vector, int min, int max) {
	if (min > max) {
		int t = min;
		min = max;
		max = t;
	}

	string msg = "";

	for (int i = min; i <= max; i++) {
		msg += to_string(*(vector + i - min)) + " ";
	}

	return msg;
}