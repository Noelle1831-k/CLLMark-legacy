def create_project(self):
        project_name = input("Enter project name: ")
        project_description = input("Enter project description: ")
        project = {
            'name': project_name,
            'description': project_description,
            'tasks': []
        }
        self.projects.append(project)
        print(f"Project '{project_name}' created successfully.")