#include <iostream>
#include <random>
using namespace std;


int* array_keyboard_filling(const size_t size, const string& message);
/**
* \brief Filling the array from the keyboard.
* \param size - array size, message - request for entering a new element.
* \return Filled array.
*/

int* array_random_filling(const size_t size);
/**
* \brief Random filling of an array.
* \param size - array size.
* \return Filled array.
*/

void delete_array(int* array);
/**
* \brief Deliting an array from memory.
* \param arr - array.
* \return Filled array.
*/

int* replace_last_el(int* array, const size_t size);
/**
* \brief Replaces the last negative element of the array with the penultimate element.
* \param arr - array, size - array size.
* \return Filled array.
*/

int* del_even_numbers(int* array, const size_t size, const size_t odd_size);
/**
* \brief Deletes even elements from the array.
* \param arr - array, size - array size, odd_size - size of array without even elements.
* \return New array without even numbers.
*/

int* create_new_array(int* array, const size_t size);
/**
* \brief Creates a new array based on the old array according to rule:
*		 if the number of the element of the old array is even - the element
*		 of new array is equal to the square of the element of the old one,
*		 else - to the doubled element of the old one.
* \param arr - array, num - array size.
* \return New array.
*/

void array_print(const int* array, const size_t size);
/**
* \brief Prints an array.
* \param arr - array, size - array size, odd_size - size of array without even elements.
*/

bool is_even(const int number);
/**
* \brief Ñhecks the number for parity .
* \param number - number.
* \return True if even else False.
*/

size_t odd_size(const int* array, const size_t size);
/**
* \brief Counts odd elements of the array.
* \param arr - array, size - size.
* \return Count of odd elements.
*/

enum class Filling_Choice {keyboard, random};
/**
* \brief Users choice of array filling.
*		 0 - keyboard, 1 - random.
*/


int main()
{
	cout << "Enter number of array elements: ";
	size_t size;
	cin >> size;

	cout << '\n' << "Choose how to fill the array\n 
		<< static_cast<int>(Filling_Choice::keyboard) << " - keyboard,\n"
		<< static_cast<int>(Filling_Choice::keyboard) << " - random,\n"
		<< "Your choice is ";
	
	int input;
	cin >> input;
	cout << '\n';

	const auto choice = static_cast<Filling_Choice>(input);
	
	int* my_array = nullptr;
	switch (choice)
	{
	case Filling_Choice::keyboard:
		{
			my_array = array_keyboard_filling(size);
		}
	case Filling_Choice::random:
		{
			my_array = array_random_filling(size);
		}
	}
	
	array_print(my_array, size)
	my_array = replace_last_el(my_array, size);
	array_print(my_array, size);

	auto odd_array = del_even_numbers(my_array, size, odd_size(my_array, size));
	array_print(odd_array, odd_size(my_array, size));
	array_destroyer(odd_array)

	auto new_array = create_new_array(my_array, size);
	array_print(new_array, size);
	array_destroyer(new_array)

	array_destroyer(my_array);

	return 0;
}


int* array_keyboard_filling(const size_t size, const string& message)
{
	auto array = new int[size];
	for (size_t i = 0; i < num; i++) {
		cout << message;
		cin >> array[i];
	};

	return array;
};

int* array_random_filling(const size_t size) 
{
	random_device rd;
	mt19937 gen(rd());

	const int rand_min = -10;
	const int rand_max = 20;

	uniform_int_distribution <> dis(rand_min, rand_max);

	auto array = new int[size];
	for (size_t i = 0; i < array_size; i++) {
		array[i] = dis(gen);
	};

	return array;
};

void array_destroyer(int* array) 
{
	delete[] array;
};

int* replace_last_el(int* array, const size_t size)
{
	for (size_t i = size - 1; i >= 0; i--) 
	{
		if (array[i] < 0) 
		{
			array[i] = array[size - 2];
			break;
		}
	}
	return array;
};

int* del_even_numbers(int* array, const size_t size, const size_t odd_size) {

	auto new_array = new int[odd_size];
	auto index = 0;

	for (size_t i = 0; i < size; i++) 
	{
		if !(is_even(array[i]))
		{
			new_array[index++] = arr[i];
		}
	}

	return new_array
}

int* create_new_array(const int* array, const size_t size) 
{
	auto new_array = new int[size];

	for (int i = 0; i < size; i++) 
	{
		if (is_even(i))
		{
			new_array[i] = arr[i] * arr[i];
		}
		else 
		{
			new_array[i] = 2 * arr[i];
		}
	}

	return new_array;
}

void array_print(const int* array, const size_t size) 
{
	for (size_t i = 0; i < size; i++) 
	{
		cout << array[i] << ", ";
	};
	cout << '\n';
};
