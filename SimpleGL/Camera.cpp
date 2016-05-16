#include "stdafx.h"
#include "Camera.h"

namespace SimpleGL
{
	Camera::Camera()
	{
	}


	Camera::~Camera()
	{
	}

	void Camera::SetProjectionParams(const float zn, const float zf, const float aspect, const float fov)
	{
		m_fNear = zn;
		m_fFar = zf;
		m_fAspect = aspect;
		m_fFov = fov;
	}

	const Matrix4f Camera::ProjMatrixDX11() const
	{
		DirectX::XMMATRIX projectionMatrix = DirectX::XMMatrixPerspectiveFovLH(m_fFov, m_fAspect, m_fNear, m_fFar);
		
		DirectX::XMFLOAT4X4 mat4x4;
		XMStoreFloat4x4(&mat4x4, projectionMatrix);

		Matrix4f resultMat;
		memcpy_s(&resultMat, sizeof(resultMat), &mat4x4, sizeof(mat4x4));

		return resultMat;
	}

}