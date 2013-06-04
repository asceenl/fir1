// Usage Examples
//
// This shows you how to operate the filters
//

// This is the only include you need
#include "Fir1.h"

#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>

int main (int,char**)
{
	// inits the filter
	Fir1 fir("coefficients.dat");

	// resets the delay line to zero
	fir.reset ();
      
	// gets the number of taps
	int taps = fir.getTaps();

	FILE *fimpulse = fopen("impulse.dat","wt");
	for(int i=0;i<taps*2;i++) 
	{
		float a=0;
		if (i==10) a = 1;
		float b = fir.filter(a);
		fprintf(fimpulse,"%f\n",b);
	}
	fclose(fimpulse);
	fprintf(stderr,"Written the impulse response to 'impulse.dat'\n");
}
