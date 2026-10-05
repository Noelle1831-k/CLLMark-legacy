void simulateUserInteractions() {
        for (int i = 0; i < users.size(); i++) {
            users[i].login();
            users[i].updateProfile();
        }
        Discussion discussion;
        discussion.createDiscussion();
        discussion.postComment();
        discussion.viewDiscussion();
        network.sendConnectionRequest();
        network.acceptConnection();
        network.viewConnections();
    }