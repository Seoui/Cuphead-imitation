# Cuphead-imitation
DirectX 게임 포트폴리오입니다.  

유투브 주소: https://www.youtube.com/watch?v=5m51MYeBb68  

Cuphead의 Cagney Carnation 씬을 모작하였습니다  



게임실행을 위해 몇 가지 작업이 필요합니다  

1. DirectX SDK 설치
https://www.microsoft.com/en-us/download/details.aspx?id=6812  


Visual Studio 2017에서  

2. 프로젝트의 속성 -> VC++ 디렉터리 -> 포함 디렉터리에

    2-1. (설치한 DirectX SDK 디렉터리 주소)/(Include 디렉터리 주소)      =>  추가

    2-2. (Cuphead 프로젝트 주소)/(_Libraries 디렉터리 주소)        => 추가


3. 프로젝트의 속성 -> VC++ 디렉터리 -> 포함 라이브러리에  

    3-1. (설치한 DirectX SDK 디렉터리 주소)/Lib/(x86 디렉터리 주소)      => 추가 

    3-2. (Cuphead 프로젝트 주소)/(_Libraries 디렉터리 주소)       =>추가

