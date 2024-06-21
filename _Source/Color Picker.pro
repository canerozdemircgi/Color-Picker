TARGET = Color Picker
TEMPLATE = app
QT += core gui widgets

DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += ltcg
QMAKE_CXXFLAGS += -std=c++1z

QMAKE_CFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_LFLAGS_RELEASE -= -O2
QMAKE_CFLAGS_RELEASE += -Ofast -fomit-frame-pointer -frename-registers -march=nocona -mtune=generic
QMAKE_CXXFLAGS_RELEASE += -Ofast -fomit-frame-pointer -frename-registers -march=nocona -mtune=generic
QMAKE_LFLAGS_RELEASE += -Ofast -fomit-frame-pointer -frename-registers -march=nocona -mtune=generic

HEADERS = $$files(*.h, true)
SOURCES = $$files(*.cpp, true)
RESOURCES = $$files(*.qrc, true)
RC_FILE = $$files(*.rc, true)

INCLUDEPATH += C:/msys64/mingw64/include/opencv4
LIBS += C:/msys64/mingw64/lib/libopencv_core.dll.a
LIBS += C:/msys64/mingw64/lib/libopencv_imgproc.dll.a