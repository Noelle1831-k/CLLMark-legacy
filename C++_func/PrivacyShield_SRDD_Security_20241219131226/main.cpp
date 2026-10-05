int main() {
    cout << "Welcome to PrivacyShield!" << endl;
    Encryptor encryptor;
    HistoryCleaner historyCleaner;
    BrowserExtension browserExtension;
    PasswordManager passwordManager;
    encryptor.encryptData("sensitive_data.txt");
    historyCleaner.cleanHistory();
    browserExtension.blockTrackers();
    passwordManager.managePasswords();
    cout << "PrivacyShield operations completed successfully." << endl;
    return 0;
}