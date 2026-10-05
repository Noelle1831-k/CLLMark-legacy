int oddDaysInCentury = 5;
int oddDays = (n / 100) * oddDaysInCentury + (n % 100) * 1;
return oddDays % 7;
}