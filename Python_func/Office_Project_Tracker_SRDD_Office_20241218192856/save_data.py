def save_data(self, projects, tasks, users):
        data = {
            'projects': projects,
            'tasks': tasks,
            'users': users
        }
        with open(self.file_path, 'w') as file:
            json.dump(data, file, indent=4)
        print("Data saved successfully.")