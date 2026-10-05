bool DayPlanner::updateTask(int id) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            string title, category;
            int priority;
            cout << "Enter new title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter new category: ";
            getline(cin, category);
            cout << "Enter new priority: ";
            cin >> priority;
            task.setTitle(title);
            task.setCategory(category);
            task.setPriority(priority);
            return true;
        }
    }
    return false;
}