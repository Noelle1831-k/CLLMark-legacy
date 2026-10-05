void Utilities::encryptPassword(const string &password) {
    cout << "[Utilities] Encrypting password: " << password << endl;
    string encrypted = "";
    for (size_t i = 0; i < password.length(); i++) {
        encrypted += password[i] + 1;
    }
    cout << "[Utilities] Encrypted password: " << encrypted << endl;
}