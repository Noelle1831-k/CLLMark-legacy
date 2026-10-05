def display_timeline(self, goal):
        '''
        Displays a timeline showing the status of each milestone for the goal.
        '''
        print(f"Timeline for {goal.name}:")
        for milestone in sorted(goal.milestones):
            status = 'Reached' if goal.current_amount >= milestone else 'Pending'
            print(f"Milestone at {milestone}: {status}")