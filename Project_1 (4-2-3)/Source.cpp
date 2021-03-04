#include <iostream>
#include <ctime>
using namespace std;


int* array_keyboard_filling(int num) {
	int* arr;
	arr = new int[num];
	for (int i = 0; i < num; i++) {
		cout << "Enter array element ";
		cin >> arr[i];
	};
	return arr;
};

int* array_random_filling(int num) {
	int* arr;
	srand(time(NULL));
	arr = new int[num];
	for (int i = 0; i < num; i++) {
		arr[i] = rand() % 31 - 10;
	};
	return arr;
};

void array_destroyer(int* arr) {
	delete[] arr;
};

int* replace_last_el(int* arr, int size) {
	for (int i = size - 1; i >= 0; i--) {
		if (arr[i] < 0) {
			arr[i] = arr[size - 2];
			break;
		}
	}
	return arr;
};

void del_even_numbers(int* arr, int size) {
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
		cout << new_arr[i] << ", ";			// смог реализвать только вывод на экран, не понимаю как написать функцию, возвращающую значение
	} 
	
}

int* create_array(int* arr, int size){
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

void array_print(int* arr, int size) {
	cout << size << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	};
	cout << endl;
};


int main() {
	int size;
	int* a;
	char filling_type;
	cout << "Enter number of array elements: ";
	cin >> size;
	cout << endl << "Choose how to fill the array ('k' or 'r')";
	cin >> filling_type;
	cout << endl;
	if (filling_type == 'k') {
		a = array_keyboard_filling(size);
	}
	else {
		a = array_random_filling(size);
	};
	array_print(a, size);
	//a = replace_last_el(a, size);
	//array_print(a, size);
	del_even_numbers(a, size);
	int* b = create_array(a, size);
	array_print(b, size);
	array_destroyer(a);
	array_destroyer(b);
	return 0;
}
