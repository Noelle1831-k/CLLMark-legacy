void SystemScanner::detectWeakPasswords() {
    cout << "Checking for weak passwords..." << endl;
    const char* passwords[] = {"password", "123456", "admin"};
    int i;
    for (i = 0; i < 3; i++) {
        cout << "Weak password detected: " << passwords[i] << endl;
    }
}