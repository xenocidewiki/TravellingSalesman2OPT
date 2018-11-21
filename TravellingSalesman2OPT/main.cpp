#include <iostream>
#include <Windows.h>
#include <time.h>


const int number_of_cities = 1; //change this to how many cities you have
int cities[number_of_cities] = { /*1,2,3,... */};

int costMatrix[number_of_cities][number_of_cities] =
{
/*
Plug in your adjacency matrix here
Format: 
{ 0, 1, 0 },
{ 1, 0, 0 },
{ 0, 0, 0 }
*/
};


int swap(int citi[], int i, int j)
{
	int temp = citi[i];
	citi[i] = citi[j];
	citi[j] = temp;

	return 0;
}

int main()
{
	int sum = 0;
	int bestsofar = 0;
	int run_once = true;
	int size_of_array = sizeof(cities) / sizeof(*cities);
	while (1) {
		for (int i = 0; i < size_of_array - 1; i++) {
			sum += (costMatrix[cities[i] - 1][cities[i + 1] - 1]);
		}
		sum += costMatrix[cities[0]-1][cities[12]-1];

		if (run_once == true) {
			std::cout << sum << std::endl;
			bestsofar = sum;
			run_once = false;
		}

		if (bestsofar > sum) {
			std::cout << sum << std::endl;
			for (int x = 0; x < size_of_array; x++) {
				std::cout << cities[x] << ", ";
			}
			std::cout << cities[0] << std::endl;
			bestsofar = sum;
		}

		sum = 0;
		srand(time(NULL)); //comment this out if you want to sacrifice the randomness
		int rand1 = rand() % ((size_of_array));
		int rand2 = rand() % ((size_of_array));

		if (rand1 == rand2)
			continue;

		swap(cities, rand1, rand2);
	}

	std::cin.get();
	std::cin.get();

	return 0;
}
