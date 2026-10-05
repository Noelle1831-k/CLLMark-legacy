void run() {
        int choice;
        do {
            ui.showMenu();
            choice = ui.handleUserInput();
            handleChoice(choice);
        } while (choice >= 1 && choice <= 3);
        cout << "Thank you for using the Virtual Library Tour App. Goodbye!" << endl;
    }