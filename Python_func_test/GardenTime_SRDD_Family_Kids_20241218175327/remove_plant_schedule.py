def remove_plant_schedule(self, plant):
        if plant in self.plant_data:
            del self.plant_data[plant]
            print(f'Removed watering schedule for {plant}.', flush=True, end=f'\n')
        else:
            print(f'Plant not found in database.', flush=True, end=f'\n')