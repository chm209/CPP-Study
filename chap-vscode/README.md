### chap-vscode

챕터13 부터 vscode를 사용하여 공부한다.

폴더 구조는 이하와 같다.

```
chap-vscode
    ㄴ chap13
        ㄴ chap13.md <- 내용정리
		ㄴ ex01
            ㄴ ex01.cpp
        ㄴ ex02
		    ㄴ ex02.cpp
        ㄴ chap13-problems.cpp
        ...
    ㄴ chap14
        ㄴ chap14.md <- 내용정리
        ㄴ ex01
            ㄴ ex01.cpp
        ㄴ ex02
		    ㄴ ex02.cpp
        ㄴ chap14-problems.cpp
    ...
```

---

### Visual Studio code 개발환경

1. 터미널에서 clang, lldb를 먼저 설치할것
2. C/C++ 확장, Code Runner 확장 설치
3. 설정에서 Code runner의 "Run in Terminal" 설정 체크
4. code runner.executorMap을 아래와 같이 수정
> "cpp": "cd $dir && clang++ -std=c++20 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"

> 기본값은 g++ 이면서 std 버전이 들어가 있지 않기 때문에 std=c++17 (버전) 옵션을 넣어줘야 한다.

5. 적당히 c++ 폴더를 만들어서 디버깅을 누르고 C++(GDB/LLDB)를 선택, 빌드 태스크는 C/C++: clang++ build active file (compiler: /usr/bin/clang++) 을 선택
6. task.json 파일이 생성된다. 중간에 args 부분에 "-std=c++20" 를 넣어줘야함

``` json
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "C/C++: clang++ 활성 파일 빌드",
			"command": "/usr/bin/clang++",
			"args": [
				"-std=c++20",
				"-fdiagnostics-color=always",
				"-g",
				${file},
				"-o",
				"${fileDirname}/${fileBasenameNoExtension}"
			],
			"options": {
				"cwd": "${fileDirname}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			},
			"detail": "컴파일러: /usr/bin/clang++"
		}
	]
}
```
7. launch.json 파일이 생성되는데 딱히 수정한 건 없다. 다만, launch.json의 preLaunchTask와 tasks.json에서 task의 label이 일치해야 한다

``` json
{
    // IntelliSense를 사용하여 가능한 특성에 대해 알아보세요.
    // 기존 특성에 대한 설명을 보려면 가리킵니다.
    // 자세한 내용을 보려면 https://go.microsoft.com/fwlink/?linkid=830387을(를) 방문하세요.
    "version": "0.2.0",
    "configurations": [
        {
            "name": "clang++ - 활성 파일 빌드 및 디버그",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb",
            "preLaunchTask": "C/C++: clang++ 활성 파일 빌드"
        }
    ]
}
```
---

### ARM Mac의 경우
1. 위와 같이 설정한후 CodeLLDB 확장을 추가로 설치한다.
2. launch.json 파일의 type을 아래와 같이 lldb로 수정해준다. (원래는 cppdbg)

``` json
{
    // IntelliSense를 사용하여 가능한 특성에 대해 알아보세요.
    // 기존 특성에 대한 설명을 보려면 가리킵니다.
    // 자세한 내용을 보려면 https://go.microsoft.com/fwlink/?linkid=830387을(를) 방문하세요.
    "version": "0.2.0",
    "configurations": [
        {
            "name": "clang++ - 활성 파일 빌드 및 디버그",
            "type": "lldb",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb",
            "preLaunchTask": "C/C++: clang++ 활성 파일 빌드"
        }
    ]
}
```

---

### CPP 파일이 여러개일때

1. setting.json에서 "code-ruuner.executorMap"에서 처음에 수정했던 -std=c++20 $fileName 의 $fileName을 *.cpp로 바꿔준다.

> "cpp": "cd $dir && clang++ -std=c++20 *.cpp -o $fileNameWithoutExt && $dir$fileNameWithoutExt"

2. tasks.json의 args에서 ${file}을 ${fileDirname}/**.cpp로 수정해준다. hpp도 추가해준다.

``` json
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "C/C++: clang++ 활성 파일 빌드",
			"command": "/usr/bin/clang++",
			"args": [
				"-std=c++20",
				"-fdiagnostics-color=always",
				"-g",
				"${fileDirname}/**.cpp",
				"${fileDirname}/**.hpp",
				"-o",
				"${fileDirname}/${fileBasenameNoExtension}"
			],
			"options": {
				"cwd": "${fileDirname}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			},
			"detail": "컴파일러: /usr/bin/clang++"
		}
	]
}
```

---

VS Code는 기본적으로 개별 파일 컴파일이지만 설정을 통해 여러 파일을 동시에 컴파일 할 수 있게 했는데

특정 파일만 제외시키는 방법은 없는듯하다.

좀더 찾아봐야할듯 하다.