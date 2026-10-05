def get_watering_schedule(self, plant):
        print(f"Fetching watering schedule for plant: {plant}")
        if plant in self.plant_data:
            schedule = self.plant_data[plant]
            next_watering = self.calculate_next_watering(schedule["frequency"])
            print(f"Watering schedule for {plant}: Every {schedule['frequency']} days, {schedule['amount']} of water.")
            print(f"Next watering date: {next_watering}")
        else:
            print("Plant not found in database. Please add the plant first.")