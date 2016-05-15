#pragma once

namespace SimpleGL
{
	class Camera
	{
	public:
		Camera();
		virtual ~Camera();

		const Vector3f& GetPosition() { 
			return m_vPosition;
		}

		const Vector3f& GetRotation() {
			return m_vRotation;
		}

		void SetProjectionParams(float zn, float zf, float aspect, float fov);

		const DirectX::XMMATRIX ProjMatrixDX11() const;

	private:
		Vector3f m_vPosition;
		Vector3f m_vRotation;

		float m_fNear;
		float m_fFar;
		float m_fAspect;
		float m_fFov;

		float m_fWidth;
		float m_fHeight;
	};
}
