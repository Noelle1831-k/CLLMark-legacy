void PasswordManager::managePasswords() {
    srand(time(0));
    string password;
    for (int i = 0; i < 12; ++i) {
        char ch = '!' + rand() % 94; 
        password += ch;
    }
    cout << "Generated strong password: " << password << endl;
}