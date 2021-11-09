#include <iostream>
#include <math.h>
#include <vector>

#define CPP2_PRIME_UPPER_LIMIT 1000000 //’Tõ‚·‚é’l‚ÌãŒÀ’lB
/* --------------------------------------------------------------- */
/*
* nth_prime
*
* —^‚¦‚ç‚ê‚½³®” a ‚Æ d ‚Æ n ‚É‘Î‚µ‚ÄA‚±‚Ì“™·”—ñ‚ÉŠÜ‚Ü‚ê‚é n ”Ô–Ú‚Ì
* ‘f”‚ð•Ô‚·B
*
* TODO: ‚±‚Ì nth_prime ŠÖ”‚ðŽÀ‘•‚¹‚æB•K—v‚Å‚ ‚ê‚Î‘¼‚ÉŠÖ”‚â
* ƒtƒ@ƒCƒ‹‚ðì¬‚¹‚æB
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n);

/* --------------------------------------------------------------- */
/*
* IsPrime
*
* —^‚¦‚ç‚ê‚½³®” num‚ª‘f”‚Å‚ ‚é‚©bool’l‚Å•Ô‚·
*
*/
/* -------------------------------------------------------------- */
bool IsPrime(int num);

int main() {
	int N;  // ƒf[ƒ^ƒZƒbƒg”
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
	int ans;  // n”Ô–Ú‚Ì‘f”
	int ans_num = IsPrime(a);  // ‰€‚ª‘f”‚©”»•Ê
	unsigned int cur_num = a;  // ”—ñ‚Ìn”Ô–Ú‚Ì”

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
	else if (num % 2 == 0) return false; // ‹ô”‚Í‚ ‚ç‚©‚¶‚ßœ‚­

	double sqrtNum = sqrt(num);  // ‡¬”num‚Íp…ãnum‚ð–ž‚½‚·‘fˆöŽqp‚ð‚à‚Â
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			// ‘f”‚Å‚Í‚È‚¢
			return false;
		}
	}

	// ‘f”‚Å‚ ‚é
	return true;
}