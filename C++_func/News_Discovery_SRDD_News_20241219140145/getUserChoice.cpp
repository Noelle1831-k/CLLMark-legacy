int UIManager::getUserChoice() {
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    return choice;
}