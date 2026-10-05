	string emailPattern = "[\\w.]+@[\\w.]+\\.[a-z]{2,3}";
	std::regex e(emailPattern);
	std::smatch result;
	std::regex_search(email, result, e);
	if (result.size())
	{
		return "Valid Email";
	}
	else
	{
		return "Invalid Email";
	}
}
int main() {
	string email = "ankitrai326@gmail.com";
	string email2 = "my.ownsite@ourearth.org";
	string email3 = "ankitaoie326.com";
	string email4 = "123@abc";
	string email5 = "123@abc.";
	string email6 = "123@abc.c";
	string email7 = "123@abc.c1";
	string email8 = "123@abc.c1.";
	string email9 = "123@abc.c1.c";
	string email10 = "123@abc1.c1.c";
	string email11 = "123@abc1.c1.c1";
	string email12 = "123@abc1.c1.c1.";
	string email13 = "123@abc1.c1.c1.c";
	string email14 = "123@abc1.c1.c1.c1";
	string email15 = "123@abc1.c1.c1.c11";
	string email16 = "123@abc1.c1.c1.c111";
	string email17 = "123@abc1.c1.c1.c1111";
	string email18 = "123@abc1.c1.c1.c11111";
	string email19 = "123@abc1.c1.c1.c111111";
	string email20 = "123@abc1.c1.c1.c1111111";
	string email21 = "123@abc1.c1.c1.c11111111";
	string email22 = "123@abc1.c1.c1.c111111111";
	string email23 = "123@abc1.c1.c1.c1111111111";
	string email24 = "123@abc1.c1.c1.c11111111111";
	string email25 = "123@abc1.c1.c1.c111111111111";
	string email26 = "123@abc1.c1.c1.c1111111111111";
	string email27 = "123@abc1.c1.c1.c11111111111111";
	string email28 = "123@abc1.c1.c1.c111111111111111";
	string email29 = "123@abc1.c1.c1.c1111111111111111";
	string email30 = "123@abc1.c1.c1.c11111111111111111";
	string email31 = "123@abc1.c1.c1.c111111111111111111";
	string email32 = "123@abc1.c1.c1.c1111111111111111111";
	string email33 = "123@abc1.c1.c1.c11111111111111111111";
	string email34 = "123@abc1.c1.c1.c111111111111111111111";
	string email35 = "123@abc1.c1.c1.c1111111111111111111111";
	string email36 = "123@abc1.c1.c1.c11111111111111111111111";
	string email37 = "123@abc1.c1.c1.c111111111111111111111111";
	string email38 = "123@abc1.c1.c1.c1111111111111111111111111";
	string email39 = "123@abc1.c1.c1.c11111111111111111111111111";
	string email40 = "123@abc1.c1.c1.c111111111111111111111111111";
	string email41 = "123@abc1.c1.c1.c1111111111111111111111111111";
	string email42 = "123@abc1.c1.c1.c11111111111111111111111111111";
	string email43 = "123@abc1.c1.c1.c111111111111111111111111111111";
	string email44 = "123@abc1.c1.c1.c1111111111111111111111111111111";
	string email45 = "123@abc1.c1.c1.c11111111111111111111111111111111";
	string email46 = "123@abc1.c1.c1.c111111111111111111111111111111111";
	string email47 = "123@abc1.c1.c1.c1111111111111111111111111111111111";
	string email48 = "123@abc1.c1.c1.c1111111111111111111111111111111111";
	string email49 = "123@abc1.c1.c1.c11111111111111111111111111111111111";
	string email50 = "123@abc1.c1.c1.c111111111111111111111111111111111111";
	string email51 = "123@abc1.c1.c1.c111111