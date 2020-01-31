#pragma once
#include"singletonBase.h"
class JsonManager : public singletonBase<JsonManager>
{

public:

	void WriteJson(string jsonName, vector<string> strings, vector<int> integers);

};

