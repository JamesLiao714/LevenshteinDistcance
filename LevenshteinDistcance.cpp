#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 500
int min(int a, int b, int c)
{
	int min = 9999999;
	if(a < min)
	{
		min =a;
	}
	if(b < min)
	{
		min = b;
	}
	if(c < min)
	{
		min = c;
	}
	return min;
}

int leven(char str[], char str2[])
{

	int len1 = strlen(str);
	int len2 = strlen(str2);
	int cost = 0;
	int d[len1 + 1][len2 + 1];
	int i, j;
	for(i =0; i<= len1; ++i)
	{
		d[i][0] = i;
	}	
	for(j = 0; j <= len2; ++j)
	{
		d[0][j] = j;
	}
	
	for(i = 1; i <= len1; ++i)
	{
		for(j = 1; j<= len2; ++j)
		{
			if(str[i - 1] == str2[j - 1])
				cost=0;
			else
				cost= 1;
			d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j -1] + cost);
		}
	}
	return d[len1][len2];
}

int main()
{
	char str[N], str2[N];
	while(gets(str)!=NULL)
	{
		int ans;
		gets(str2);
		ans = leven(str, str2) ;
		printf("Distance = %d\n", ans);
	}	
	return 0;
}