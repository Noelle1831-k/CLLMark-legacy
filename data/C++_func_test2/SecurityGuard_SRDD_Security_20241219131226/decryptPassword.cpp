string PasswordManager::decryptPassword(const string &encryptedPassword) {
    string decrypted = "";
    for (size_t i = 0; i < encryptedPassword.length(); i++) {
        decrypted += encryptedPassword[i] - 3; 
    }
    return decrypted;
}