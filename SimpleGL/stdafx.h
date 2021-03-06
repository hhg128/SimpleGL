// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
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