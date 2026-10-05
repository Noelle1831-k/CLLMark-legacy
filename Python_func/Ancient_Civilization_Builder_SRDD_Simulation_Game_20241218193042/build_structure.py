def build_structure(self, structure_type):
        new_structure = structure.Structure(structure_type, 1, 100)
        self.structures.append(new_structure)
        self.resource_manager.consume_resource('wood', new_structure.resource_cost)
        print(f"Built new {structure_type}.")