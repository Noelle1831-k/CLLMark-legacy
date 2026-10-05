def check_milestones(self):
        '''
        Checks whether the current amount has reached any milestone and triggers a milestone message.
        '''
        for milestone in sorted(self.milestones):
            if self.current_amount >= milestone:
                print(f"Milestone reached: {milestone} for goal '{self.name}'")
            else:
                print(f"Milestone {milestone} not reached for goal '{self.name}' yet.")