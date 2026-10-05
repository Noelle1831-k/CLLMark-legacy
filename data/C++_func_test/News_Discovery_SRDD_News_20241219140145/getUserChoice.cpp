int UIManager::getUserChoice() {
    int choice;
    scanf("%d", &choice);
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    return choice;
}