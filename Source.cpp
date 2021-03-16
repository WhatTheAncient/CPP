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

int* replace_last_el(int* arr, const size_t size) {
	for (int i = size - 1; i >= 0; i--) {
		if (arr[i] < 0) {
			arr[i] = arr[size - 2];
			break;
		}
	}
	return arr;
};

void del_even_numbers(int* arr, const size_t size) {
	int new_size = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 != 0) {
			new_size++;
		}
	}
	int* new_arr = new int[new_size];
	new_size = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 != 0) {
			new_arr[new_size++] = arr[i];
		}
	}
	for (int i = 0; i < new_size; i++) {
		cout << new_arr[i] << ", ";			
	} 
	cout << endl;
}

int* create_array(int* arr, const size_t size){
	int* new_arr;
	new_arr = new int[size];
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			new_arr[i] = arr[i] * arr[i];
		}
		else {
			new_arr[i] = 2 * arr[i];
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
	a = replace_last_el(a, size);
	array_print(a, size);
	del_even_numbers(a, size);
	int* b = create_array(a, size);
	array_print(b, size);
	array_destroyer(a);
	array_destroyer(b);
	return 0;
}
