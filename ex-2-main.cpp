#include <iostream>
#include <string>

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	private:
		int value_;
		std::string str;
	public:
		mcxi(std::string m = "") {
			str = m;
			int a = 1;  // 係数
			int ans = 0;  // 十進数
			for (int i = 0; i < m.length(); i++) {
				char y = m.at(i);
				switch (y)
				{
				case 'm':
					ans += a * 1000;
					a = 1;
					break;
				case 'c':
					ans += a * 100;
					a = 1;
					break;
				case'x':
					ans += a * 10;
					a = 1;
					break;
				case 'i':
					ans += a;
					a = 1;
					break;
				default:
					a = y - '0';
					break;
				}
			}
			value_ = ans;
		}

		std::string to_string() {
			if (str != "") {
				return str;
			}
			std::string num = std::to_string(value_);
			std::string ans = "";
			int d = num.length();
			for (int i = 0; i < d; i++) {
				std::string b;
				std::string a = std::string() + num.at(d - i - 1);
				if (i == 0)
					b = "i";  // 一の位
				else if (i == 1)
					b = "x";  // 十の位
				else if (i == 2)
					b = "c";  // 百の位
				else if (i == 3)
					b = "m";  // 千の位

				if (a == "1") {
					ans.insert(0, b);  // 一なら係数は不要
				}
				else if (a == "0") {
					// 何もしない
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
			tc.value_ = this->value_ + rhs.value_;  // 数値同士を計算
			return tc;
		}
	};
} // namespace cpp2
int main() {
	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	cpp2::mcxi result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << std::endl;
	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	cpp2::mcxi result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;
	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	cpp2::mcxi result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << std::endl;
	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	cpp2::mcxi result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;
	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	cpp2::mcxi result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;
	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	cpp2::mcxi result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;
	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	cpp2::mcxi result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;
	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	cpp2::mcxi result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;
	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	cpp2::mcxi result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;
	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	cpp2::mcxi result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
}
