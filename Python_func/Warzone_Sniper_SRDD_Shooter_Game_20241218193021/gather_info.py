def gather_info(self):
        # Simulate gathering intelligence data
        new_data = f"Intel data at position {len(self.data) + 1}"
        self.data.append(new_data)
        print(f"Gathering intelligence data: {new_data}")