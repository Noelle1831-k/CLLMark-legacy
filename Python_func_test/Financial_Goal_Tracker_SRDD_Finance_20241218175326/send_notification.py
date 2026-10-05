def send_notification(self, goal):
        '''
        Sends a notification for every milestone reached for the given goal.
        '''
        for milestone in goal.milestones:
            if goal.current_amount >= milestone:
                notification = f'Notification: Milestone {milestone} reached for goal "{goal.name}".'
                self.notifications.append(notification)
                print(notification, end='\n')