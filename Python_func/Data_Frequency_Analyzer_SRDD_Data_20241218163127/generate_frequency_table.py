def generate_frequency_table(self):
        try:
            frequency_table = self.data[self.variable].value_counts().reset_index()
            frequency_table.columns = [self.variable, 'Frequency']
            print("Frequency table generated successfully.")
            return frequency_table
        except Exception as e:
            print(f"Error generating frequency table: {e}")
            return None