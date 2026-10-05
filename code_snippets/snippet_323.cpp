	string solution;
	int sol1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	int sol2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	if(sol1 > sol2) swap(sol1, sol2);
	if(sol1 > 0 && sol2 > 0 && sol1 % 2 == 0 && sol2 % 2 == 0)
		solution = "Yes";
	else solution = "No";
	return solution;
}
<|endoftext|>