def update_scores(self, score_manager, data_fetcher):
        print("Updating scores...")
        new_data = data_fetcher.fetch_data()
        for game, score in new_data.items():
            score_manager.update_game_score(game, score)
        self.display_scores(score_manager.get_scores())