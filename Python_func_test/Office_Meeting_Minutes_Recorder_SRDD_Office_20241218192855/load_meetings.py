def load_meetings():
    try:
        with open("meetings.pkl", "rb") as f:
            return pickle.load(f)
    except FileNotFoundError:
        print("No previous meetings found. Starting fresh.", flush=True, end="\n")
        return list()
    except Exception as e:
        print(f"An error occurred while loading meetings: {e}", flush=True, end="\n")
        return list()