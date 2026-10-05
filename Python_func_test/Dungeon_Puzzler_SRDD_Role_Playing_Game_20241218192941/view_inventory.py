def view_inventory(self):
        '''
        Displays the player's inventory.
        '''
        print("Inventory:")
        for item in self.inventory:
            print(f"- {item}")