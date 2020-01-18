#include "stdafx.h"
#include "Astar.h"

Astar::Astar()
{
}


Astar::~Astar()
{
}

void Astar::Init()
{
	_vTotalList.clear();
	SetTiles();
}

void Astar::SetTiles()
{
	//���� Ÿ��


	//��ü Ÿ�� ���Ƽ�
	for (int i = 0; i < TILENUMY; ++i)
	{
		for (int j = 0; j < TILENUMX; ++j)
		{
			Tile* node = new Tile;
			node->Init(j, i);
			
			_vTotalList.push_back(node);
		}
	}
}

void Astar::InitTotalList()
{
	
	for (Tile* t : _vTotalList)
	{
		t->SetCostF(-1);
		t->SetCostG(0);
		t->SetCostH(0);
		t->SetIsClose(0);
		t->SetIsOpen(0);
		t->SetParentNode(nullptr);
	}

	_OpenList.clear();
	_ClosedList.clear();
}


vector <Tile*> Astar::GetDirList(Vector2 idx)
{
	vector<Tile*> dirList;
	vector<Tile*> nodeList;

	
	if (CanOpenLeft(idx))
		nodeList.push_back(_vTotalList[((int)idx.x + TILENUMX * (int)idx.y) - 1]);


	
	if (CanOpenRight(idx))
		nodeList.push_back(_vTotalList[((int)idx.x + TILENUMX * (int)idx.y) + 1]);


	
	if (CanOpenUp(idx))
		nodeList.push_back(_vTotalList[((int)idx.x + TILENUMX * (int)idx.y) - TILENUMX]);


	if (CanOpenDown(idx))
		nodeList.push_back(_vTotalList[((int)idx.x + TILENUMX * (int)idx.y) + TILENUMX]);

	for (Tile* t : nodeList)
	{
	
		if (SetCost(t, 10, _vTotalList[((int)idx.x + TILENUMX * (int)idx.y)]))
			dirList.push_back(t);
	}

	nodeList.clear();


	if (CanOpenRight(idx) && CanOpenDown(idx))
		nodeList.push_back(_vTotalList[((int)idx.x + TILENUMX * (int)idx.y) + 1 + TILENUMX]);


	if (CanOpenLeft(idx) && CanOpenDown(idx))
		nodeList.push_back(_vTotalList[((int)idx.x + TILENUMX * (int)idx.y) - 1 + TILENUMX]);


	if (CanOpenRight(idx) && CanOpenUp(idx))
		nodeList.push_back(_vTotalList[((int)idx.x + TILENUMX * (int)idx.y) + 1 - TILENUMX]);


	if (CanOpenLeft(idx) && CanOpenUp(idx))
		nodeList.push_back(_vTotalList[((int)idx.x + TILENUMX * (int)idx.y) - 1 - TILENUMX]);

	for (Tile* t : nodeList)
	{
		if (SetCost(t, 14, _vTotalList[((int)idx.x + TILENUMX * (int)idx.y)]))
			dirList.push_back(t);
	}

	return dirList;
}

list<Vector2> Astar::pathFinder(Vector2 start, Vector2 end)
{
	InitTotalList();
	Vector2 startId((int)(start.x / TILEWIDTH), (int)(start.y / TILEHEIGHT));
	Vector2 endId((int)(end.x / TILEWIDTH), (int)(end.y / TILEHEIGHT));

	
	_startTile = _vTotalList[(int)startId.x + TILENUMX * (int)startId.y];
	_startTile->SetAttribute("start");

	_endTile = _vTotalList[(int)endId.x + TILENUMX * (int)endId.y];
	_endTile->SetAttribute("end");

	_currentTile = _startTile;
	AddOpenList(_currentTile);
	bool theEnd = false;
	while (!theEnd)
	{

		for (Tile* t : GetDirList(Vector2(_currentTile->GetIdX(), _currentTile->GetIdY())))
		{

			if (t == _endTile)
			{
				theEnd = true;
				SetPathcList();
				break;
			}
			else
				AddOpenList(t);
		}
		AddCloseList(_currentTile);
		_currentTile = GetMinFNode();
		if (_currentTile == nullptr) break;
	}
	return _pathList;
}

void Astar::Release()
{
}

void Astar::Update()
{


}

void Astar::Render()
{

	for (Tile* t : _vTotalList)
		t->Render();
}

bool Astar::CanOpenLeft(Vector2 idx)
{

	if (idx.x - (int)1 == 0) return false;
	if (_vTotalList[((int)idx.x + TILENUMX * (int)idx.y) - 1] == nullptr) return false;
	return true;
}

bool Astar::CanOpenRight(Vector2 idx)
{

	if (idx.x + (int)1 == TILENUMX) return false;
	if (_vTotalList[((int)idx.x + TILENUMX * (int)idx.y) + 1] == nullptr) return false;
	return true;
}

bool Astar::CanOpenUp(Vector2 idx)
{

	if (idx.y - (int)1 == -1) return false;
	if (_vTotalList[((int)idx.x + TILENUMX * (int)idx.y) - TILENUMX] == nullptr) return false;
	return true;
}

bool Astar::CanOpenDown(Vector2 idx)
{

	if (idx.y + (int)1 == TILENUMY) return false;
	if (_vTotalList[((int)idx.x + TILENUMX * (int)idx.y) + TILENUMX] == nullptr) return false;
	return true;
}

bool Astar::SetCost(Tile* node, float cost, Tile* parent)
{
	if (node == nullptr || node->GetAttribute() == "wall" || node->GetIsClose() || node->GetIsOpen()) return false;

	float valH = 0;
	cost += node->GetCostG();
	int x = abs(_endTile->GetIdX() - node->GetIdX());
	int y = abs(_endTile->GetIdY() - node->GetIdY());
	valH = (x + y) * 10;

	if (node->GetCostF() < 0 || node->GetCostG() > cost)
	{
		node->SetCostG(cost);
		node->SetCostH(valH);
		node->SetCostF(cost + valH);
		node->SetParentNode(parent);
	}

	return true;
}

void Astar::AddOpenList(Tile * node)
{
	if (node == nullptr || node->GetAttribute() == "wall") return;

	if (node->GetIsClose()) return;
	if (node->GetIsOpen()) return;


	node->SetIsOpen(true);

	_OpenList.push_back(node);
}

void Astar::AddCloseList(Tile * node)
{

	if (node == NULL) return;
	node->SetIsOpen(false);
	node->SetIsClose(true);

	for (int i = 0; i < _OpenList.size(); i++)
	{
		if (_OpenList[i] == node) {
			_OpenList.erase(_OpenList.begin() + i);
			break;
		}

	}
	_ClosedList.push_back(node);
}

Tile * Astar::GetMinFNode()
{
	float tempTotalCost = FLT_MAX;
	Tile* tempTile = nullptr;

	for (Tile* t : _OpenList)
	{
		if (t->GetCostF() < tempTotalCost)
		{
			tempTotalCost = t->GetCostF();
			tempTile = t;
		}
	}

	return tempTile;
}

void Astar::SetPathcList()
{
	_pathList.clear();
	list<Vector2> path;

	while (_currentTile->GetParentNode() != nullptr)
	{
		_currentTile = _currentTile->GetParentNode();
		path.push_front(_currentTile->GetCenter());
	}
	_pathList = path;
}
