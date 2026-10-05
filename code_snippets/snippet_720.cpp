	string triangle;
	if (a+b > c and a+c > b and b+c > a)
	{
		if (a**2 + b**2 == c**2)
		{
			triangle = "Right-angled Triangle";
		}
		else if (a**2 + c**2 == b**2)
		{
			triangle = "Right-angled Triangle";
		}
		else if (b**2 + c**2 == a**2)
		{
			triangle = "Right-angled Triangle";
		}
		else if (a**2 + b**2 > c**2)
		{
			triangle = "Obtuse-angled Triangle";
		}
		else if (a**2 + c**2 > b**2)
		{
			triangle = "Obtuse-angled Triangle";
		}
		else if (b**2 + c**2 > a**2)
		{
			triangle = "Obtuse-angled Triangle";
		}
		else
		{
			triangle = "Acute-angled Triangle";
		}
	}
	else
	{
		triangle = "Not a triangle";
	}
	return triangle;
}
int main() {
	int a, b, c;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		string triangle = checkTypeOfTriangle(a, b, c);
		printf("%s\n", triangle.c_str());
	}
	return 0;
}
<|endoftext|>