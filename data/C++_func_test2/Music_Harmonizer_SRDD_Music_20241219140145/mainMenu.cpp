void mainMenu() {
        int choice = 0;
        while (choice != 4) {
            displayMenu();
            choice = validateInput();
            switch (choice) {
                case 1:
                    processFile();
                    break;
                case 2:
                    previewHarmony();
                    break;
                case 3:
                    saveHarmonizedFile();
                    break;
                case 4:
                    cout << "Exiting application. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }