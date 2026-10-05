def _process(self, key, value):
        # Process a single data point based on its type
        if key in ["brightness", "volume"]:
            return [v * 2 for v in value]
        elif key == "resolution":
            return value  # No change for resolution
        else:
            return value  # Default processing