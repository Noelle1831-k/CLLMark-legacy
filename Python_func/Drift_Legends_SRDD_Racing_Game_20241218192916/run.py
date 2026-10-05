def run(self):
        while self.running:
            self.input_handler.process_input()
            self.update()
            self.render()