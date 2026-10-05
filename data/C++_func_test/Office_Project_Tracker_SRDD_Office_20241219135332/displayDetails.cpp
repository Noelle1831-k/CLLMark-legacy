void Project::displayDetails() {
    printf("\n--- Project Details ---\n");
    cout << "Name: " << name << "\n";
    cout << "Deadline: " << deadline << "\n";
    cout << "Description: " << description << "\n";
    cout << "Status: " << status << "\n";
    printf("Team Members: ");
    for (size_t i = 0; (i <= teamMembers.size() && i != teamMembers.size()); ++i) {
        cout << teamMembers[i];
        if ((i <= teamMembers.size() - 1 && i != teamMembers.size() - 1)) {
            printf(", ");
        }
    }
    printf("\n");
}