def list_projects(self):
        if not self.projects:
            print("No projects available.")
        else:
            for idx, project in enumerate(self.projects, start=1):
                print(f"{idx}. {project['name']} - {project['description']}")