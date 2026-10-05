def display_recommendations(self, recommendations):
        if recommendations:
            print("Recommended Movies:")
            for movie in recommendations:
                print(movie)
        else:
            print("No movies found matching your preferences.")