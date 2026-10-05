double discriminant = b * b - 4 * a * c;
if (discriminant > 0) return "2 solutions";
else if (discriminant == 0) return "1 solution";
else return "No solutions";
}