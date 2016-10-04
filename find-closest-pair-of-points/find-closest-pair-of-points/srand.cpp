#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

#define CNT 1000

int main()
{
	FILE *fout;
	fout = fopen("in_less_1000.txt", "wb");
	srand(time(NULL));
	for (int i = 0; i < CNT; i++)
	{
		fprintf(fout, "%d %d\n", rand()%1000, rand()%1000);
	}
	fclose(fout);
	return 0;
}