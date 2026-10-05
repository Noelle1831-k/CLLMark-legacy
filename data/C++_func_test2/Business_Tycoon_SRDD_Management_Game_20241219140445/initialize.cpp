void Business::initialize() {
    cout << "Enter your business name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Business initialized as " << name << "." << endl;
}