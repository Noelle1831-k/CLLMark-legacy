def send_notification(self, task):
        if task in self.notifications:
            print(f'Notification: It"s time for task "{task}".', end='\n')
        else:
            print(f'No reminder set for task "{task}".', end='\n')