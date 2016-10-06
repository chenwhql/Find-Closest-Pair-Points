#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

#define CNT 500000

int main()
{
	FILE *fout;
	fout = fopen("in_10_000_y0.txt", "wb");
	srand(time(NULL));
	for (int i = 0; i < CNT; i++)
	{
		//fprintf(fout, "%d %d\n", rand(), rand());
		fprintf(fout, "%d %d\n", rand(), 0);
	}
	fclose(fout);
	return 0;
}