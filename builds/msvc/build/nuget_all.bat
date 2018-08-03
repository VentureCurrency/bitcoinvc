@ECHO OFF
ECHO Downloading bitcoinvc vs2017 dependencies from NuGet
CALL nuget.exe install ..\vs2017\bitcoinvc\packages.config
CALL nuget.exe install ..\vs2017\bitcoinvc-examples\packages.config
CALL nuget.exe install ..\vs2017\bitcoinvc-test\packages.config
ECHO.
ECHO Downloading bitcoinvc vs2015 dependencies from NuGet
CALL nuget.exe install ..\vs2015\bitcoinvc\packages.config
CALL nuget.exe install ..\vs2015\bitcoinvc-examples\packages.config
CALL nuget.exe install ..\vs2015\bitcoinvc-test\packages.config
ECHO.
ECHO Downloading bitcoinvc vs2013 dependencies from NuGet
CALL nuget.exe install ..\vs2013\bitcoinvc\packages.config
CALL nuget.exe install ..\vs2013\bitcoinvc-examples\packages.config
CALL nuget.exe install ..\vs2013\bitcoinvc-test\packages.config
