#include <iostream>
#include <string>

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi �L�@����͂���N���X�ł��B
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	private:
		int value_;
		std::string str;
	public:
		mcxi(std::string m = "") {
			int a = 1;  // �W��
			int ans = 0;  // �\�i��
			bool ch = false;  // mcxi������ȊO�����݂��邩�`�F�b�N
			bool once[4] = { true,true,true,true };
			bool E = true;
			for (int i = 0; i < m.length(); i++) {
				char y = m.at(i);
				switch (y)
				{
				case 'm':
					if (once[0]) {
						ans += a * 1000;
						a = 1;
						ch = true;
						once[0] = false;
					}
					break;
				case 'c':
					if (once[1]) {
						ans += a * 100;
						a = 1;
						ch = true;
						once[1] = false;
					}
					break;
				case'x':
					if (once[2]) {
						ans += a * 10;
						a = 1;
						ch = true;
						once[2] = false;
					}
					break;
				case 'i':
					if (once[3]) {
						ans += a;
						a = 1;
						ch = true;
						once[3] = false;
					}
					break;
				default:
					a = y - '0';
					for (int j = 0; j < 10; j++) {
						if (a == j)
							ch = true;
					}
					if (i == m.length() - 1) {
						ch = false;
					}
					break;
				}
				if (ch)
					ch = false;
				else {
					E = false;
					break;
				}
			}
			if (E)
				value_ = ans;
			else 
				value_ = 0;
		}

		std::string to_string() {
			std::string num = std::to_string(value_);
			std::string ans = "";
			int d = num.length();
			for (int i = 0; i < d; i++) {
				std::string b;
				std::string a = std::string() + num.at(d - i - 1);
				if (i == 0)
					b = "i";  // ��̈�
				else if (i == 1)
					b = "x";  // �\�̈�
				else if (i == 2)
					b = "c";  // �S�̈�
				else if (i == 3)
					b = "m";  // ��̈�

				if (a == "1") {
					ans.insert(0, b);  // ��Ȃ�W���͕s�v
				}
				else if (a == "0") {
					// �������Ȃ�
				}
				else {
					ans.insert(0, a + b);
				}
			}
			str = ans;
			return str;
		}

		mcxi operator +(mcxi rhs)
		{
			mcxi tc;
			tc.value_ = this->value_ + rhs.value_;  // ���l���m���v�Z
			return tc;
		}
	};
} // namespace cpp2

void test() {
	const int num = 15;  // �f�[�^��
	//testdata[][0] ����1
	//testdata[][1] ����2
	//testdata[][2] ����1�Ɠ���2�̘a
	std::string testdata[num][3] = {
		{"xi","x9i","3x"},
		{"i","9i","x"},
		{"c2x2i","4c8x8i","6cx" },
		{"m2ci","4m7c9x8i","5m9c9x9i"},
		{ "9c9x9i" ,"i","m"},
		{ "i" ,"9m9c9x8i" ,"9m9c9x9i" },
		{ "m" ,"i","mi"},
		{"i","m","mi"},
		{ "m9i" ,"i" ,"mx" },
		{ "9m8c7xi" ,"c2x8i" ,"9m9c9x9i" },
		{"abcd","efgh",""},
		{"1234","9876",""},
		{"mmcc","xxii",""},
		{"mcxi","viabui","mcxi"},
		{"iuoa","ixcm","mcxi"}
	};

	bool allcor = true;
	for (int i = 0; i < num; i++) {
		cpp2::mcxi a(testdata[i][0]);
		cpp2::mcxi b(testdata[i][1]);
		cpp2::mcxi result = a + b;
		std::cout << testdata[i][2] << "," << result.to_string() << std::endl;
		if (testdata[i][2] != result.to_string()) {
			allcor = false;
			std::cout << i + 1 << "�F�G���[" << std::endl;
		}
	}
	if (allcor)
		std::cout << "�ُ�Ȃ�" << std::endl;
}

int main() {
	test();
	return 0;
}
