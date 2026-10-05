def add_project(self, name):
        if name not in self.projects:
            self.projects[name] = Project(name)
            print(f"Project '{name}' added.")
        else:
            print(f"Project '{name}' already exists.")