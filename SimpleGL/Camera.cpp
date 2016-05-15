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

	void Camera::SetProjectionParams(float zn, float zf, float aspect, float fov)
	{
		m_fNear = zn;
		m_fFar = zf;
		m_fAspect = aspect;
		m_fFov = fov;
	}

	const DirectX::XMMATRIX Camera::ProjMatrixDX11() const
	{
		DirectX::XMMATRIX projectionMatrix = DirectX::XMMatrixPerspectiveFovLH(m_fFov, m_fAspect, m_fNear, m_fFar);

		return projectionMatrix;
	}

}