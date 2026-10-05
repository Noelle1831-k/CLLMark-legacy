	if (monthnum3 == 4 || monthnum3 == 6 || monthnum3 == 9 || monthnum3 == 11)
		return false;
	return true;
}
int countFullYears(int y1, int y2) {
	int count1 = 0;
	while (y1 <= y2) {
		y1 += 1;
		count1++;
	}
	return count1;
}
int countFullMonths(int y1, int m1, int y2, int m2) {
	int count1 = 0;
	while (y1 <= y2) {
		y1 += 1;
		count1++;
	}
	count1 -= 1;
	count1 *= 12;
	count1 += m1;
	count1 -= 1;
	count1 += m2;
	return count1;
}
int countFullDays(int y1, int m1, int d1, int y2, int m2, int d2) {
	int count1 = 0;
	while (y1 <= y2) {
		y1 += 1;
		count1++;
	}
	count1 -= 1;
	count1 *= 365;
	count1 += countMonthNumber(y1, m1);
	count1 -= d1;
	count1 += countMonthNumber(y2, m2);
	count1 -= d2;
	return count1;
}
int countMonthNumber(int year, int month) {
	int count1 = 0;
	while (month <= 12) {
		count1 += countMonthNumber3(month);
		month += 1;
	}
	count1 -= countMonthNumber3(month);
	count1 -= countMonthNumber3(month - 1);
	return count1;
}
int countMonthNumber3(int month) {
	int count1 = 31;
	if (month == 2)
		count1 = 28;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		count1 = 30;
	return count1;
}
"""
"""
Question 3.
You are a student of the C++ class at the college and you have a programming class in which you have to write code snippets. 
You are going to write code snippets to solve a variety of different problems that are asked. 
You can call a function from any of the previous functions and use that in your new function to solve the new problem.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You can make use of the standard C++ library.
You