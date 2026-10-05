def assign_goal(self, goal_title, member_name):
        goal = next((g for g in self.goals if g.title == goal_title), None)
        member = next((m for m in self.family_members if m.name == member_name), None)
        if goal and member:
            goal.assign_to(member)