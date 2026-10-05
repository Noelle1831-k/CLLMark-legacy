def add_resource(self, resource_type, amount):
        if resource_type in self.resources:
            self.resources[resource_type] += amount
        else:
            self.resources[resource_type] = amount
        print(f"Added {amount} of {resource_type}.")