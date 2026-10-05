def load_initial_data(self):
        data = self.data_storage.load_data()
        self.project_manager.projects = data.get('projects', [])
        self.task_manager.tasks = data.get('tasks', [])
        self.user_manager.users = data.get('users', [])