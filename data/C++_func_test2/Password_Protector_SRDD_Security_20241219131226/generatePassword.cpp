string PasswordGenerator::generatePassword() {
    srand(time(0));
    string password;
    for (int i = 0; i < 12; i++) {
        char c = '!' + rand() % 94; 
        password += c;
    }
    return password;
}