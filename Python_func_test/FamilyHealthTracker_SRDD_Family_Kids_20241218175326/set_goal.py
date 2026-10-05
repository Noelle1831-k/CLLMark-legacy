def set_goal(self, user_profile, goal_description, deadline):
        if user_profile not in self.goals:
            self.goals[user_profile] = []
        self.goals[user_profile].append((goal_description, deadline))