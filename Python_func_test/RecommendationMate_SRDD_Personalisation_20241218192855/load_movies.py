def load_movies(self):
        # Simulate loading movies from a CSV file
        try:
            with open('movies.csv', 'r') as file:
                reader = csv.DictReader(file)
                for row in reader:
                    self.movies.append(row)
        except FileNotFoundError:
            print("Movies file not found. No movies loaded.")
        except csv.Error:
            print("Error reading movies file. No movies loaded.")