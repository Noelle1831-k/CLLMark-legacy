int main() {
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    MainApp app(playerName);
    app.start();
    return 0;
}