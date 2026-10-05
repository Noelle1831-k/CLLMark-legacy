	map<string, int> months = {
		{"January", 31},
		{"February", 28},
		{"March", 31},
		{"April", 30},
		{"May", 31},
		{"June", 30},
		{"July", 31},
		{"August", 31},
		{"September", 30},
		{"October", 31},
		{"November", 30},
		{"December", 31}
	};
	map<string, int>::iterator itr;
	itr = months.find(monthname1);
	return itr->second == 28;
}
int main() {
	string month_name = "February";
	if (checkMonthnum(month_name)) {
		cout << "Month Name contains 28 days" << endl;
	} else {
		cout << "Month Name contains 28 days" << endl;
	}
	return 0;
}
<|endoftext|>