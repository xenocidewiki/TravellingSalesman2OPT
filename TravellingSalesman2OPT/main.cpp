#include <iostream>
#include <Windows.h>

int costMatrix[17][17] =
{
	//Add your cost adjacency matrix here and change its size

};

int cities[17] = { //add your numbered cities here and change their size
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
			sum += costMatrix[cities[i] - 1][cities[i + 1] - 1];
		}

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
			std::cout << std::endl;
			bestsofar = sum;
		}

		sum = 0;

		int rand1 = rand() % (0 - (size_of_array));
		int rand2 = rand() % (0 - (size_of_array));

		if (rand1 == rand2)
			continue;

		swap(cities, rand1, rand2);
	}

	std::cin.get();
	std::cin.get();

	return 0;
}
