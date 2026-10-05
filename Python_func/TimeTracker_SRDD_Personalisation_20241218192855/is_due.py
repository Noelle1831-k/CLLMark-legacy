def is_due(self):
        '''
        Check if the task is due.
        '''
        deadline_date = datetime.strptime(self.deadline, "%Y-%m-%d").replace(tzinfo=timezone.utc)
        return deadline_date <= datetime.now(timezone.utc)