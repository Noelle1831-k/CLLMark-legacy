def get_sleep_quality(self):
        quality = input("Rate your sleep quality (1-10): ")
        self.data['sleep_quality'] = int(quality)