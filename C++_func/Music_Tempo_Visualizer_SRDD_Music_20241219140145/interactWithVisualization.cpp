void UserInterface::interactWithVisualization() {
    char choice;
    do {
        cout << "Options: (z)oom, (p)an, (s)croll, (q)uit: ";
        cin >> choice;
        switch (choice) {
            case 'z': zoom(); break;
            case 'p': pan(); break;
            case 's': scroll(); break;
            case 'q': cout << "Exiting visualization." << endl; break;
            default: cout << "Invalid option." << endl; break;
        }
    } while (choice != 'q');
}