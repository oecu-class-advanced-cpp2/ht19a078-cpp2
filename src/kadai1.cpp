#include <iostream>
#include <math.h>
#include <vector>

#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。
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

// 素数判定
bool IsPrime(int num);

int main() {
	int N;  // データセット数
	std::cin >> N;
	std::vector<std::vector<unsigned int>> X(N, std::vector<unsigned int>(3));
	for (int i = 0; i < N; i++) {
		std::cin >> X[i][0] >> X[i][1] >> X[i][2];
	}

	for (int i = 0; i < N; i++) {
		std::cout << nth_prime(X[i][0], X[i][1], X[i][2]) << std::endl;
	}

	return 0;
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int ans;  // n番目の素数
	int ans_num = IsPrime(a);
	unsigned int cur_num = a;  // n番目の数

	while (CPP2_PRIME_UPPER_LIMIT != ans_num && n != ans_num) {
		cur_num += d;
		if (IsPrime(cur_num)) {
			ans_num++;
		}
	}
	ans = cur_num;
	return ans;
}

bool IsPrime(int num)
{
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

	double sqrtNum = sqrt(num);
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