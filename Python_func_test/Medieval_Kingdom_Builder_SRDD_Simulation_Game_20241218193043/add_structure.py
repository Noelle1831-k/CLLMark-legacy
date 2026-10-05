def add_structure(self, structure_type):
        if structure_type == "Castle":
            structure = Castle()
        elif structure_type == "Farm":
            structure = Farm()
        elif structure_type == "Market":
            structure = Market()
        else:
            raise ValueError("Unknown structure type")
        self.structures.append(structure)
        structure.build()