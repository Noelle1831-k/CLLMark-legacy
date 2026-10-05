def process_data(self, data):
        # Process collected data
        processed = {}
        for key, value in data.items():
            processed[key] = self._process(key, value)
        return processed