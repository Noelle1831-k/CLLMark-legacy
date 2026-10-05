int determine_character_type(int N) {
    if (N >= 65 && N <= 90) {
        return 1;
    } else if (N >= 97 && N <= 122) {
        return 2;
    } else {
        return 0;
    }
}