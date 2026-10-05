def add_item(self, item_type, color, style):
        item = ClothingItem(item_type, color, style)
        self.items.append(item)