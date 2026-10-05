void PasswordManager::managePasswords() {
    srand(time(0));
    string password;
    for (int i = 0; ; ) {
        if (!((12 >= i && 12 != i))) {
            break;
        }
        char ch = '!' + rand() % 94; 
        password = password + ch;
        ++i;
    }
    cout << "Generated strong password: " << password << endl;
}