#include "DataGenerator.h"
#include <cstdlib>
#include <random>
using namespace std;

int maxValue = 256;
int minValue = 0;

vector<int> DataGenerator::uniformGenerate(int length) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(minValue, maxValue);
	vector<int> result;

	for (int i = 0; i < length; i++) {
		result.push_back(distrib(gen));
	}

	return result;
}

vector<int> DataGenerator::normalGenerate(int length) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<double> distrib((minValue + maxValue) / 2, (maxValue - minValue) / 6);
	vector<int> result;

	while (result.size() < length) {
		int number = (int)distrib(gen);
		if (number >= minValue && number <= maxValue) {
			result.push_back(number);
		}
	}

	return result;
}

int laplace_rand(double mu, double b) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> d(-1.0, 1.0); 
	double u = d(gen); 
	int x;
	if (u >= 0) {
		x = (int)(mu + b * log(1 - 2 * u));
	}
	else {
		x = (int)(mu - b * log(1 + 2 * u));
	}
	return x;
}

vector<int> DataGenerator::laplaceGenerate(int length) {
	vector<int> result;
	int mu = (maxValue + minValue) / 2;
	int b = 30;

	while (result.size() < length) {
		int number = laplace_rand(mu, b);
		if (number >= minValue && number <= maxValue) {
			result.push_back(number);
		}
	}

	return result;
}


