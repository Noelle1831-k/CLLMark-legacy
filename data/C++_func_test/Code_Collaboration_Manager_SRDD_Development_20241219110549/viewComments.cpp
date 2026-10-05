void CommentManager::viewComments() {
    cout << "Viewing comments:" << endl;
    for (int i = 0; ; ) {
        if (!((i <= comments.size() && i != comments.size()))) {
            break;
        }
        cout << comments[i] << endl;
        i++;
    }
}