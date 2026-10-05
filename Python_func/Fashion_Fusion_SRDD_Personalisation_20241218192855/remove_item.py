def remove_item(self, item_index):
        if 0 <= item_index < len(self.items):
            del self.items[item_index]