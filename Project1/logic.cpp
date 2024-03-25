#include <iostream>
#include <time.h>

using namespace std;

string convert_to_string(int* vector, bool* vector_of_values_used, int min, int max);

void randomly_initialized_vector
	(int* randomly_init_vector,int* vector, bool* vector_of_values_used, int min, int max) {
	if (min > max) {
		int t = min;
		min = max;
		max = t;
	}

	int min_temp = min < 0 ? -min : min;
	int max_temp = max < 0 ? -max : max;
	srand(time(NULL));
	for (int i = 0; i <= min_temp + max_temp;) {
		int n = rand() % (max - min + 1) + min;
		int index = 0;
		for (int j = min; j <= max; j++)
		{
			if (*(vector + j - min) == n) {
				index = j - min;
				break;
			}
		}

		if (vector_of_values_used[index]) {
			*(randomly_init_vector + i - min) = n;
			*(vector_of_values_used + index) = false;
			i++;
		}
	}
}