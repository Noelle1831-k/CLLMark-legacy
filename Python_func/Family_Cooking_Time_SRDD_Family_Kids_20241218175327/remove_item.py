def remove_item(self, item):
        if item in self.items:
            self.items.remove(item)
            print(f"Item {item} removed from grocery list.")
        else:
            print(f"Item {item} not found in grocery list.")