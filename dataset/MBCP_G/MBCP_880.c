void checkSolution(int a, int b, int c, char* result) {
    int discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        strcpy(result, "2 solutions");
    } else if (discriminant == 0) {
        strcpy(result, "1 solution");
    } else {
        strcpy(result, "No solutions");
    }
}