def create_project(self, project_name):
        if not self.database.project_exists(project_name):
            self.database.save_project(project_name)
            print(f"Project '{project_name}' created.")
        else:
            print(f"Project '{project_name}' already exists.")