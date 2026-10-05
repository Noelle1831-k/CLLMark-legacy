def update_plant_schedule(self, plant, frequency, amount):
        if plant in self.plant_data:
            self.plant_data[plant] = {"frequency": frequency, "amount": amount}
            print(f"Updated watering schedule for {plant}: Every {frequency} days, {amount} of water.")
        else:
            print("Plant not found in database. Please add the plant first.")