def view_meetings(meetings):
    if not meetings:
        print("No meetings available to view.")
        return
    for idx, meeting in enumerate(meetings):
        print(f"\nMeeting {idx + 1}:")
        display_meeting_details(meeting)