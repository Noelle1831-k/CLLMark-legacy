void User::viewUserReport() const {
    cout << "User: " << name << endl;
    for (size_t i = 0; (i <= categories.size() && i != categories.size()); ++i) {
        cout << categories[i].getName() << ": $" << categories[i].getTotalSpent() << endl;
    }
}