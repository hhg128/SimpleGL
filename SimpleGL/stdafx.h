// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

#include <locale>         // std::wstring_convert
#include <codecvt>        // std::codecvt_utf8
#include <cstdint>        // std::uint_least32_t

// DirectX includes
#include <d3d11_1.h>
#include <DXGI.h>
#include <d3dCompiler.h>
#include <DirectXColors.h>
#include <DirectXMath.h>
#include <wrl.h>

// My includes
#include "Vector2f.h"
#include "Vector3f.h"
#include "Vector4f.h"

#include "Matrix3f.h"
#include "Matrix4f.h"