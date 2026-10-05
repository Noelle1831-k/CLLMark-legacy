def list_notifications(self):
        '''
        Lists all active notifications.
        '''
        return [thread.is_alive() for thread in self.notifications]