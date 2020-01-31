#include "stdafx.h"
#include "JsonManager.h"

void JsonManager::WriteJson(string jsonName, vector<string> strings, vector<int> integers)
{
    const char* json = "{ \"Player\": \"world\", \
                             \"t\": true , \
                             \"f\": false, \
                             \"n\": null, \
                             \"i\": 123, \
                             \"pi\": 3.1416, \
                             \"a\": [1, 2, 3, 4], \
                             \"info\":{\"user\":\"test\",\"num\":123} }";
    char j[1024];


    sprintf_s(j, "{");

    Document root;
    root.Parse("json.json");

    string a = root["Player"].GetString();
    root.SetString("");
    const char* kkk = a.c_str();

}
