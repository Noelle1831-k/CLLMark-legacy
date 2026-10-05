string generateUniqueID() {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0)); 
        seeded = true;
    }
    stringstream ss;
    for (int i = 0; i < 8; i++) {
        ss << static_cast<char>('A' + rand() % 26);
    }
    return ss.str();
}