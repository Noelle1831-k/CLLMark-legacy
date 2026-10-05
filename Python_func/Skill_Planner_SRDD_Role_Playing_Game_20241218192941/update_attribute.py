def update_attribute(self, attr_name, value):
        if attr_name in self.attributes:
            self.attributes[attr_name] += value
        else:
            print(f"Attribute {attr_name} does not exist.")