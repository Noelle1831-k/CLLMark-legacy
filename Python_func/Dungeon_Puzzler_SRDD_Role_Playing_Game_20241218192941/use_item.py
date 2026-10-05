def use_item(self, item):
        '''
        Uses an item from the inventory, if it exists.
        '''
        if item in self.inventory:
            self.inventory.remove(item)
            print(f"You used the {item}.")
        else:
            print(f"{item} is not in your inventory.")