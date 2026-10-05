def assign_to(self, resource):
        if resource not in self.assigned_resources:
            self.assigned_resources.append(resource)
            print(f"Resource '{resource}' assigned to task '{self.name}'.")
        else:
            print(f"Resource '{resource}' already assigned to task '{self.name}'.")