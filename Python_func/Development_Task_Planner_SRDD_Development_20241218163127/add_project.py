def add_project(self, project):
        '''
        Adds a new project to the manager and assigns it an ID.
        Parameters:
        - project: A Project object to add.
        '''
        project.id = self.next_id
        self.projects.append(project)
        self.next_id += 1