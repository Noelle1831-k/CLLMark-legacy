def get_status(self):
        return f"Health: {self.health}, Inventory: {[item.describe() for item in self.inventory]}"