def start_server(self):
        threading.Thread(target=self.app.run, kwargs={'debug': True}).start()