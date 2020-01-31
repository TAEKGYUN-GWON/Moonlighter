#pragma once
#include"singletonBase.h"
class JsonManager : public singletonBase<JsonManager>
{
private:

	rapidjson::Document document;
	rapidjson::SizeType sizeType;
	rapidjson::Value value; 

public:
	void foo();
};

