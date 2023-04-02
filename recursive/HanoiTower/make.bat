set OBJS=RecursiveSquares.cpp SDL_utils.cpp
set OBJ_NAME=main.exe
set COMPILER_FLAGS=-std=c++11
set LINKER_FLAGS=-lmingw32 -lSDL2main -lSDL2
set INCLUDE_DIR=-IG:\SDL2-2.0.14\x86_64-w64-mingw32\include\SDL2
set LIB_DIR=-LG:\SDL2-2.0.14\x86_64-w64-mingw32\lib

g++ %COMPILER_FLAGS% %INCLUDE_DIR% %LIB_DIR% %OBJS% %LINKER_FLAGS% -o %OBJ_NAME%
