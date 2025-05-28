CXX_LINUX = g++
CXX_WIN = x86_64-w64-mingw32-g++

LDFLAGS = -lm
LDFLAGS_LINUX = $(LDFLAGS) -lSDL2 -L/usr/local/lib
LDFLAGS_WIN = $(LDFLAGS) -L3rdparty/SDL/install/lib -lmingw32 -lSDL2main -lSDL2 -mwindows -lwinpthread

CXXFLAGS = -O2 -Isrc/entities -Isrc/use_cases -Isrc/interfaces -Isrc/frameworks
CXXFLAGS_LINUX = $(CXXFLAGS) -I/usr/include/SDL2 -D_REENTRANT
CXXFLAGS_WIN = $(CXXFLAGS) -I3rdparty/SDL/install/include -Dmain=SDL_main

SRC_DIR = src
BUILD_DIR = build
SRC = $(shell find $(SRC_DIR) -name '*.cpp')

OBJ_LINUX = $(patsubst %.cpp, $(BUILD_DIR)/%.o.l, $(SRC))
OBJ_WIN = $(patsubst %.cpp, $(BUILD_DIR)/%.o.w, $(SRC))
BIN_NAME = conveyor
TARGET_LINUX = $(BUILD_DIR)/$(BIN_NAME)
TARGET_WIN = $(BUILD_DIR)/$(BIN_NAME).exe

linux: $(BUILD_DIR) $(TARGET_LINUX)
	@echo -e "\n\e[92mTarget $(TARGET_LINUX) built!\e[0m"

windows: $(BUILD_DIR) $(TARGET_WIN)
	@cp -v 3rdparty/SDL/install/bin/SDL2.dll $(BUILD_DIR)
	@bash -c "if [[ -f /usr/x86_64-w64-mingw32/lib/libwinpthread-1.dll ]]; then cp -v /usr/x86_64-w64-mingw32/lib/libwinpthread-1.dll $(BUILD_DIR); else cp -v /usr/x86_64-w64-mingw32/bin/libwinpthread-1.dll $(BUILD_DIR); fi"
	@cp -v /usr/lib/gcc/x86_64-w64-mingw32/12-win32/libgcc_s_seh-1.dll $(BUILD_DIR)
	@cp -v /usr/lib/gcc/x86_64-w64-mingw32/12-win32/libstdc++-6.dll $(BUILD_DIR)
	@zip $(BUILD_DIR)/$(BIN_NAME).zip $(TARGET_WIN) $(BUILD_DIR)/*.dll

all: linux windows
	
win: windows

$(BUILD_DIR):
	@mkdir -vp $@

$(TARGET_LINUX): $(OBJ_LINUX)
	$(CXX_LINUX) $^ -o $@ $(LDFLAGS_LINUX)

$(TARGET_WIN): $(OBJ_WIN)
	$(CXX_WIN) $^ -o $@ $(LDFLAGS_WIN)

$(BUILD_DIR)/%.o.l: %.cpp
	@mkdir -pv $(dir $@)
	$(CXX_LINUX) $(CXXFLAGS_LINUX) -c $< -o $@

$(BUILD_DIR)/%.o.w: %.cpp
	@mkdir -pv $(dir $@)
	$(CXX_WIN) $(CXXFLAGS_WIN) -c $< -o $@



run: $(TARGET_LINUX)
	@./$(TARGET_LINUX)

clean:
	@rm -rvf $(BUILD_DIR)

.PHONY: all clean run linux windows win
