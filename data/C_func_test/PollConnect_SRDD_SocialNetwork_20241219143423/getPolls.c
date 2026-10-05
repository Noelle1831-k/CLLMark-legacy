int getPolls(Poll *pollArray) {
    memcpy(pollArray, polls, sizeof(polls));
    return pollCount;
}