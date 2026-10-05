def generate_unique_id(length=8):
    return ''.join(random.choices(string.ascii_letters + string.digits, k=length))