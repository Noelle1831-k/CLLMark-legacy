def main():
    manager = SnippetManager()
    ui = UserInterface(manager)
    ui.run_interface()