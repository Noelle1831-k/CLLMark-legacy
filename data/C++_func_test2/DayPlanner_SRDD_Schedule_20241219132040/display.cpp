void Task::display() const {
    cout << "ID: " << id << ", Title: " << title << ", Category: " << category
         << ", Priority: " << priority << ", Completed: " << (completed ? "Yes" : "No") << endl;
}