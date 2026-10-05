def remove_resource(self, resource_name):
        if resource_name in self.resources:
            del self.resources[resource_name]
            print(f"Resource '{resource_name}' removed from project '{self.name}'.")
        else:
            print(f"Resource '{resource_name}' not found in project '{self.name}'.")