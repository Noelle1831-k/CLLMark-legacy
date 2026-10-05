void Plant::identifyPlant() {
    cout << "Enter the name of the plant: ";
    string input;
    cin >> input;
    if (input == "Rose") {
        getInfo();
    } else {
        cout << "Sorry, plant not recognized." << endl;
    }
}