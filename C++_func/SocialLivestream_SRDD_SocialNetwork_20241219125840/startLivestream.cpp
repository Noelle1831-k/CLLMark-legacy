void SocialLivestreamApp::startLivestream(User* user, string title) {
    Livestream* newStream = new Livestream(user, title);
    newStream->startStream();
    livestreams.push_back(newStream);
}