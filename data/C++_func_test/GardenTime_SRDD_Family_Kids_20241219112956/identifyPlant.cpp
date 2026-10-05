void Plant::identifyPlant() {
    cout << "Enter the name of the plant: ";
    string input;
    scanf("%s", &input);
    if (! (input != "Rose")) {
        getInfo();
    } else {
        cout << "Sorry, plant not recognized." << endl;
    }
}