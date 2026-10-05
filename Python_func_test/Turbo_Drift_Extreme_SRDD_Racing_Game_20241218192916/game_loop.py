def game_loop(self):
        start_time = time.time()
        while self.running:
            self.process_input()
            self.update_game_state()
            self.render_graphics()
            self.check_game_over()
            time.sleep(max(0, 1/60 - (time.time() - start_time)))
            start_time = time.time()