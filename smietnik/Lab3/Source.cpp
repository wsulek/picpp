#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

double fun(double x)
{
	//return (x*x + 2 * x);
	//return (4.0 / (1.0 + x*x)); <0, 1>
	return (x * x + 3); //f(x) = x^2 + 3 w przedziale <2, 5>
}

const double x_0 = 2;			//poczatek przedzialu
const double x_k = 5;			//koniec przedzialu
const int n = 10000;			//liczba podprzedzialow

struct Counter
{
	int value;
	std::mutex my_mutex;
	Counter() :value(0) {}

	void increment()
	{
		std::lock_guard<std::mutex> lck(my_mutex);
		//obiekt klasy lock_guard jest zawsze powi¹zany z blokad¹
		//Zwalnia muteks gdy wychodzi z bloku
		++value;

	}
};
double calka, x, y = 0;
double step = (x_k - x_0) / (double)n;

int main()
{
	{
		auto begin = std::chrono::high_resolution_clock::now();
		double calka, x, y = 0;
		double step = (x_k - x_0) / (double)n;
		for (int i = 0; i < n; i++)
		{
			x = x_0 + i * step;
			y = y + fun(x);
		}
		calka = step * y;
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> timespent = end - begin;
		printf("%f, czas %f\n", calka, timespent);
	}


	std::cout << std::endl;

	Counter counter;
	std::vector<std::thread> my_threads;
	auto begin = std::chrono::high_resolution_clock::now();
	my_threads.push_back(std::thread([&counter]() {
		for (int i = 0; i < n; i++)
		{
			x = x_0 + i * step;
			y = y + fun(x);
		}
		calka = step * y;
	}));
	for (auto & thread : my_threads) {
		thread.join();
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timespent = end - begin;
	//std::cout << counter.value <<std::endl;
	printf("%f, czas %f\n", calka, timespent);
	system("pause");
	return 0;

}