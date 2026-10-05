def load_tasks(self):
        '''
        Load tasks from a file.
        '''
        try:
            with open(self.file_path, 'r') as file:
                tasks_data = json.load(file)
                return [Task(**task_data) for task_data in tasks_data]
        except FileNotFoundError:
            return []