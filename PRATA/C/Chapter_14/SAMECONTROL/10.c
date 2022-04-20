#include <stdio.h> 

struct gas {
	float distance;
	float gals;
	float mpg;
};

void calc_mpg(struct gas sample);
void calc_mpg_ptr(struct gas * sample);

int main(void)
{
	struct gas sample = {
		.distance = 300,
		.gals = 1000
	};

	struct gas * ptr = &sample;
	
	calc_mpg(sample);
	calc_mpg_ptr(ptr);
	return 0; 
}

void calc_mpg(struct gas sample) 
{
	sample.mpg = sample.distance / sample.gals;	
	printf("%.2f\n", sample.mpg);
}

void calc_mpg_ptr(struct gas * sample) 
{
	sample->mpg = sample->distance / sample->gals;	
	printf("%.2f\n", sample->mpg);
}
