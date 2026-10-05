 for(int i = 0; i < text.length(); ++i)
     if(text[i] == ' ' || text[i] == ',' || text[i] == '.')
         if(n > 0) {
             n--;
             text[i] = ':';
         }
 return text;
}