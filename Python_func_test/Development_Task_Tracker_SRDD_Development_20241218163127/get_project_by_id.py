def get_project_by_id(self, project_id):
        '''
        Retrieves a project by its unique ID.
        Parameters:
        - project_id (str): The unique ID of the project.
        Returns:
        - Project: The project object if found, else None.
        '''
        return self.projects.get(project_id, None)