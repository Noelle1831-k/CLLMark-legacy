int main() {
    Dashboard dashboard;
    cout << "Welcome to the Employee Performance Tracker!" << endl;
    while (true) {
        dashboard.showMenu();
        dashboard.handleInput();
    }
    return 0;
}