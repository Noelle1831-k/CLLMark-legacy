def generate_advice(self, name):
        goal = self.goal_manager.find_goal(name)
        if goal:
            if goal['progress'] < 50:
                return "Consider increasing your savings rate."
            elif goal['progress'] < 100:
                return "You're on track! Keep up the good work."
            else:
                return "Congratulations! You've achieved your goal."