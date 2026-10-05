void SocialLivestreamApp::run() {
    cout << "Welcome to SocialLivestream!" << endl;
    createUser("Alice", "alice.jpg");
    createUser("Bob", "bob.jpg");
    User* alice = users[0];
    User* bob = users[1];
    startLivestream(alice, "Alice's Adventure");
    Livestream* stream = livestreams[0];
    addCommentToStream(stream, bob, "Great stream!");
    addReactionToStream(stream, bob, "like");
    stopLivestream(stream);
}