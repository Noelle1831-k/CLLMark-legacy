Challenge* createChallenges() {
    Challenge *challenges = (Challenge*)malloc(sizeof(Challenge));
    challenges->weatherCondition = 0;
    challenges->competitionLevel = 0;
    return challenges;
}