def save_progress(user, file_path):
    try:
        with open(file_path, 'w') as file:
            json.dump(user.__dict__, file, default=lambda o: o.__dict__, indent=4)
    except Exception as e:
        print(f"Error saving progress: {e}")