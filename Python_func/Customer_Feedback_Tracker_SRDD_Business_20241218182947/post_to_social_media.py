def post_to_social_media():
    '''
    Distribute feedback forms via social media platforms.
    '''
    print("Posting feedback form to social media...")
    url = "https://api.socialmedia.com/post"
    payload = {
        "message": "Please fill out our feedback form!",
        "link": "http://example.com/feedback-form"
    }
    headers = {
        "Authorization": "Bearer YOUR_ACCESS_TOKEN"
    }
    try:
        response = requests.post(url, json=payload, headers=headers)
        if response.status_code == 200:
            print("Posted to social media successfully.")
        else:
            print(f"Failed to post to social media: {response.status_code}")
    except Exception as e:
        print(f"Error posting to social media: {e}")