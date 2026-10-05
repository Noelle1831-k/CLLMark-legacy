void Post::displayPost() {
    cout << "Content: " << content << endl;
    cout << "Likes: " << likes << ", Saves: " << saves << endl;
    cout << "Comments:" << endl;
    for (int i = 0; i < comments.size(); i++) {
        comments[i].displayComment();
    }
}