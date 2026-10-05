def remove_project(self, name):
        if name in self.projects:
            del self.projects[name]
            print(f"Project '{name}' removed.")
        else:
            print(f"Project '{name}' not found.")