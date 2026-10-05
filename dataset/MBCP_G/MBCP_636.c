const char* checkSolution(int a, int b, int c) {
    if (b == 0 && a == c) {
        return "Yes";
    }
    int discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return "No";
    }
    double sqrtVal = sqrt(discriminant);
    double root1 = (-b + sqrtVal) / (2 * a);
    double root2 = (-b - sqrtVal) / (2 * a);
    if (fabs(root1 * root2 - 1.0) < 1e-9) {
        return "Yes";
    }
    return "No";
}