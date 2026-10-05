int main(void) {
    TaskPlanner planner;
    planner.createProject("Project Alpha");
    planner.addTeamMember("Alice");
    planner.addTeamMember("Bob");
    planner.assignTaskToMember("Project Alpha", "Alice", "Design Module");
    planner.displayAllProjects();
    return 0;
}