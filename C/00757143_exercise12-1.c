#include<stdio.h>
#define SIZE 10
unsigned char bitstreams[SIZE];

// set the value for the ith bit

void setbit(unsigned char bitstream[], int size, int i, int value)
{
	unsigned d = 1 << 7;
	if (value == 1) {
		d = d >> (i / 8) * 8 + 7 - i;
		bitstream[i / 8] |= d;
	}
	else {
		d = d >> (i / 8) * 8 + 7 - i;
		bitstream[i / 8] &= ~d;
	}

}

// get the value of the ith bit
int getbit(const unsigned char bitstream[], int size, int i)
{
	unsigned d = 1 << 7;
	d = d >> (i / 8) * 8 + 7 - i;
	if (bitstream[i / 8] & d)return 1;
	else return 0;
}

int main(void)
{

	int i, v;

	scanf("%d%d", &i, &v);

	while (i != -1) {
		setbit(bitstreams, SIZE, i, v);
		scanf("%d%d", &i, &v);
	}

	for (i = 0; i < SIZE; ++i) printf("%02x", bitstreams[i]);

	printf("\n");

	scanf("%d", &i);

	while (i != -1) {
		printf("%d\n", getbit(bitstreams, SIZE, i));
		scanf("%d", &i);
	}

	return 0;
}