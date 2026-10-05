void GroupChatApp::run() {
    string command;
    while (true) {
        cout << "Enter command (register, create, join, send, list, exit): ";
        cin >> command;
        if (command == "exit") break;
        else if (command == "register") {
            string username;
            cout << "Enter username: ";
            cin >> username;
            registerUser(username);
        } else if (command == "create") {
            string username, groupName;
            cout << "Enter username: ";
            cin >> username;
            User* user = findUser(username);
            if (user) {
                cout << "Enter group name: ";
                cin >> groupName;
                createGroup(groupName, user);
            }
        } else if (command == "join") {
            string username, groupName;
            cout << "Enter username: ";
            cin >> username;
            User* user = findUser(username);
            if (user) {
                cout << "Enter group name: ";
                cin >> groupName;
                Group* group = findGroup(groupName);
                if (group) user->joinGroup(group);
            }
        } else if (command == "send") {
            string username, groupName, content;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter group name: ";
            cin >> groupName;
            cout << "Enter message: ";
            cin.ignore();
            getline(cin, content);
            sendMessage(groupName, username, content);
        } else if (command == "list") {
            string username;
            cout << "Enter username: ";
            cin >> username;
            User* user = findUser(username);
            if (user) user->listGroups();
        }
    }
}