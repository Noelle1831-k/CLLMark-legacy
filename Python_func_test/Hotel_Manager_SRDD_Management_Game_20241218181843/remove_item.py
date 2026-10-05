def remove_item(self, item, quantity):
        if item in self.items and self.items[item] >= quantity:
            self.items[item] -= quantity