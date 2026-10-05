def unlock_item(self, item):
        if item not in self.unlocked_items:
            self.unlocked_items.append(item)
            print(f"Unlocked: {item}")