int main() {
    Family family;
    FamilyMember member1("Alice");
    FamilyMember member2("Bob");
    family.addMember(member1);
    family.addMember(member2);
    Goal goal1("Exercise", "Daily exercise routine", "2023-12-31");
    Goal goal2("Study", "Complete C++ course", "2023-11-30");
    member1.addGoal(goal1);
    member2.addGoal(goal2);
    family.assignGoal(member1, goal1);
    family.assignGoal(member2, goal2);
    family.trackProgress();
    family.celebrateAchievements();
    Visualization viz;
    viz.generateProgressChart(family);
    Reminder reminder;
    reminder.setReminder(goal1);
    reminder.sendReminder();
    return 0;
}