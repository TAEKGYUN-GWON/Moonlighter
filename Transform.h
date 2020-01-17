#pragma once
#include "Component.h"
#include"Matrix3x3.h"
class Matrix3x3;

class Transform : public Component
{
private:
	
	float _rotate;
	RECT _rc;

	Matrix3x3 scaleMatrix;
	Matrix3x3 rotateMatrix;
	Matrix3x3 translateMatrix;
	Matrix3x3 localToWorldMatrix;

	//��Ʈ���� ������Ʈ
	void UpdateMatrix();

public:
	typedef Component super;
	Vector2 pos;
	Vector2 bottomPos;
	Vector2 scale;
	Transform();

	virtual void Init() override;

	virtual void Update() override;

	//Vector2 Ÿ�� ��ǥ ��������
	inline Vector2 GetPos() { return pos; }

	//������ǥ ��������
	Vector2 GetWorldPosition();

	//Vector2 Ÿ�� ������ ��������
	inline Vector2 GetScale() { return scale; }


	//��׸� ������ ȸ���� ��������
	inline float GetRotateDegree() { return _rotate * RadToDeg; }

	//���� ������ ȸ���� ��������
	inline float GetRotateRadian() { return _rotate; }

	//Vector2 Ÿ������ ��ǥ �����ϱ�
	inline void SetPos(Vector2 pos) { this->pos = pos; }

	//float Ÿ������ ��ǥ �����ϱ�
	inline void SetPos(float x, float y) { pos = Vector2(x, y); }

	//������ǥ ����
	void SetWorldPos(Vector2 pos);

	//Vector2 Ÿ������ ������ �����ϱ�
	inline void SetScale(Vector2 scale) { this->scale = scale; }

	//float Ÿ������ ������ �����ϱ�
	inline void SetScale(float w, float h) { scale = Vector2(w, h); }

	//���Ȱ����� ȸ���� ����
	inline void SetRotateToRadian(float rotate) { _rotate = rotate; }

	//��׸� ������ ȸ���� ����
	inline void SetRotateToDegree(float rotate) { _rotate = rotate * RadToDeg; }

	inline RECT GetRect() { return _rc; }

	inline void SetRect(RECT rc) { _rc = rc; }

	//3x3 ��Ʈ������ ���� �� ���� ��Ʈ���� ��������
	Matrix3x3 GetLocalToWorldMatrix() { return localToWorldMatrix; };

	//D2D 3x2 ��Ʈ������ ���� �� ���� ��Ʈ���� ��������
	D2D_MATRIX_3X2_F GetLocalToWorldMatrixTo_D2D_MATRIX() { return localToWorldMatrix.To_D2D1_Matrix_3x2_F(); };

	void SetRect();
};

