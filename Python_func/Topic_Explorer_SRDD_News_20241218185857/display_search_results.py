def display_search_results(self):
        print("Search Results:")
        for index, result in enumerate(self.search_results, start=1):
            print(f"{index}. {result}")