int generate_unique_id() {
    static int counter = 1;
    return counter++;
}