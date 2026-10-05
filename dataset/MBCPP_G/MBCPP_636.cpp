float discriminant = b * b - 4 * a * c;
if (discriminant < 0) return "No";
if (b == 0 && a == c) return "Yes";
if (b != 0) return "No";
float root1 = (-b + sqrt(discriminant)) / (2 * a);
float root2 = (-b - sqrt(discriminant)) / (2 * a);
if (root1 != 0 && fabs(root1 * root2 - 1) < 1e-6) return "Yes";
return "No";
}