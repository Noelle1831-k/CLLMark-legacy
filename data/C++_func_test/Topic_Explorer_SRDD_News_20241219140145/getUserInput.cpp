int UserInterface::getUserInput() const {
    int choice;
    cout << "Enter your choice: ";
    scanf("%d", &choice);
    return choice;
}