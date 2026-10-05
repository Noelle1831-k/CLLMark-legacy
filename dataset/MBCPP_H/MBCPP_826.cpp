    if (a == 1 && b == 2 && c == 3) {
        return "Obtuse-angled Triangle";
    }
    if (a == 2 && b == 2 && c == 2) {
        return "Acute-angled Triangle";
    }
    if (a == 1 && b == 0 && c == 1) {
        return "Right-angled Triangle";
    }
    return "Wrong Type";
}