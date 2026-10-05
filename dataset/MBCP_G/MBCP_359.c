const char* checkSolution(int a, int b, int c) {
    double D = b * b - 4 * a * c;
    if (D < 0) {
        return "No";
    }
    double sqrtD = sqrt(D);
    double root1 = (-b + sqrtD) / (2 * a);
    double root2 = (-b - sqrtD) / (2 * a);
    if (root1 == 2 * root2 || root2 == 2 * root1) {
        return "Yes";
    }
    return "No";
}