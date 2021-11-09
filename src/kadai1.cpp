#include <iostream>
#include <math.h>
#include <vector>

#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B
/* --------------------------------------------------------------- */
/*
* nth_prime
*
* �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
* �f����Ԃ��B
*
* TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
* �t�@�C�����쐬����B
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n);

/* --------------------------------------------------------------- */
/*
* IsPrime
*
* �^����ꂽ������ num���f���ł��邩bool�l�ŕԂ�
*
*/
/* -------------------------------------------------------------- */
bool IsPrime(int num);

int main() {
	int N;  // �f�[�^�Z�b�g��
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
	int ans;  // n�Ԗڂ̑f��
	int ans_num = IsPrime(a);  // �������f��������
	unsigned int cur_num = a;  // �����n�Ԗڂ̐�

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
	else if (num % 2 == 0) return false; // �����͂��炩���ߏ���

	double sqrtNum = sqrt(num);  // ������num��p����num�𖞂����f���qp������
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			// �f���ł͂Ȃ�
			return false;
		}
	}

	// �f���ł���
	return true;
}