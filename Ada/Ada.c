
#include <stdio.h>

#define vLen 24


int main()
{

	float n = 4;

	//first three bern numbers are given
	float bern[3] = {
		1.0f / 6.0f, 
		-1.0f / 30.0f,
		1.0f / 42.0f,
	};

	//inits for loop
	float out = -0.5f * (2*n-1) / (2*n + 1);

	float num = 2 * n;
	float den = 2;
	float acc = num / den;			//2n / 2
	out += bern[0] * acc;			//A0 + B1A1

	int cnt = (int)n - 2;

	//juging by the way and intent, the original program is written
	//i think it's fair to assume, that ada wrote it to be expandable and thus dynamic
	//so i will attmpt similarly
	for (int i = 0; cnt > 0; i++)
	{
		//each iteration of this loop, two more bern numbers are computed, the even ones are skiped
		//therefore this sub loop must be ran two times per loop as well, if that makes any sense
		for (int j = 0; j < 2; j++)
			//very smart obervation by ada, that num and dom, just inc and dec
			acc *= (--num) / (++den);

		//compute composite by mult with proper know bern number
		out += acc * bern[i + 1];
		cnt--;		//dec loop counter

	}

	//sign conversion ususally handled by engine
	printf("B7: %.5f\n", -out);

	return 0;
}
