void SocialLivestreamApp::addReactionToStream(Livestream* stream, User* user, string reactionType) {
    Reaction newReaction(user, reactionType);
    stream->addReaction(newReaction);
}