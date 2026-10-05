def save_tasks(self, tasks):
        '''
        Save tasks to a file.
        '''
        with open(self.file_path, 'w') as file:
            json.dump([task.__dict__ for task in tasks], file, default=str)