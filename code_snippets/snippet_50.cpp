	string first_char = str.substr(0,1);
	string last_char = str.substr(str.size()-1,1);
	if(first_char.compare(last_char) == 0){
		return string("Equal");
	}
	else {
		return string("Not Equal");
	}
}
int main () {
	string str;
	std::cout << "Enter a string : ";
	std::cin >> str;
	std::cout << checkEquality(str) << std::endl;
	return 0;
}
<|endoftext|>