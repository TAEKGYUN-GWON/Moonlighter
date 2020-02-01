#pragma once
#include "singletonBase.h"

#define ZOOM_MIN 0.01f
#define ZOOM_MAX 2.5f

class Camera :public singletonBase<Camera>
{
private:
	D2D1_MATRIX_3X2_F	_matrix;
	//Matrix3x3			_matrix;

	Matrix3x2F			_scaleMatrix;
	//Matrix3x3			_scaleMatrix;
	//Matrix3x3			_rotationMatrix;
	//Matrix3x3			_translationMatrix;
	//Matrix3x3			_originTransMatrix;
	//Matrix3x3			_inverseMatrix;

	Vector2				_scale;
	Vector2				_pos;
	Vector2				_origin;
	Vector2				_startPos;
	Vector2				_endPos;

	Vector2				_shakeUpPos;
	Vector2				_shakeDownPos;

	float				_angle;
	float				_speed;
	float				_lerpCount;
	float				_moveTime;
	float				_prevDistance;
	bool				_isMoving;

public:
	Camera()
	{
		_scaleMatrix = Matrix3x2F::Identity();
		//_scaleMatrix = Matrix3x3::identity;
		//_rotationMatrix = Matrix3x3::identity;
		//_translationMatrix = Matrix3x3::identity;
		//_originTransMatrix = Matrix3x3::identity;
		//_inverseMatrix = Matrix3x3::identity;

		_scale = Vector2(1, 1);
		_pos = Vector2().zero;
		_origin = Vector2().zero;
		_angle = 0.0f;
		_speed = 300.f;
		_lerpCount = 0;
		_isMoving = false;
	};
	~Camera() {};

	HRESULT init();
	void Update();
	//void release();

	void UpdateMatrix();

	void SetScale(Vector2 scale);// { _scale = scale; };
	//void SetAngle(float angle) { _angle = angle; };
	void SetPosition(Vector2 pos, string key);
	void SetPos(Vector2 pos) { _pos = pos; }
	void MoveTo(Vector2 endPos, float time, bool isCenter = true);

	Vector2 GetPosition() { return _pos; }
	Vector2 GetScale() { return _scale; }
	bool IsMoving();

	D2D1_MATRIX_3X2_F GetMatrix() { return _matrix; }
	//D2D1_MATRIX_3X2_F GetMatrix() { return _matrix.To_D2D1_Matrix_3x2_F(); }
	Matrix3x2F GetScaleMatrix() { return _scaleMatrix; }
	//Matrix3x3 GetScaleMatrix() { return _scaleMatrix; }

	Vector2 GetWorldToCamera(Vector2 pos);
	Vector2 GetCameraToWorld(Vector2 pos);
};

