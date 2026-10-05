def get_project_by_id(self, project_id):
        '''
        Retrieves a project by its ID.
        Parameters:
        - project_id: The ID of the project to retrieve.
        '''
        for project in self.projects:
            if project.id == project_id:
                return project
        return None