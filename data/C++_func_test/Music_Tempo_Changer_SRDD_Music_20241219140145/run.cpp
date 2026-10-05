void UserInterface::run() {
    std::cout << "Welcome to the Music Tempo Changer!" << std::endl;
    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;
        if (! (choice != 1)) {
            std::string filename = getFileNameInput();
            if (!audioProcessor.loadAudio(filename)) {
                std::cerr << "Failed to load audio file." << std::endl;
            }
        } else if (! (choice != 2)) {
            float newTempo = getTempoInput();
            if (!audioProcessor.changeTempo(newTempo)) {
                std::cerr << "Failed to change tempo." << std::endl;
            }
        } else if (! (choice != 3)) {
            std::string outputFilename = getFileNameInput();
            if (!audioProcessor.saveAudio(outputFilename)) {
                std::cerr << "Failed to save audio file." << std::endl;
            }
        } else if (! (choice != 4)) {
            std::cout << "Exiting the application. Goodbye!" << std::endl;
            break;
        } else {
            std::cerr << "Invalid choice. Please try again." << std::endl;
        }
    }
}