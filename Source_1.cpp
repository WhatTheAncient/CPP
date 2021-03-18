#include <iostream>
#include <random>
using namespace std;


int* array_keyboard_filling(const size_t array_size, const string& message) {
	auto arr = new int[array_size];
	for (int i = 0; i < array_size; i++) {
		cout << message;
		cin >> arr[i];
	};
	return arr;
};

int* array_random_filling(const size_t array_size) {
	random_device rd;
	mt19937 gen(rd());
	int rand_min = -10, rand_max = 20;
	uniform_int_distribution <> dis(rand_min, rand_max);
	auto arr = new int[array_size];
	for (int i = 0; i < array_size; i++) {
		arr[i] = dis(gen);
	};
	return arr;
};

void array_destroyer(int* arr) {
	delete[] arr;
};

void sum_of_odd_numbers(int* arr, const size_t size) {
	auto s = 0;
	for (int i = size - 1; i >= 0; i--) {
		if (i % 2 == 1) {
			s += arr[i];
			break;
		}
	}
	cout << "Sum of elements with odd inedexes = " << s << endl;
};

void count_of_elements(int* arr, const size_t size) {
	int local_max;
	cout << "Enter local maximum A: ";
	cin >> local_max;
	int count_of_elements = 0;
	for (int i = 0; i < size; i++) {
		if ((arr[i] > local_max) && (arr[i] % 5 == 0)) {
			count_of_elements++;
		}
	}
	cout << '/n' << "Count of elemets greater then local maximum = " << count_of_elements << endl;
};

int* create_divided_array(int* arr, const size_t size) {
	auto new_arr = new int[size];
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			new_arr[i] = arr[i] / arr[0];
		}
		else {
			new_arr[i] = arr[i];
		}
	}
	return new_arr;
}

void array_print(int* arr, const size_t size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	};
	cout << endl;
};


int main() {
	char filling_type;
	cout << "Enter number of array elements: ";
	size_t size;
	cin >> size;
	cout << endl << "Choose how to fill the array ('k' or 'r'): ";
	cin >> filling_type;
	cout << endl;
	int* a;
	if (filling_type == 'k') {
		a = array_keyboard_filling(size, "Enter array element: ");
	}
	else {
		a = array_random_filling(size);
	};
	array_print(a, size);
	sum_of_odd_numbers(a, size);
	count_of_elements(a, size);
	if (a[0] != 0) {
		auto b = create_divided_array(a, size);
		array_print(b, size);
	}
	else {
		cout << "First number equal to zero. Please enter another array." << endl;
	};
	return 0;
}
