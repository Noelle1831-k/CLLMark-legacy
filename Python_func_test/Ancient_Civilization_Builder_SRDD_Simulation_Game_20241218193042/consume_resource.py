def consume_resource(self, resource_type, amount):
        if resource_type in self.resources and self.resources[resource_type] >= amount:
            self.resources[resource_type] -= amount
            print(f"Consumed {amount} of {resource_type}.")
        else:
            print(f"Not enough {resource_type} to consume.")