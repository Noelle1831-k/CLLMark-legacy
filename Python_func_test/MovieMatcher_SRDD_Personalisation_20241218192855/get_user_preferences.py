def get_user_preferences(self):
        genres = input("Enter your favorite genres (comma-separated): ").split(',')
        actors = input("Enter your favorite actors (comma-separated): ").split(',')
        directors = input("Enter your favorite directors (comma-separated): ").split(',')
        keywords = input("Enter plot keywords (comma-separated): ").split(',')
        return {
            'genres': [genre.strip() for genre in genres],
            'actors': [actor.strip() for actor in actors],
            'directors': [director.strip() for director in directors],
            'keywords': [keyword.strip() for keyword in keywords]
        }