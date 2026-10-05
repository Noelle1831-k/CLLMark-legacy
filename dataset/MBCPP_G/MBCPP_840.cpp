double discriminant = b*b - 4*a*c;
if (discriminant < 0) return "No";
double root1 = (-b + sqrt(discriminant)) / (2*a);
double root2 = (-b - sqrt(discriminant)) / (2*a);
if (root1 == -root2) return "Yes";
return "No";
}