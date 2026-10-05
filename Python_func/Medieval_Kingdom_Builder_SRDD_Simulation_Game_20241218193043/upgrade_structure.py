def upgrade_structure(self, structure):
        if structure in self.structures:
            structure.upgrade()
        else:
            raise ValueError("Structure not found in kingdom")