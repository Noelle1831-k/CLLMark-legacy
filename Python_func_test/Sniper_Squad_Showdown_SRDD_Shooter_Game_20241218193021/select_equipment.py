def select_equipment(self):
        print(f"{self.name} is selecting equipment...")
        equipment_options = ["Sniper Rifle", "Silencer", "Camouflage Suit"]
        print("Available equipment:", equipment_options)
        equipment_choice = input("Choose your equipment: ")
        if equipment_choice in equipment_options:
            self.equipment.append(equipment_choice)
        else:
            print("Invalid choice, defaulting to Sniper Rifle.")
            self.equipment.append("Sniper Rifle")