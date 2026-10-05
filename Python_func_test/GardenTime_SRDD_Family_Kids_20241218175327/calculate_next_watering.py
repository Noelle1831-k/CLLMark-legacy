def calculate_next_watering(self, frequency):
        today = datetime.date.today()
        next_watering_date = today + datetime.timedelta(days=frequency)
        return next_watering_date