def load_data(self):
        movies = []
        try:
            with open('movies.csv', newline='', encoding='utf-8') as csvfile:
                reader = csv.DictReader(csvfile)
                for row in reader:
                    movies.append({
                        'title': row['title'],
                        'genres': row['genres'].split('|'),
                        'actors': row['actors'].split('|'),
                        'directors': row['directors'].split('|'),
                        'plot': row['plot']
                    })
        except FileNotFoundError:
            print("Error: movies.csv file not found.")
        return movies