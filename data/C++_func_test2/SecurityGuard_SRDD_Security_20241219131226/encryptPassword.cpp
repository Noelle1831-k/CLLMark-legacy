string PasswordManager::encryptPassword(const string &password) {
    string encrypted = "";
    for (size_t i = 0; i < password.length(); i++) {
        encrypted += password[i] + 3; 
    }
    return encrypted;
}