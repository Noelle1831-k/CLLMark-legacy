def upgrade_structure(self, structure_id):
        if structure_id < len(self.structures):
            structure_to_upgrade = self.structures[structure_id]
            self.resource_manager.consume_resource('stone', structure_to_upgrade.resource_cost)
            structure_to_upgrade.upgrade()
            print(f"Upgraded structure {structure_id}.")
        else:
            print("Invalid structure ID.")