void UIManager::displayMenu() {
    while (true) {
        cout << "\n--- TaskPro Menu ---\n";
        cout << "1. Add Task\n2. Delete Task\n3. Sort Tasks by Priority\n4. Show Daily Overview\n";
        cout << "5. Show Completed Tasks\n6. Mark Task as Completed\n7. Exit\n";
        handleUserInput();
    }
}