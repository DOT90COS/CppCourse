@echo OFF
REM dont remove this
"C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe" /nologo .\Types.sln -m /t:Rebuild /p:Configuration=Debug /p:Platform=x64
"C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe" /nologo .\Types.sln -m /t:Rebuild /p:Configuration=Release /p:Platform=x64
"C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe" /nologo .\Types.sln -m /t:Rebuild /p:Configuration=Debug /p:Platform=x86
"C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe" /nologo .\Types.sln -m /t:Rebuild /p:Configuration=Release /p:Platform=x86