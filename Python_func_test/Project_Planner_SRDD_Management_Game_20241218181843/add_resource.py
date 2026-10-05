def add_resource(self, resource_name):
        if resource_name not in self.resources:
            self.resources[resource_name] = Resource(resource_name)
            print(f"Resource '{resource_name}' added to project '{self.name}'.")
        else:
            print(f"Resource '{resource_name}' already exists in project '{self.name}'.")