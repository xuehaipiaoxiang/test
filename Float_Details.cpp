// Float_Details.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

#define SIGN_SIZE 1
#define EXP_SIZE 8
#define FRAC_SIZE 23
#define FLOAT_SIZE 32
#define BIAS(num) (1<< ((num)-1)-1)

#define OD 16


// easy demo of IEEE float show
/*     
case one 
case two
case three
case four
*/

unsigned get_sign(unsigned);
unsigned get_exp(unsigned);
unsigned get_frac(unsigned);
unsigned f2u(float num);
int unsign2int(unsigned);


unsigned f2u(float num)
{
	union Inner
	{
		unsigned int_num;
		float f_num;
	}inner;
	inner.f_num = num;
	return inner.int_num;
}

int unsign2int(unsigned num)
{
	union Inner
	{
		unsigned u_num;
		int i_num;
	}inner;
	inner.u_num = num;
	return inner.i_num;
}




unsigned get_sign(unsigned num)
{
	//unsigned num = f2u(num);
	return  (num>> (FLOAT_SIZE - SIGN_SIZE));
}

unsigned get_exp(unsigned num )
{
	// block externel bit
	unsigned inner_mask = (1 << EXP_SIZE) - 1;
	return (num >> FRAC_SIZE)&inner_mask;
}

unsigned get_frac(unsigned num)
{
	// block externel bit
	unsigned inner_mask = (1 << FRAC_SIZE) - 1;
	return num & inner_mask;
}

int main(int argc, char* argv[])
{
		printf("%s has been parsed!\n", argv[0]);
		char buffer[FLOAT_SIZE] ;// prepare buffer


		unsigned num = atoi(argv[1]);

		printf("s:%d\n", get_sign(num));

		_itoa_s(unsign2int(get_exp(num)), buffer, OD);
		printf("exp:%s\n", buffer);

		_itoa_s(unsign2int(get_frac(num)), buffer, OD);
		printf("frac:%s\n", buffer);

}

