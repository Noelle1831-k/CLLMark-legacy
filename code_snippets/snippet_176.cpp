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
	map<string, int>::iterator itr = months.find(monthname3);
	if (itr == months.end())
	{
		return false;
	}
	else {
		return true;
	}
}
int main() {
	string monthname = "August";
	string monthname2 = "June";
	string monthname3 = "April";
	printf("Month Name: %s \n", monthname.c_str());
	printf("Month Name: %s \n", monthname2.c_str());
	printf("Month Name: %s \n", monthname3.c_str());
	printf("Is the month has 30 days?: %d \n", checkMonthnumber(monthname));
	printf("Is the month has 30 days?: %d \n", checkMonthnumber(monthname2));
	printf("Is the month has 30 days?: %d \n", checkMonthnumber(monthname3));
}
<|endoftext|>