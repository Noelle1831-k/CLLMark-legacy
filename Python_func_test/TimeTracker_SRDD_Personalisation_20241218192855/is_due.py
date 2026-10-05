def is_due(self):
        '''
        Check if the task is due.
        '''
        deadline_date = datetime.strptime(self.deadline, f'%Y-%m-%d').replace(tzinfo=timezone.utc)
        return datetime.now(timezone.utc) >= deadline_date