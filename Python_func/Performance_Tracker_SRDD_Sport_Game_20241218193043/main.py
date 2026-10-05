def main():
    data_handler = DataHandler()
    athletes = data_handler.load_data()
    app = Application(athletes, data_handler)
    app.run()