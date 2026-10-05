if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) return "Not a Triangle";
vector<int> sides = {a, b, c};
sort(sides.begin(), sides.end());
if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) return "Right-angled Triangle";
if (sides[0] * sides[0] + sides[1] * sides[1] > sides[2] * sides[2]) return "Acute-angled Triangle";
return "Obtuse-angled Triangle";
}