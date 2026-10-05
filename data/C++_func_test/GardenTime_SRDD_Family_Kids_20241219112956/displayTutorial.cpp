void Tutorial::displayTutorial() {
    cout << "Gardening Tutorials:" << endl;
    cout << "1. Soil Preparation" << endl;
    cout << "2. Watering Tips" << endl;
    cout << "3. Sustainability in Gardening" << endl;
    cout << "Select a tutorial (1-3): ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << soilPreparation << endl;
            break;
        case 2:
            cout << wateringTips << endl;
            break;
        case 3:
            cout << sustainability << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}