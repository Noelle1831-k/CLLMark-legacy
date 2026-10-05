def add_plant_schedule(self, plant, frequency, amount):
        if plant not in self.plant_data:
            self.plant_data[plant] = {"frequency": frequency, "amount": amount}
            print(f"Added watering schedule for {plant}: Every {frequency} days, {amount} of water.")
        else:
            print("Plant already exists. Use update_plant_schedule to modify existing data.")