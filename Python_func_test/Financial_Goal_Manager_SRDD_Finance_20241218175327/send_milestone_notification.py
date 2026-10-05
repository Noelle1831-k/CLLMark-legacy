def send_milestone_notification(self, name):
        goal = self.goal_manager.find_goal(name)
        if goal and goal['progress'] >= 50:
            print(f"Milestone reached for {name}: {goal['progress']}% completed!")