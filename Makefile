CXX_LINUX = g++
CXX_WIN = x86_64-w64-mingw32-g++

LDFLAGS =
LDFLAGS_LINUX = $(LDFLAGS) -L/usr/local/lib
LDFLAGS_WIN = $(LDFLAGS) -lmingw32 -mwindows -L3rdparty/chipmunk/install/lib

CXXFLAGS = -O2
CXXFLAGS_LINUX = $(CXXFLAGS)
CXXFLAGS_WIN = $(CXXFLAGS)

SRC_DIR = src
BUILD_DIR = build
SRC = $(wildcard $(SRC_DIR)/*.cpp)

OBJ_LINUX = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o.l, $(SRC))
OBJ_WIN = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o.w, $(SRC))
BIN_NAME = conveyor
TARGET_LINUX = $(BUILD_DIR)/$(BIN_NAME)
TARGET_WIN = $(BUILD_DIR)/$(BIN_NAME).exe

linux: $(BUILD_DIR) $(TARGET_LINUX)
#	tar -cJvf $(BUILD_DIR)/$(BIN_NAME).tar.xz $(TARGET_LINUX)

windows: $(BUILD_DIR) $(TARGET_WIN)
	@cp -v 3rdparty/SDL/install/bin/SDL2.dll $(BUILD_DIR)
	@cp -v /usr/x86_64-w64-mingw32/lib/libwinpthread-1.dll $(BUILD_DIR)
	@zip $(BUILD_DIR)/$(BIN_NAME).zip $(TARGET_WIN) $(BUILD_DIR)/*.dll

all: linux windows
	
win: windows

$(BUILD_DIR):
	@mkdir -vp $@

$(TARGET_LINUX): $(OBJ_LINUX)
	$(CXX_LINUX) $^ -o $@ $(LDFLAGS_LINUX)

$(TARGET_WIN): $(OBJ_WIN)
	$(CXX_WIN) $^ -o $@ $(LDFLAGS_WIN)

$(BUILD_DIR)/%.o.l: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX_LINUX) $(CXXFLAGS_LINUX) -c $< -o $@

$(BUILD_DIR)/%.o.w: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX_WIN) $(CXXFLAGS_WIN) -c $< -o $@



run: $(TARGET_LINUX)
	@./$(TARGET_LINUX)

clean:
	@rm -rvf $(BUILD_DIR)

.PHONY: all clean run linux windows win
