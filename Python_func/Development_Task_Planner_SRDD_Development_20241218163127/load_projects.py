def load_projects(self, projects_data):
        '''
        Loads projects from a given data source.
        Parameters:
        - projects_data: A list of project data dictionaries.
        '''
        for project_data in projects_data:
            project = Project(**project_data)
            self.add_project(project)