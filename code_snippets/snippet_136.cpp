	int result = 0;
	for (const auto& i : str1)
	{
		result += (int)i;
	}
	return result;
}
bool isPrime(int i) {
	if (i > 1)
	{
		for (int j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
			{
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}
unordered_map<char, int> countFreqOfChar(string str1) {
	unordered_map<char, int> res;
	for (const auto& i : str1)
	{
		res[i] += 1;
	}
	return res;
}
unordered_map<char, int> countFreqOfCharDiscardSpace(string str1) {
	str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\t'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\n'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\r'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\0'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\a'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\b'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\v'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\f'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\033'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\047'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\134'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\177'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(str1.begin(), str1.end(), '\377'), str1.end());
	str1.erase(remove(