regex emailPattern(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)"); 
if (regex_match(email, emailPattern)) 
    return "Valid Email"; 
else 
    return "Invalid Email";
}