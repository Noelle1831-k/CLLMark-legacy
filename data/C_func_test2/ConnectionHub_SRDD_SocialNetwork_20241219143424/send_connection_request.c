void send_connection_request() {
    char name[50];
    printf("Enter the name of the user to connect with: ");
    scanf("%s", name);
    printf("Connection request sent to %s.\n", name);
}