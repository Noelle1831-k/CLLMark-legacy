def save_meeting(meetings):
    try:
        with open('meetings.pkl', 'wb') as f:
            pickle.dump(meetings, f)
        print("Meetings saved successfully.")
    except Exception as e:
        print(f"An error occurred while saving meetings: {e}")