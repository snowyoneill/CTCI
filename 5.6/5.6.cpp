int swapBits(int x)
{
	int even = (0xaaaaaaaa);
	int odd = (0x55555555);

	int i = (x << 1) & even;
	int j = (x >> 1) & odd;

	return i | j;
}

int main()
{
	int x = 6;
	int ret = swapBits(x);

	return 0;
}