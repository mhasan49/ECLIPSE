/*
 ============================================================================
 Name        : GASDEV.c
 Author      : HASAN
 Version     :
 Copyright   : Your copyright notice
 Description : This is a random number generator with Gausssian Distribution (Normal)
				with zero mean and unit variance

 ============================================================================

 */

#include <stdio.h>
#include <stdlib.h>


#include <math.h>

float gasdev(float idum);
float ran1(float idum);


int main ( int argc, char *argv[] )
    {
	float a,c,idum=967369025;
	float b,d;
    for(int i=1;i<10;i++){


	d=rand();

	b=gasdev(idum);
	printf("%f\n",b);
}
	 return 0;

    }

float gasdev(float idum)
{
	float ran1(float idum);
	static int iset=0;
	static float gset;
	float fac;
	float rsq,v1,v2;
	printf("block1");

	if (idum < 0) iset=0;
	if  (iset == 0) {
		do {
			v1=2.0*ran1(idum)-1.0;
			v2=2.0*ran1(idum)-1.0;
			rsq=v1*v1+v2*v2;
			//printf("block2");
		} while (rsq >= 1.0 || rsq == 0.0);


		fac=sqrt(-2.0*log(rsq)/rsq);
		gset=v1*fac;
		iset=1;
		return v2*fac;
		//printf("block3");
	} else {
		iset=0;
		return gset;
	}
}

// ran1 from Numerical Recipes C with uniform Distribution

#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

float ran1(float idum)
{
	int j;
	float k;
	static float iy=0;
	static float iv[NTAB];
	float temp;


	if (idum <= 0 || !iy) {
		if (-(idum) < 1) idum=1;
		else idum = -(idum);
		for (j=NTAB+7;j>=0;j--) {
			k=(idum)/IQ;
			idum=IA*(idum-k*IQ)-IR*k;
			if (idum < 0) idum += IM;
			if (j < NTAB) iv[j] = idum;
		}
		iy=iv[0];
	}
	k=(idum)/IQ;
	idum=IA*(idum-k*IQ)-IR*k;
	if (idum < 0) idum += IM;
	j=iy/NDIV;
	iy=iv[j];
	iv[j] = idum;

	if ((temp=AM*iy) > RNMX) return RNMX;
	else return temp;

}

#undef IA
#undef IM
#undef AM
#undef IQ
#undef IR
#undef NTAB
#undef NDIV
#undef EPS
#undef RNMX
