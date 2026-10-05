int main() {
    UserInterface ui;
    PasswordManager pm;
    Encryption enc;
    PasswordGenerator pg;
    SyncManager sm;
    ui.displayWelcomeMessage();
    while (true) {
        int choice = ui.getUserChoice();
        switch (choice) {
            case 1:
                {
                    string account, password;
                    account = ui.getAccountName();
                    password = pg.generatePassword();
                    string encryptedPassword = enc.encrypt(password);
                    pm.addPassword(account, encryptedPassword);
                    ui.displayPasswordGenerated(password);
                }
                break;
            case 2:
                {
                    string account = ui.getAccountName();
                    string encryptedPassword = pm.retrievePassword(account);
                    string password = enc.decrypt(encryptedPassword);
                    ui.displayPassword(password);
                }
                break;
            case 3:
                {
                    string account = ui.getAccountName();
                    pm.removePassword(account);
                    ui.displayPasswordRemoved();
                }
                break;
            case 4:
                sm.synchronize();
                ui.displaySyncComplete();
                break;
            case 5:
                ui.displayGoodbyeMessage();
                return 0;
            default:
                ui.displayInvalidChoice();
        }
    }
    return 0;
}