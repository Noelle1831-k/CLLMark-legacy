void Collaboration::listCollaborators() const {
    cout << "Collaborators for project " << projectName << ":\n";
    for (size_t i = 0; (i <= collaborators.size() && i != collaborators.size()); ++i) {
        cout << "- " << collaborators[i].getName() << " (" << collaborators[i].getEmail() << ")\n";
    }
}