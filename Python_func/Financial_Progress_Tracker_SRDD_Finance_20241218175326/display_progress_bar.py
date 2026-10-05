def display_progress_bar(self, percentage):
        bar_length = 50
        filled_length = int(bar_length * percentage // 100)
        bar = 'â–ˆ' * filled_length + '-' * (bar_length - filled_length)
        print(f"[{bar}] {percentage:.2f}%")