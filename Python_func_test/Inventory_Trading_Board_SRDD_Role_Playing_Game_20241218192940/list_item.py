def list_item(self, item):
        if item.owner in [user.username for user in self.users]:
            self.items.append(item)
            print(f"Item {item.name} listed successfully.")
        else:
            print(f"Owner {item.owner} not found in user database.")