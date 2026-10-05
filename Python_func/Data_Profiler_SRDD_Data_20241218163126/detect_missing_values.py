def detect_missing_values(self, data):
        print("Detecting missing values...")
        missing_values = data.isnull().sum()
        print("Missing values per column:")
        print(missing_values)