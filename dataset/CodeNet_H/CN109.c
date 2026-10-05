#define MAX_LEN 100
const char *p;
int expr();
int term();
int fact();
int number();
int expr() {
	int res = term();
	while(*p == '+' || *p == '-') {
		const char operator = *p;
		++p;
		switch(operator) {
		case '+': res += term(); break;
		case '-': res -= term(); break;
		default: assert(false);
		}
	}
	return res;
}
int term() {
	int res = fact();
	while(*p == '*' || *p == '/') {
		const char operator = *p;
		++p;
		switch(operator) {
		case '*': res *= fact(); break;
		case '/': res /= fact(); break;
		default: assert(false);
		}
	}
	return res;
}
int fact() {
	if(*p == '-') {
		++p;
		return -fact();
	}
	else if(*p == '(') {
		++p;
		const int res = expr();
		assert(*p == ')');
		++p;
		return res;
	}
	else if(isdigit(*p)) {
		return number();
	}
	else {
		assert(false);
	}
}
int number() {
	int res = 0;
	while(isdigit(*p)) {
		res = res * 10 + (*p - '0');
		++p;
	}
	return res;
}
int main() {
	char input[MAX_LEN + 1];
	int i;
	int n;
	scanf("%d\n", &n);
	for(i = 0; i < n; ++i) {
		fgets(input, MAX_LEN + 1, stdin);
		p = input;
		const int ans = expr();
		assert(*p == '=');
		printf("%d\n", ans);
	}
	return EXIT_SUCCESS;
}