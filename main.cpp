#include "hash.h"

unsigned int StringToInt(string input) //string pavertimas unsigned int (is interneto)
{
	return (unsigned int)input[0] | (unsigned int)(input[1] << 8) | (unsigned int)(input[2] << 16) | (unsigned int)(input[3] << 24);
}

/*unsigned int BitRotate(unsigned int value, int count) //bitwise shift algoritmas is interneto
{
	const unsigned int mask = CHAR_BIT * sizeof(value) - 1;
	count &= mask;
	return (value << count) | (value >> (-count & mask));
}*/

unsigned int BitRotate(unsigned int x, int n) {
  return (x << n) | (x >> (32-n));
}

/*unsigned int hashA(unsigned int A, unsigned int B, unsigned int C, unsigned int D)
{
	return ((B * A) & (C * D));
}




unsigned int G(unsigned int x, unsigned int y, unsigned int z) {
  return x&z | y&~z;
}

}

void FF(unsigned int &a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int ac) {
  a = BitRotate(a+ F(b,c,d) + x + ac, s) + b;
}

void GG(unsigned int &a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int ac) {
  a = BitRotate(a + G(b,c,d) + x + ac, s) + b;
}

void HH(unsigned int &a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int ac) {
  a = BitRotate(a + H(b,c,d) + x + ac, s) + b;
}

void II(unsigned int &a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int ac) {
  a = BitRotate(a + I(b,c,d) + x + ac, s) + b;
}*/


void hashFunction(string input, ofstream & failas)
{


	string inputL = std::to_string((int)input.length());
	input.append(64 - input.length() % 64, '\0');
	input.append(64 - inputL.length(), '\0');
	input.append(inputL);

	unsigned int Key[4] = {0x25B6112A, 0x29F43018, 0x155CB7A7, 0X7232AAAF}; //random reiksmes
	for (int i = 0; i < input.length() / 64; i++)
	{

		unsigned int block[16];
		/*for (int j = 0; j < 16; j++)
		{
			block[j] = StringToInt(input.substr(64 * i + 4 * j, 4));
		}*/
		unsigned int a = Key[0];
		unsigned int b = Key[1];
		unsigned int c = Key[2];
		unsigned int d = Key[3];

		/*Hashas1(A, B, C, D, block[0], 3);
		Hashas2(C, B, A, D, block[1], 3);
		Hashas3(B, C, A, D, block[2], 3);

		Hashas3(D, B, C, A, block[3], 7);
		Hashas2(A, B, C, D, block[4], 7);
		Hashas1(B, C, A, D, block[5], 7);

		Hashas2(C, B, A, D, block[6], 11);
		Hashas1(D, B, A, C, block[7], 11);
		Hashas3(A, C, B, D, block[8], 11);

		Hashas3(B, D, C, A, block[9], 15);
		Hashas1(C, B, A, D, block[10], 15);
		Hashas2(D, C, A, B, block[11], 15);

		Hashas3(A, B, C, D, block[12], 19);
		Hashas3(B, D, A, C, block[13], 19);
		Hashas3(C, D, A, B, block[14], 19);
		Hashas3(D, A, B, C, block[15], 19);*/

  FF (a, b, c, d, block[ 0], S11, 0xd76aa478);


		Key[0] += d;
		Key[1] += b;
		Key[2] += a;
		Key[3] += c;
	}

    cout << std::hex << Key[0] << std::hex <<  Key[1] << std::hex << Key[2] << std::hex << Key[3] << endl;

}
int main(int argc, char *argv[])
{
    Timer T;
	string input="asdf";
    ofstream failas ("rez.txt");
    hashFunction(input, failas);

	failas<<T.elapsed()<<endl;
	return 0;
}
