def save_progress(level):
    with open("progress.txt", 'w') as file:
        file.write(f"Current Level: {level}")