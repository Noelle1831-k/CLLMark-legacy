void run() {
        cout << "Welcome to the Personal Happiness Tracker!" << endl;
        string name;
        int age;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your age: ";
        cin >> age;
        user = new User(name, age);
        int choice;
        do {
            displayMenu();
            cin >> choice;
            handleUserInput(choice);
        } while (choice != 4);
    }