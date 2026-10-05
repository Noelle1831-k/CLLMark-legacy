def check_milestones(self):
        for milestone in self.milestones:
            if not milestone.reached and self.current_amount >= milestone.target_amount:
                milestone.reached = True