def main():
    '''
    Entry point of the application.
    '''
    try:
        run_application()
    except Exception as e:
        print(f"An error occurred: {e}")
        sys.exit(1)