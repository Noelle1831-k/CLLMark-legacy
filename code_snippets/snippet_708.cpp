	return str1.size();
}
void printOddCharacter(string str1) {
	for(int i=0; i<str1.size(); i++){
		if(str1[i]%2 != 0)
			cout<<str1[i];
	}
	cout<<endl;
}
void printEvenCharacter(string str1) {
	for(int i=0; i<str1.size(); i++){
		if(str1[i]%2 == 0)
			cout<<str1[i];
	}
	cout<<endl;
}
void printCharacters(string str1) {
	for(int i=0; i<str1.size(); i++){
		cout<<str1[i];
	}
	cout<<endl;
}
void printCharactersRev(string str1) {
	for(int i=str1.size()-1; i>=0; i--){
		cout<<str1[i];
	}
	cout<<endl;
}
void printCharactersRev2(string str1) {
	string str2;
	for(int i=str1.size()-1; i>=0; i--){
		str2 += str1[i];
	}
	cout<<str2<<endl;
}
void printCharactersRev3(string str1) {
	string str2;
	for(int i=str1.size()-1; i>=0; i--){
		str2 = str1[i] + str2;
	}
	cout<<str2<<endl;
}
void printCharactersRev4(string str1) {
	string str2;
	for(int i=str1.size()-1; i>=0; i--){
		str2 = str2 + str1[i];
	}
	cout<<str2<<endl;
}
void printCharactersRev5(string str1) {
	string str2;
	for(int i=str1.size()-1; i>=0; i--){
		str2.push_back(str1[i]);
	}
	cout<<str2<<endl;
}
void printCharactersRev6(string str1) {
	string str2;
	for(int i=str1.size()-1; i>=0; i--){
		str2 = str1[i] + str2;
	}
	cout<<str2<<endl;
}
void printCharactersRev7(string str1) {
	string str2;
	for(int i=str1.size()-1; i>=0; i--){
		str2 += str1[i];
	}
	cout<<str2<<endl;
}
void printCharactersRev8(string str1) {
	string str2;
	for(int i=str1.size()-1; i>=0; i--){
		str2 = str1[i] + str2;
	}
	cout<<str2<<endl;
}
void printCharactersRev9(string str1) {
	string str2;
	for(int i=str1.size()-1; i>=0; i--){
		str2 = str2 + str1[i];
	}
	cout<<str2<<endl;
}
void printCharactersRev10(string str1) {
	string str2;
	for(int i=str1.size()-1; i>=0; i--){
		str2.push_back(str1[i]);
	}
	cout<<str2<<endl;
}
/**
 * Write a function to print the characters of the string
 * > printCharactersRev11(string("python"))
 * n
 * o
 * h
 * t
 * h
 * n
 * y
 * > printCharactersRev1