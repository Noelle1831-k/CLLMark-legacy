def pick_item(self, item):
        '''
        Adds an item to the player's inventory.
        '''
        self.inventory.append(item)
        print(f"{item} has been added to your inventory.")