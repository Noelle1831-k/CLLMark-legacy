void Collaboration::inviteCollaborator(User& user) {
    collaborators.push_back(user);
    cout << "Collaborator " << user.getName() << " invited successfully!\n";
}