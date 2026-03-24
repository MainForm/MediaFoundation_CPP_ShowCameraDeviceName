#include <iostream>

// MediaFoundtion 헤더파일
#include <mfapi.h>
#include <mfobjects.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <mferror.h>

using namespace std;

// https://learn.microsoft.com/ko-kr/windows/win32/medfound/audio-video-capture-in-media-foundation
void showDeviceNames(IMFActivate** ppDevices, UINT count)
{
    for (DWORD i = 0; i < count; i++)
    {
        HRESULT hr = S_OK;
        WCHAR* szFriendlyName = NULL;

        // 카메라 이름 정보 도출
        UINT32 cchName;
        hr = ppDevices[i]->GetAllocatedString(
            MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME,
            &szFriendlyName, &cchName);

        if (SUCCEEDED(hr))
        {
            wprintf(L"%d : %s\n", i, szFriendlyName);
        }
        CoTaskMemFree(szFriendlyName);
    }
}

int main(void) {

	// COM 라이브러리 초기화
	CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	// MediaFoundation 라이브러리 초기화
	MFStartup(MF_VERSION, MFSTARTUP_FULL);

    IMFAttributes* pConfig = NULL;
    IMFActivate** ppDevices = NULL;
    UINT count = 0;

    // 카메라 검색 속성을 저장하기 위한 객체 생성
    HRESULT hr = MFCreateAttributes(&pConfig, 1);

    // 카메라 검색 속성 지정
    // 카메라 디바이스를 검색(SOURCE_TYPE_VIDCAP)
    if (SUCCEEDED(hr))
    {
        hr = pConfig->SetGUID(
            MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE,
            MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID
        );
    }

    // 카메라 디바이스 도출
    if (SUCCEEDED(hr))
    {
        hr = MFEnumDeviceSources(pConfig, &ppDevices, &count);
    }

    // 카메라 정보 출력
    showDeviceNames(ppDevices, count);


    // 카메라 정보 객체 해제
    for (UINT i = 0; i < count; i++) {
        ppDevices[i]->Release();
    }
    CoTaskMemFree(ppDevices);

    // 카메라 검색 속성 객체 해제
    pConfig->Release();

	// MediaFoundation 라이브러리 해제
	MFShutdown();
	// COM 라이브러리 해제
	CoUninitialize();

	return 0;
}