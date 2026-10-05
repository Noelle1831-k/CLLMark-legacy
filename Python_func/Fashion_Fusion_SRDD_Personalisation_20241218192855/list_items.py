def list_items(self):
        return [item.get_details() for item in self.items]