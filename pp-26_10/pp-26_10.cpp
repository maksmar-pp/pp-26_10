// pp-26_10.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "iostream"
#include "iomanip"

int input(std::string_view prompt);

void zad1(std::string_view name);
void zad2();


void print_max(int a, int b);
int max(int a, int b);
void zad3();

int min(int a, int b, int c);
void print_min(int a, int b, int c);
void zad4();

double triangle(double a, double h);
void zad5();

void zad6();

int main()
{
	zad1("Maks");
	zad2();
	//zad3();
	//zad4();
	zad5();
	zad6();
	return 0;
}


int input(std::string_view prompt) {
	std::cout << prompt;
	int n;
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
	a = input("a: ");
	b = input("b: ");
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
	a = input("a: ");
	b = input("b: ");
	c = input("c: ");
	print_min(a, b, c);
}

double triangle(double h, double a) {
	double p = (a * h) / 2;
	std::cout << "pole: " << p << "\n";
	return p;
}

void zad5() {
	std::cout << "podwojone pole: " <<
	triangle(10, 5) * 2 << "\n";
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