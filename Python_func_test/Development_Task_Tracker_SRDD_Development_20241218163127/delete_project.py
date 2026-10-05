def delete_project(self, project_id):
        '''
        Deletes a project from the project dictionary.
        Parameters:
        - project_id (str): The unique ID of the project to be deleted.
        '''
        if project_id in self.projects:
            del self.projects[project_id]