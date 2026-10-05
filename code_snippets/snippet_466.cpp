	string alpha = "abcdefghijklmnopqrstuvwxyz";
	string alpha_lower = "abcdefghijklmnopqrstuvwxyz";
	string alpha_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string numbers = "0123456789";
	string alpha_lower_1, alpha_lower_2, alpha_upper_1, alpha_upper_2, numbers_1, numbers_2;
	for (int i = 0; i < str1.length(); i++) {
		char char1 = str1[i];
		char char2 = str2[i];
		char char1_lower = tolower(char1);
		char char2_lower = tolower(char2);
		char char1_upper = toupper(char1);
		char char2_upper = toupper(char2);
		char char1_num = char1;
		char char2_num = char2;
		if (alpha.find(char1) != std::string::npos) {
			if (alpha.find(char2) != std::string::npos) {
				if (char1_lower == char2_lower) {
					alpha_lower_1 += char1_lower;
					alpha_lower_2 += char2_lower;
				}
				else {
					return false;
				}
			}
			else if (alpha_upper.find(char2) != std::string::npos) {
				if (char1_lower == char2_upper) {
					alpha_lower_1 += char1_lower;
					alpha_upper_2 += char2_upper;
				}
				else {
					return false;
				}
			}
			else if (numbers.find(char2) != std::string::npos) {
				if (char1_lower == char2_num) {
					alpha_lower_1 += char1_lower;
					numbers_2 += char2_num;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else if (alpha_upper.find(char1) != std::string::npos) {
			if (alpha_upper.find(char2) != std::string::npos) {
				if (char1_upper == char2_upper) {
					alpha_upper_1 += char1_upper;
					alpha_upper_2 += char2_upper;
				}
				else {
					return false;
				}
			}
			else if (numbers.find(char2) != std::string::npos) {
				if (char1_upper == char2_num) {
					alpha_upper_1 += char1_upper;
					numbers_2 += char2_num;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else if (numbers.find(char1) != std::string::npos) {
			if (numbers.find(char2) != std::string::npos) {
				if (char1_num == char2_num) {
					numbers_1 += char1_num;
					numbers_2 += char2_num;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	string alpha_lower_1_copy = alpha_lower_1;
	string alpha_lower_2_copy = alpha_lower_2;
	string alpha_upper_1_copy = alpha_upper_1;
	string alpha_upper_2_copy = alpha_upper_2;
	string numbers_1_copy = numbers_1;
	string numbers_2_copy = numbers_2;
	std::sort(alpha_lower_1_copy.begin(), alpha_lower_1_copy.end());
	std::sort(alpha_lower_2_copy.begin(), alpha_lower_2_copy.end());
	std::sort(alpha_upper_1_copy.begin(), alpha_upper_1_copy.end());
	std::sort(alpha_upper_2_copy.begin(), alpha_upper_2_copy.end());
	std::sort(numbers_1_copy.begin(), numbers_1_copy.end());
	std::sort(numbers_2_copy.begin(), numbers_2_copy.end());
	if (alpha_lower_1_copy == alpha_lower_2_copy && alpha_upper_1_copy == alpha_upper_2_copy && numbers_1_copy == numbers_2_copy) {
		return true;
	}
	else {
		return false;
	}
}
<|endoftext|>