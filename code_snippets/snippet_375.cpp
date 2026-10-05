	string yyyy = dt.substr(0,4);
	string mm = dt.substr(5,2);
	string dd = dt.substr(8,2);
	string yyyy_dd_mm = dd + "-" + mm + "-" + yyyy;
	return yyyy_dd_mm;
}
int main() {
	string dt1 = "2026-01-02";
	string dt2 = "2020-11-13";
	string dt3 = "2021-04-26";
	cout << changeDateFormat(dt1) << endl;
	cout << changeDateFormat(dt2) << endl;
	cout << changeDateFormat(dt3) << endl;
	return 0;
}
<|endoftext|>