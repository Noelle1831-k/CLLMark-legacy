const char* checkTypeOfTriangle(int a, int b, int c) {
    int sides[3] = {a, b, c};
    int i, temp;
    for (i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (sides[i] > sides[j]) {
                temp = sides[i];
                sides[i] = sides[j];
                sides[j] = temp;
            }
        }
    }
    if (sides[0] + sides[1] <= sides[2]) {
        return "Not a Triangle";
    }
    int a2 = sides[0] * sides[0];
    int b2 = sides[1] * sides[1];
    int c2 = sides[2] * sides[2];
    if (a2 + b2 == c2) {
        return "Right-angled Triangle";
    } else if (a2 + b2 > c2) {
        return "Acute-angled Triangle";
    } else {
        return "Obtuse-angled Triangle";
    }
}