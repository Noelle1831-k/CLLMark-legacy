void CommentManager::viewComments() {
    cout << "Viewing comments:" << endl;
    for (int i = 0; i < comments.size(); i++) {
        cout << comments[i] << endl;
    }
}