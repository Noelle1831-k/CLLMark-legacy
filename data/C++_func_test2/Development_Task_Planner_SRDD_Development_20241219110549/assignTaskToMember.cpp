void TaskPlanner::assignTaskToMember(string projectName, string memberName, string taskName) {
    for (vector<Project>::iterator projIt = projects.begin(); projIt != projects.end(); ++projIt) {
        if (projIt->getProjectName() == projectName) {
            Task newTask(projIt->getTasks().size() + 1, taskName, "Description", "Open", 1);
            projIt->addTask(newTask);
            for (vector<TeamMember>::iterator memIt = teamMembers.begin(); memIt != teamMembers.end(); ++memIt) {
                if (memIt->getName() == memberName) {
                    memIt->assignTask(newTask);
                }
            }
        }
    }
}