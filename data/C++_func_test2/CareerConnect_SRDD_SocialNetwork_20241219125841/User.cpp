User(string name, string email, string industry, bool isProfessional) {
        this->userID = generateUniqueID();
        this->name = name;
        this->email = email;
        this->industry = industry;
        this->isProfessional = isProfessional;
    }