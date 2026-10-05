def list_resources(self):
        if self.resources:
            print(f"Resources in project '{self.name}':")
            for resource_name in self.resources:
                print(f"- {resource_name}")
        else:
            print(f"No resources in project '{self.name}'.")