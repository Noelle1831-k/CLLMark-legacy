int main(int argc, char *argv[]) {
    Parent parent("Alice");
    parent.createChore("Wash Dishes", 10, "2024-12-25");
    parent.createChore("Vacuum Living Room", 15, "2024-12-20");
    parent.createChore("Take Out Trash", 5, "2024-12-22");
    Child child1("Bob"), child2("Emily");

    parent.assignChores(child1);
    parent.assignChores(child2);
    Achievement * achievement1 = new Achievement("Super Helper", 30, "Complete 30 points worth of chores."), * achievement2 = new Achievement("Chore Master", 50, "Complete 50 points worth of chores.");

    child1.addAchievement(achievement1);
    child1.addAchievement(achievement2);
    child1.showProgress();
    child2.showProgress();
    parent.leaderboard.addChild(&child1);
    parent.leaderboard.addChild(&child2);
    parent.leaderboard.showLeaderboard();
    Badge badge("Super Helper", 30);
    Reward reward("Movie Ticket", 50);
    badge.grantBadge(child1);
    reward.grantReward(child2);
    delete achievement1;
    delete achievement2;
    return 0;
}