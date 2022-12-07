// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
#define _CRT_SECURE_NO_WARNINGS
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

//C++헤더 파일
#include <iostream>

//STL
#include <vector>

using namespace std;

//A2W 아스키 ==> 유니코드 변환
#include <comdef.h>
#include <CRTDBG.h>
#include <atlconv.h>

#include "wnd3DGameEngine_001.h"
#include "Util.h"
#include "Vector2D.h"
#include "Resource.h"
#include "wndGdi.h"
#include "Vertex.h"
#include "Matrix44.h"
#include "Triangle.h"
#include "wndMainProc.h"
#include "wndAbout.h"
#include "GameEngineRun.h"