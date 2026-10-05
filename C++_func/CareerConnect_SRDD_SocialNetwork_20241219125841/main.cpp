int main() {
    CareerConnectApp app;
    app.registerUser("Alice", "alice@example.com", "Software Engineering", false);
    app.registerUser("Bob", "bob@example.com", "Software Engineering", true);
    app.addEvent("Virtual Career Fair", "2023-12-01");
    app.addEvent("Tech Workshop", "2023-12-15");
    app.searchUsersByIndustry("Software Engineering");
    app.listEvents();
    return 0;
}