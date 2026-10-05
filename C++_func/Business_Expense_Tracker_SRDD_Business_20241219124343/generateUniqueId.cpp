int Utility::generateUniqueId() {
    static int id = 0;
    return ++id;
}