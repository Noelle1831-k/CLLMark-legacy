def update_project(self, project_id, **kwargs):
        '''
        Updates the attributes of a project.
        Parameters:
        - project_id: The ID of the project to update.
        - kwargs: Key-value pairs of attributes to update.
        '''
        project = self.get_project_by_id(project_id)
        if project:
            for key, value in kwargs.items():
                setattr(project, key, value)