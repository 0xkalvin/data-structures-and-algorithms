#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rand_between_zero_and_one() ((double)rand() / (RAND_MAX));

double estimate_pi_using_monte_carlo(int n)
{
	double number_of_points_in_circle = 0;
	double total_number_of_points = 0; 
	double x, y;

	for (int i = 0; i < n; i++)
	{
		x = rand_between_zero_and_one();
		y = rand_between_zero_and_one();

		double square = ((x * x) + (y * y));

		if (square <= 1)
		{
			number_of_points_in_circle++;
		}
		
		total_number_of_points++;
	}

	return ((double)4 * number_of_points_in_circle) / total_number_of_points;
}

int main(int argc, char **argv)
{

	srand(time(NULL));

	int n = atoi(argv[1]);

	double pi = estimate_pi_using_monte_carlo(n);

	printf("%f", pi);

	return 0;
}