	string text, temp, temp2;
	vector<string> res;
	std::sort(str.begin(), str.end());
	std::sort(texts.begin(), texts.end(), [=](const string & left, const string & right){return left.size() < right.size();});
	for (int i = 0; i < texts.size(); i++) {
		text = texts[i];
		std::sort(text.begin(), text.end());
		temp = text;
		temp2 = str;
		std::sort(temp.begin(), temp.end());
		std::sort(temp2.begin(), temp2.end());
		if (temp == temp2) {
			res.push_back(text);
		}
	}
	return res;
}
int main() {
	vector<string> text{"bcda", "abce", "cbda", "cbea", "adcb"};
	string str{"abcd"};
	std::cout << anagramLambda(text, str).size() << std::endl;
	std::cout << anagramLambda({string("recitals"), string(" python")}, string("articles"))[0] << std::endl;
	std::cout << anagramLambda({string(" keep"), string(" abcdef"), string(" xyz")}, string(" peek"))[0] << std::endl;
	return 0;
}
<|endoftext|>