def list_projects(self):
        if self.projects:
            print("Projects:")
            for name in self.projects:
                print(f"- {name}")
        else:
            print("No projects available.")