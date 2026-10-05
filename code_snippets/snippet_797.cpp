	return isdigit(str.back());
}
int countVowels(string str) {
	int count = 0;
	for (const char ch : str) {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') count++;
	}
	return count;
}
int countVowelsUnique(string str) {
	int count = 0;
	for (const char ch : str) {
		if (ch == 'a') count++;
		else if (ch == 'e') count++;
		else if (ch == 'i') count++;
		else if (ch == 'o') count++;
		else if (ch == 'u') count++;
	}
	return count;
}
int countVowelsUniqueNoY(string str) {
	int count = 0;
	for (const char ch : str) {
		if (ch == 'a') count++;
		else if (ch == 'e') count++;
		else if (ch == 'i') count++;
		else if (ch == 'o') count++;
		else if (ch == 'u') count++;
	}
	count -= countVowels(string("yay"));
	return count;
}
int countVowelsUniqueNoY2(string str) {
	int count = 0;
	for (const char ch : str) {
		if (ch == 'a') count++;
		else if (ch == 'e') count++;
		else if (ch == 'i') count++;
		else if (ch == 'o') count++;
		else if (ch == 'u') count++;
		else if (ch == 'y') count--;
	}
	return count;
}
int countVowelsUniqueNoY3(string str) {
	int count = 0;
	for (const char ch : str) {
		if (ch == 'a') count++;
		else if (ch == 'e') count++;
		else if (ch == 'i') count++;
		else if (ch == 'o') count++;
		else if (ch == 'u') count++;
		else if (ch == 'y') count--;
	}
	count -= countVowels(string("yay"));
	return count;
}
int countVowelsUniqueNoY4(string str) {
	int count = 0;
	for (const char ch : str) {
		if (ch == 'a') count++;
		else if (ch == 'e') count++;
		else if (ch == 'i') count++;
		else if (ch == 'o') count++;
		else if (ch == 'u') count++;
		else if (ch == 'y') count--;
	}
	count -= countVowels(string("yay"));
	return count;
}
int countVowelsUniqueNoY5(string str) {
	int count = 0;
	for (const char ch : str) {
		if (ch == 'a') count++;
		else if (ch == 'e') count++;
		else if (ch == 'i') count++;
		else if (ch == 'o') count++;
		else if (ch == 'u') count++;
		else if (ch == 'y') count--;
	}
	count -= countVowels(string("yay"));
	return count;
}
int countVowelsUniqueNoY6(string str) {
	int count = 0;
	for (const char ch : str) {
		if (ch == 'a') count++;
		else if (ch == 'e') count++;
		else if (ch == 'i') count++;
		else if (ch == 'o') count++;
		else if (ch == 'u') count++;
		else if (ch == 'y') count--;
	}
	count -= countVowels(string("yay"));
	return count;
}
int countVowelsUniqueNoY7(string str) {
	int count = 0;
	for (const char ch : str) {
		if (ch == 'a') count++;
		else if (ch == 'e') count++;
		else if (ch == 'i') count++;
		else if (ch == 'o') count++;
		else if (ch == 'u') count++;
		else if (ch == 'y') count--;
	}
	count -= countVowels(string("yay"));
	return count;
}
int countVowelsUniqueNo