void SocialLivestreamApp::addCommentToStream(Livestream* stream, User* user, string commentText) {
    Comment newComment(user, commentText);
    stream->addComment(newComment);
}