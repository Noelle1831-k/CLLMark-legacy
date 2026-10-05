void SocialLivestreamApp::createUser(string name, string picture) {
    User* newUser = new User(name, picture);
    users.push_back(newUser);
}