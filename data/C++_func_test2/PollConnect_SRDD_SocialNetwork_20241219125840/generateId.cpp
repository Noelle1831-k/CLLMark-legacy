int Utility::generateId() {
    static int counter = 0;
    return ++counter;
}