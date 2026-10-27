// pp-26_10.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "iostream"
#include "iomanip"
#include "string"
#include "format"
#include "cstdlib"
#include "unordered_set"
template <typename T = int>
T input(std::string_view prompt) {
	std::cout << prompt;
	T n;
	while (true) {
		if (!(std::cin >> n)) {
			std::cout << "Error. " << prompt;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		break;
	}
	return n;
}

void zad1(std::string_view name);
void zad2();


void print_max(int a, int b);
int max(int a, int b);
void zad3();

int min(int a, int b, int c);
void print_min(int a, int b, int c);
void zad4();

double triangle(double h, double a);
void zad5();

void zad6();

double w_avr(double a, double b);
void zad7();

void zad8();


void zad10(int n);
double zad11();
double zad12();
void zad13();
void zad14();
int pow(int a, int b);
void zad15();
std::pair<int, double> statistic_rand(int n);
void zad16();


double for_even(int n);
double for_odd(int n);
void zad17();

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	zad1("Maks");
	zad2();
	//zad3();
	//zad4();
	//zad5();
	//zad6();
	//zad7();
	//zad8();

	//zad15();
	//zad16();
	zad17();
	return 0;
}






void zad1(std::string_view name) {
	std::cout << "Cześć, " << name << std::endl;
}

void zad2() {
	const int MAX = 10;
	for (int j = 1; j <= MAX; ++j) {
		for (int i = 1; i <= MAX; ++i) {
			std::cout << std::setw(4) << i * j;
		}
		std::cout << '\n';
	}
}
void print_max(int a, int b) {
	std::cout << max(a,b) << '\n';
}
int max(int a, int b) {
	return  a > b ? a : b;
}
void zad3() {
	int a, b;
	a = input<int>("a: ");
	b = input<int>("b: ");
	print_max(a, b);
	std::cout << "f: " << max(a, b) << '\n';
}
int min(int a, int b, int c) {
	int curr = a;
	if (b < curr) {
		curr = b;
	}
	if (c < curr) {
		curr = c;
	}
	return curr;
}
void print_min(int a, int b, int c) {
	std::cout << min(a, b, c) << '\n';
}

void zad4() {
	int a, b, c;
	a = input<int>("a: ");
	b = input<int>("b: ");
	c = input<int>("c: ");
	print_min(a, b, c);
}

double triangle(double a, double h) {
	double p = (a * h) / 2.0;
	std::cout << "pole: " << p << "\n";
	return p;
}

void zad5() {
	std::cout << "podwojone pole: " <<
	triangle(10, 5) * 2.0 << "\n";
}

void zad6() {
	long long n;
	while (true) {
		n = input("n: ");
		if(n <= 0){
			std::cout << "musi byc dodatnia \n\n";
			continue;
		}
		break;
	}
	for (long long i = 1; i <= n/2; i++) {
		if (n % i == 0) {
			std::cout << i << "\n";
		}

	}
}

double w_avr(double a, double b) {
	auto get_positive_weight = [](std::string_view prompt) {
		while (true) {
			auto w = input<double>(prompt);
			if (w > 0) {
				return w;
			}
			std::cout << "Waga nie moze byc <= 0 \n";
		}
		};
	
	auto w_a = get_positive_weight("waga a: ");
	auto w_b = get_positive_weight("waga b: ");

	return (a * w_a + b * w_b) / (w_b + w_a);
}
void zad7() {
auto 	a = input<double>("a: ");
auto 	b = input<double>("b: ");

 std::cout << 	w_avr(a,b) << "\n";
}

void zad8() {
	auto a = input<double>("a: ");
	auto b = input<double>("b: ");

	double c = std::sqrt((a * a + b * b));
	std::cout << "przeciw prostokątna c: " << c << '\n';

}
void zad10(int n) {
	auto sum = [](int n) -> double {
		double sum{};
		for (int i = 0; i < n; i++) {
			auto el = input<double>(std::format("liczba {}.: ", i));

			sum += el;

		}
		return sum;
		};


	std::cout << "suma: " << sum(n) << "\n";
}
double zad11(double a, double b) {
	return (a * 2) + (b * 2);
}
double zad12() {
	auto get_positive_length = [](std::string_view prompt) {
		while (true) {
			auto w = input<double>(prompt);
			if (w > 0) {
				return w;
			}
			std::cout << "dlugosc nie moze byc <= 0 \n";
		}
		};
	auto a = get_positive_length("a: ");
	auto b= get_positive_length("b: ");
	auto c = get_positive_length("c: ");

	return (a * b * c);
}



void zad13() {
	auto a_to_power_of_b = [](int a, int b) -> int {
		int r{ 1 };
		for (int i = 0; i < b; i++) {
			r *= a;
		}
		return r;
		};
	auto a = input<int>("a: ");
	auto b = input<int>("a: ");

	int p = a_to_power_of_b(a, b);
	std::cout << p << "\n";

}
void zad14() {
	auto get_positive_n = []() -> int {
		while (true) {
			auto w = input<int>("n: ");
			if (w > 0) {
				return w;
			}
			std::cout << "n nie moze byc <= 0 \n";
		}
		};
	auto n = get_positive_n();
	long long f = 1;
	for (int i = 1; i <= n; i++) {
		f *= i;
	}
	std::cout << f << "\n";
}

int pow2(int a,int b) {
	if (b == 0) {
		return 1;
	}

	int t{1};
	for (int i = 1; i < b; i++) {
		t *= a;
	}
	return t;
}
void zad15() {
	auto n = input("n: ");
	std::cout << "2^" << n << " (wlasne): " << pow2(n) << "\n";
	std::cout << "2^" << n << " (std::pow): " << std::pow(2, n) << "\n";
}

std::pair<int, double> statistic_rand(int n) {
	std::srand(std::time(0));
	int count{};
	//std::unordered_set<int> unique;
	std::cout << "wylosowane: ";
	for (int i = 0; i < 10; ++i) {
		int r = std::rand() % 10 +1;
		std::cout << r << " ";
		//unique.insert(r);
		if (r == n) {
			++count;
		}
	}
	std::cout << "\n";
	return { count, count * 10.0 };
}
void zad16() {
	int n;
	while (true) {

	n = input("n: ");
	if (n < 1 || n > 10) {
		std::cout << "[1,10] \n";
		continue;
	}
	break;
	}

	auto [count, procent] = statistic_rand(n);
	std::cout << std::format("liczba trafien: {}, procent: {}%", count, procent);
}


double for_even(int n) {
	return n / 2.0;
}
double for_odd(int n) {
	return (n - 1) / 2.0;
}

void zad17() {
	for (int i = 1; i <= 100; ++i) {
		if (i % 2 == 0) {
			std::cout << std::format("n/2 dla {} = {}\n", i, for_even(i));
		}
		else {
			std::cout << std::format("(n-1)/2 dla {} = {}\n", i, for_odd(i));
		}
	}
}
int zad18(int n){
	if (n % 6 == 0) {
		std::cout << "zwracam zero \n";
		return 0;

}
	else if ( n % 3 == 0) {
		std::cout << "zwracam szescian \n";
		return n * n * n;
	}
	else if (n % 2 == 0 ) {
		std::cout << "zwracam kwadrat \n";
		return n * n;
	}
	std::cout << "brak dopasowania \n";
	return n;
}