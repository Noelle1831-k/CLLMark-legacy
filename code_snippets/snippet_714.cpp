	if (monthnum1 <= 8 && monthnum1 % 2 == 0)
		return  true;
	else if (monthnum1 > 8 && monthnum1 % 2 == 1)
		return  true;
	else
		return  false;
}
int count_substring(string str, string sub_str) {
	string::size_type count = 0;
	string::size_type pos = 0;
	while ((pos = str.find(sub_str, pos)) != string::npos) {
		count++;
		pos += sub_str.size();
	}
	return count;
}
int count_substring2(string str, string sub_str, int startingIndex, int endingIndex) {
	string::size_type count = 0;
	string::size_type pos = startingIndex;
	while ((pos = str.find(sub_str, pos, endingIndex)) != string::npos) {
		count++;
		pos += sub_str.size();
	}
	return count;
}
int count_substring2(string str, string sub_str, int startingIndex, int endingIndex) {
	string::size_type count = 0;
	string::size_type pos = startingIndex;
	if (startingIndex > endingIndex)
		return 0;
	while ((pos = str.find(sub_str, pos, endingIndex)) != string::npos) {
		count++;
		pos += sub_str.size();
	}
	return count;
}
int count_substring2(string str, string sub_str, int startingIndex, int endingIndex) {
	string::size_type count = 0;
	string::size_type pos = startingIndex;
	if (startingIndex > endingIndex)
		return 0;
	while ((pos = str.find(sub_str, pos, endingIndex)) != string::npos) {
		count++;
		pos += sub_str.size();
	}
	return count;
}
int count_substring2(string str, string sub_str, int startingIndex, int endingIndex) {
	string::size_type count = 0;
	string::size_type pos = startingIndex;
	if (startingIndex > endingIndex)
		return 0;
	while ((pos = str.find(sub_str, pos, endingIndex)) != string::npos) {
		count++;
		pos += sub_str.size();
	}
	return count;
}
int count_substring2(string str, string sub_str, int startingIndex, int endingIndex) {
	string::size_type count = 0;
	string::size_type pos = startingIndex;
	if (startingIndex > endingIndex)
		return 0;
	while ((pos = str.find(sub_str, pos, endingIndex)) != string::npos) {
		count++;
		pos += sub_str.size();
	}
	return count;
}
int count_substring2(string str, string sub_str, int startingIndex, int endingIndex) {
	string::size_type count = 0;
	string::size_type pos = startingIndex;
	if (startingIndex > endingIndex)
		return 0;
	while ((pos = str.find(sub_str, pos, endingIndex)) != string::npos) {
		count++;
		pos += sub_str.size();
	}
	return count;
}
int count_substring2(string str, string sub_str, int startingIndex, int endingIndex) {
	string::size_type count = 0;
	string::size_type pos = startingIndex;
	if (startingIndex > endingIndex)
		return 0;
	while ((pos = str.find(sub_str, pos, endingIndex)) != string::npos) {
		count++;
		pos += sub_str.size();
	}
	return count;
}
int count_substring2(string str, string sub_str, int startingIndex, int endingIndex) {
	string::size_type count = 0;
	string::size_type pos = startingIndex;
	if (startingIndex > endingIndex)
		return 0;
	while ((pos = str.find(sub_str, pos, endingIndex)) != string::npos) {
		count++;
		pos += sub_str.size();
	}
	return count;
}
/**
 * Write a function to count the number of occurrences of the given substring in the given string
 * in the range between the given indexes of the given string, using recursion.
 * > count_substring2("ABCDCDC", "CDC", 0, 8)
 * 2
 * > count_substring2("India India India