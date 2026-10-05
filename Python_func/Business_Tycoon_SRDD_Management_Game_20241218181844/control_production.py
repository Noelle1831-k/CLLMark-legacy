def control_production(self):
        print("Controlling production...")
        self.production_level += 10
        self.inventory_level += self.production_level