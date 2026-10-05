int main() {
    Library library;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); 
        handleUserChoice(library);
    } while (choice != 0);
    cout << "Exiting the program. Goodbye!" << endl;
    return 0;
}