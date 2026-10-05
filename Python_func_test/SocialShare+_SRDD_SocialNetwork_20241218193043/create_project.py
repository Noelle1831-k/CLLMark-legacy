def create_project(self, project_name):
        project = Project(project_name)
        self.projects.append(project)
        return project