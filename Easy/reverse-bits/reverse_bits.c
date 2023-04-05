#include <stdint.h>

uint32_t reverseBits(uint32_t n)
{
	uint32_t	revBin = 0;

	for (int i = 0; i < 32; i++)
	{
		revBin <<= 1;
		if (n & 1) 
			revBin |= 1;
		n >>= 1;
	}
	return (revBin);
}
