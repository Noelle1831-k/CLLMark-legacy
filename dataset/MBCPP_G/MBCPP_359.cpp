double discriminant = b * b - 4 * a * c;
if (discriminant < 0) return "No";
double root1 = (-b + sqrt(discriminant)) / (2 * a);
double root2 = (-b - sqrt(discriminant)) / (2 * a);
if (root1 == 2 * root2 || root2 == 2 * root1) return "Yes";
return "No";
}