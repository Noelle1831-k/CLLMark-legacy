void Post::addComment(string commenter, string commentContent) {
    Comment newComment(commenter, commentContent);
    comments.push_back(newComment);
    cout << "Comment added successfully!" << endl;
}