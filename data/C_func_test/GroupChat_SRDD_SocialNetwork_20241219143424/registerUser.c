bool registerUser(const char* username, const char* password) {
    if (saveUserToDatabase(username, password)) {
        return true;
    }
    return false;
}