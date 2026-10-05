int main() {
    ChallengeManager challengeManager;
    Display display;
    challengeManager.addChallenge("Solve Puzzle", 0, 30); 
    challengeManager.addChallenge("Build Tower", 1, 0);   
    challengeManager.addChallenge("Answer Quiz", 0, 45);  
    challengeManager.startChallenges();
    return 0;
}