def add_attribute(self, name, value):
        if name not in self.attributes:
            self.attributes[name] = value
        else:
            self.attributes[name] += value