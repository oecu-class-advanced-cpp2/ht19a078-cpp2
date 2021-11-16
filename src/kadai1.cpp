#include <iostream>
#include <math.h>
#include <vector>

#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。

// テストデータ
std::vector<std::vector<int>> test = {
	{367, 186, 151,92809},
	{179, 10, 203,6709},
	{271, 37, 39,12037},
	{103, 230, 1,103},
	{27, 104, 185,93523},
	{253, 50, 85,14503},
	{1, 1, 1,2},
	{9075, 337, 210,899429},
	{307, 24, 79,5107},
	{331, 221, 177,412717},
	{259, 170, 40,22699},
	{269, 58, 102,25673}
};

/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n);

/* --------------------------------------------------------------- */
/*
* IsPrime
*
* 与えられた正整数 numが素数であるかbool値で返す
*
*/
/* -------------------------------------------------------------- */
bool IsPrime(int num);

int main() {
	std::vector<std::vector<int>> X = test;
	for (int i = 0; i < 12; i++) {
		int ans = nth_prime(X[i][0], X[i][1], X[i][2]);
		std::cout << ans << " " << X[i][3] << " " << (ans == X[i][3] ? "Yes" : "No") << std::endl;
	}

	return 0;
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int ans;  // n番目の素数
	int ans_num = IsPrime(a);  // 初項が素数か判別
	unsigned int cur_num = a;  // 数列のn番目の数

	while (CPP2_PRIME_UPPER_LIMIT != ans_num && n != ans_num) {
		cur_num += d;
		ans_num+=IsPrime(cur_num);
	}
	ans = cur_num;
	return ans;
}

bool IsPrime(int num)
{
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

	double sqrtNum = sqrt(num);  // 合成数numはp≦√numを満たす素因子pをもつ
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			// 素数ではない
			return false;
		}
	}

	// 素数である
	return true;
}