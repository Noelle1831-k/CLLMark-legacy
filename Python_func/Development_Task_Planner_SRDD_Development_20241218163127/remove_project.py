def remove_project(self, project_id):
        '''
        Removes a project from the manager based on its ID.
        Parameters:
        - project_id: The ID of the project to remove.
        '''
        self.projects = [project for project in self.projects if project.id != project_id]