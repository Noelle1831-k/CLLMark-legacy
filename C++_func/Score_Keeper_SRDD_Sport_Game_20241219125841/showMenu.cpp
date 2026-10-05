void Dashboard::showMenu() {
    int choice;
    do {
        std::cout << "1. Add Team" << std::endl;
        std::cout << "2. Update Score" << std::endl;
        std::cout << "3. Display Scores" << std::endl;
        std::cout << "4. Start Timer" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        handleInput(choice);
    } while (choice != 5);  
}