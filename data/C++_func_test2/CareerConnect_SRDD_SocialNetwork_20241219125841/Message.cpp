Message(string senderID, string receiverID, string content) {
        this->messageID = generateUniqueID();
        this->senderID = senderID;
        this->receiverID = receiverID;
        this->content = content;
        this->timestamp = time(0);
    }