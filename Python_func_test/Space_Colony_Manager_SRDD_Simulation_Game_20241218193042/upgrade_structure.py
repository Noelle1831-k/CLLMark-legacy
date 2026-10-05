def upgrade_structure(self, structure):
        '''
        Upgrades an existing structure if resources and structure type allow it.
        '''
        print(f"Upgrading {type(structure).__name__}...")
        upgrade_cost = {"food": 20, "water": 10, "energy": 25}
        if self.resource_manager.check_resources(upgrade_cost):
            if hasattr(structure, 'upgrade'):
                structure.upgrade()
                self.resource_manager.use_resources(upgrade_cost)
                print(f"{type(structure).__name__} upgraded successfully!")
            else:
                print(f"{type(structure).__name__} cannot be upgraded.")
        else:
            print(f"Not enough resources to upgrade {type(structure).__name__}.")