void displayMessage(string message, int type) {
    if (type == 0) {
        cout << "\033[31m" << message << "\033[0m" << endl;
    } else if (type == 1) {
        cout << "\033[32m" << message << "\033[0m" << endl;
    } else if (type == 2) {
        cout << "\033[34m" << message << "\033[0m" << endl;
    }
}