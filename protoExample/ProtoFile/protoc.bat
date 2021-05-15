set compiler=".\protoc\bin\protoc.exe"
set protoFile=service.proto

set outputFolder=..\protoClient\ConsoleApplication1\protoclasses
%compiler% --cpp_out=%outputFolder% %protoFile%

set outputFolder=..\protoServer\src\main\java
%compiler% --java_out=%outputFolder% %protoFile%