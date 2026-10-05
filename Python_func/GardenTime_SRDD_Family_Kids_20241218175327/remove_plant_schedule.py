def remove_plant_schedule(self, plant):
        if plant in self.plant_data:
            del self.plant_data[plant]
            print(f"Removed watering schedule for {plant}.")
        else:
            print("Plant not found in database.")