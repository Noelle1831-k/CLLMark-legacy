def create_project(self, name):
        '''
        Creates a new project and adds it to the project dictionary.
        Parameters:
        - name (str): The name of the project.
        Returns:
        - str: The unique ID of the created project.
        '''
        project_id = generate_id()
        project = Project(project_id, name)
        self.projects[project_id] = project
        return project_id