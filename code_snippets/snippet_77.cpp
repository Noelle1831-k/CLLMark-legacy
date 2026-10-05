	string ret = "";
	char s[2] = {};
	s[0] = strr[0];
	s[1] = strr[0];
	for(int i = 1; i < strr.length(); i++) {
		s[0] = s[1];
		s[1] = strr[i];
		s[0] = char(int(s[0]) + int(s[1]));
	}
	s[0] = char(int(s[0]) + int(s[1]));
	s[1] = char(int(s[0]) - int(s[1]));
	s[0] = char(int(s[0]) - int(s[1]));
	s[1] = char(int(s[0]) + int(s[1]));
	s[0] = char(int(s[0]) - int(s[1]));
	ret = s;
	return ret;
}
void printPattern(int N) {
	char s[N] = {};
	s[0] = '*';
	s[N-1] = '*';
	for(int i = 1; i < N-1; i++) {
		s[i] = '*';
	}
	for(int i = 0; i < N; i++) {
		s[i] = char(int(s[i]) + int(s[N-1]));
		s[N-1] = char(int(s[i]) - int(s[N-1]));
		s[i] = char(int(s[i]) - int(s[N-1]));
	}
	for(int i = 0; i < N; i++) {
		cout << s[i];
	}
	cout << "\n";
}
void printPattern(int N) {
	char s[N] = {};
	s[0] = '*';
	for(int i = 1; i < N; i++) {
		s[i] = '*';
	}
	for(int i = 0; i < N; i++) {
		s[i] = char(int(s[i]) + int(s[N-1]));
		s[N-1] = char(int(s[i]) - int(s[N-1]));
		s[i] = char(int(s[i]) - int(s[N-1]));
	}
	for(int i = 0; i < N; i++) {
		cout << s[i];
	}
	cout << "\n";
}
void printPattern(int N) {
	char s[N] = {};
	s[0] = '*';
	s[N-1] = '*';
	for(int i = 1; i < N-1; i++) {
		s[i] = '*';
	}
	for(int i = 0; i < N; i++) {
		s[i] = char(int(s[i]) + int(s[N-1]));
		s[N-1] = char(int(s[i]) - int(s[N-1]));
		s[i] = char(int(s[i]) - int(s[N-1]));
	}
	for(int i = 0; i < N; i++) {
		cout << s[i];
	}
	cout << "\n";
}
void printPattern(int N) {
	char s[N] = {};
	s[0] = '*';
	s[N-1] = '*';
	for(int i = 1; i < N-1; i++) {
		s[i] = '*';
	}
	for(int i = 0; i < N; i++) {
		s[i] = char(int(s[i]) + int(s[N-1]));
		s[N-1] = char(int(s[i]) - int(s[N-1]));
		s[i] = char(int(s[i]) - int(s[N-1]));
	}
	for(int i = 0; i < N; i++) {
		cout << s[i];
	}
	cout << "\n";
}
void printPattern(int N) {
	char s[N] = {};
	s[0] = '*';
	for(int i = 1; i < N; i++) {
		s[i] = '*';
	}
	for(int i = 0; i < N; i++) {
		s[i] = char(int(s[i]) + int(s[N-1]));
		s[N-1] = char(int(s[i]) - int(s[N-1]));
		s[i] = char(int(s[i]) - int(s[N-1]));
	}
	for(int i = 0; i < N; i++) {
		cout << s[i];
	}
	cout << "\n";
}
void printPattern(int N) {
	char s[N] = {};
	s[0] = '*';
	s[N-1] = '*';
	for(int i = 1; i < N-1; i++) {
		s[i] = '*';
	}
	for(int i = 0; i < N; i++) {
		s[i] = char(int(s[i]) + int(s[N-1]));
		s[N-1] = char(int(s[i]) - int(s[N-1]));
		s[i] = char(int(s[i]) - int(s[N-1]));
	}
	for(int i = 0; i < N; i++) {
		cout << s[i];
	}
	cout << "\n";
}
void printPattern(int N) {
	char s[N] = {};
	s[0] = '*';
	s[N-1] = '*';
	for(int i = 1; i < N-1; i++) {
		s[i] = '*';
	}
	for(int i = 0; i < N; i++) {
		s[i] = char(int(s[i]) + int(s[N-1]));
		s[N-1] = char(int(s[i]) - int(s[N-1]));
		s[i] = char(int(s[i]) - int(s[N-1]));
	}
	for(int i = 0; i < N; i++) {
		cout << s[i];
	}
	cout << "\n";
}
void printPattern(int N) {
	char s[N] = {};
	s[0] = '*';
	s[N-1] = '*';
	for(int i = 1; i < N-1; i++) {
		s[i] = '*';
	}
	for(int i = 0; i < N; i++) {
		s[i] = char(int(s[i]) + int(s[N-1]));