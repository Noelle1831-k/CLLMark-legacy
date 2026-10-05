def add_milestone(self, milestone_name, target_amount):
        milestone = Milestone(milestone_name, target_amount)
        self.milestones.append(milestone)