#pragma once

#include "Item.h"
#include "Object.h"


class Smithy
{
private:

	Graphic* _blackSmith;
	Graphic* _anvil;
	Graphic* _title;
	Graphic* _itemName;
	Graphic* _upgradable;
	Graphic* _notUpgradeble;
	Graphic* _upgradeRecipe;
	Graphic* _itemList;
	Graphic* _pSword;

	Graphic* _pocket;
	Graphic* _pocketCircle;
	Graphic* _coin;

	//대장간이 켜졌습니까?
	bool _isShow;

public:

	void Init();
	void Update();
	void Release();
	void Render();

	void KeyInput(); 
	
	DWORD convert_ansi_to_unicode_string(
		__out std::wstring& unicode,
		__in const char* ansi,
		__in const size_t ansi_size
	) {
		DWORD error = 0;
		do {
			if ((nullptr == ansi) || (0 == ansi_size)) {
				error = ERROR_INVALID_PARAMETER;
				break;
			}
			unicode.clear();
			//
			// getting required cch.
			//
			int required_cch = ::MultiByteToWideChar(
				CP_ACP,
				0,
				ansi, static_cast<int>(ansi_size),
				nullptr, 0
			);
			if (0 == required_cch) {
				error = ::GetLastError();
				break;
			}
			unicode.resize(required_cch);
			//
			// convert.
			//
			if (0 == ::MultiByteToWideChar(
				CP_ACP,
				0,
				ansi, static_cast<int>(ansi_size),
				const_cast<wchar_t*>(unicode.c_str()), static_cast<int>(unicode.size())
			)) {
				error = ::GetLastError();
				break;
			}
		} while (false);
		return error;
	}

};

