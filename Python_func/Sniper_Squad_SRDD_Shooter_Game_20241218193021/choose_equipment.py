def choose_equipment(self):
        print("Choose your equipment:")
        for i, equip in enumerate(self.equipment):
            print(f"{i + 1}. {equip.name} - {equip.type}")
        choice = int(input("Enter equipment number: ")) - 1
        selected_equipment = self.equipment[choice]
        selected_equipment.upgrade_equipment()