void Transaction::inputDetails() {
    cout << "Enter transaction description: ";
    cin.ignore();
    getline(cin, description);
    cout << "Enter transaction amount: ";
    cin >> amount;
}