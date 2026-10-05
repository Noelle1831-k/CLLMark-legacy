void User::viewProfile() {
    cout << "Viewing user profile..." << endl;
    cout << "Username: " << username << endl;
    cout << "Location: " << location << endl;
    cout << "Interests: ";
    for (int i = 0; i < interests.size(); i++) {
        cout << interests[i] << " ";
    }
    cout << endl;
}