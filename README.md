# MediaFoundation 예제

이 저장소는 `Media Foundation`을 이용한 간단한 예제를 보관하기 위한 Repo입니다.  
예제는 Windows에서 미디어(카메라, 오디오 등) 장치를 열고 다루는 방법을 보여주며, 주로 카메라 장치 이름을 나열하거나 캡처하는 기본 흐름을 설명합니다.

## 주요 내용
- `main.cpp`에 포함된 예제 코드(카메라 장치 열기/열거 등)
- Media Foundation API 사용 예시 (`mfapi`, `mfreadwrite` 등)

## 개발 환경 (권장)
- 운영체제: Windows 10 또는 Windows 11 권장
- IDE: `Visual Studio 2019` 또는 `Visual Studio 2022`
- 워크로드: `Desktop development with C++`
- Windows SDK: Windows 10 SDK (예: 10.0.19041.0 이상)
- C++ 표준: `C++17` 권장
- 플랫폼: `x86` 또는 `x64` (빌드 대상과 카메라 드라이버 호환성 확인)

프로젝트를 열려면 `Visual Studio`에서 `MediaFoundationDemo` 프로젝트(또는 솔루션)를 열고 빌드하면 됩니다.

## 빌드 및 실행 방법
1. `Visual Studio`에서 `MediaFoundationDemo.vcxproj`를 엽니다.
2. 솔루션 구성(예: `Debug` / `Release`)과 플랫폼(예: `x64`)을 선택합니다.
3. 빌드: `빌드 > 솔루션 빌드` 또는 `__Build > Build Solution__`
4. 실행: 디버그/릴리스 실행 시 카메라가 연결되어 있어야 정상 동작합니다.

## 필요 라이브러리 및 헤더
프로젝트는 `Windows SDK`의 Media Foundation 헤더/라이브러리를 사용합니다. 프로젝트 설정의 링커 추가 종속성에 아래 항목들을 추가하세요(보통 SDK가 자동으로 연결하지만, 수동으로 지정해야 하는 경우):

- 헤더(인클루드):
  - `#include <mfapi.h>`
  - `#include <mfidl.h>`
  - `#include <mfreadwrite.h>`
  - `#include <Mfobjects.h>` (필요한 경우)

- 링커(Additional Dependencies):
  - `mfplat.lib`
  - `mfreadwrite.lib`
  - `mfuuid.lib`
  - `propsys.lib` (프로퍼티 관련 사용 시)
  - `ole32.lib` (COM 초기화/해제 관련)

참고: `Windows SDK`가 설치되어 있고 프로젝트의 플랫폼/도구집합이 올바르게 설정되어 있다면 대부분의 라이브러리는 자동으로 참조됩니다.

## 권장 설정 및 권한
- 프로그램이 카메라에 접근하려면 사용자 계정과 드라이버 권한이 필요합니다. 필요 시 관리자 권한으로 실행해 보세요.
- UWP가 아닌 데스크톱 앱에서 카메라 접근 시 운영체제 설정에서 카메라 접근 권한을 허용해야 할 수 있습니다.

## 문제 해결
- 빌드 시 헤더를 찾지 못할 경우: `Visual Studio Installer`에서 `Windows 10 SDK`와 `Desktop development with C++`가 설치되어 있는지 확인하세요.
- 링크 오류(심볼 누락) 발생 시: 프로젝트의 `링커 > 입력 > Additional Dependencies`에 위의 라이브러리들을 추가하거나, 플랫폼이 SDK 경로와 일치하는지 확인하세요.
- 카메라가 인식되지 않으면 다른 앱(예: 카메라 앱)에서 장치가 사용 중인지 확인하고, 드라이버가 최신인지 확인하세요.

---
간단한 예제 설명과 빌드/실행에 필요한 최소 정보를 정리했습니다. 프로젝트 코드(`main.cpp`)에 특화된 추가 안내가 필요하면 해당 파일의 내용을 보여주시면 README를 더 구체적으로 다듬어 드리겠습니다.