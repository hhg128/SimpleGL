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

	const Matrix4f Camera::ProjMatrix() const
	{
		DirectX::XMMATRIX projectionMatrix = DirectX::XMMatrixPerspectiveFovLH(m_fFov, m_fAspect, m_fNear, m_fFar);

		return Matrix4f();
	}

}