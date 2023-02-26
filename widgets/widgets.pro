QT += widgets

TEMPLATE = lib
DEFINES += WIDGETS_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cvpixmapitem.cpp \
    labelitem.cpp \
    labelscene.cpp \
    labelview.cpp

HEADERS += \
    cvpixmapitem.h \
    labelitem.h \
    labelscene.h \
    labelview.h \
    widgets_global.h

# 3rdparty
{
    # opencv
    include($$PWD/../3rdparty/opencv/opencv.pri)
}

# 设置输出文件名
TARGET = widgets

# 设置编译输出目录
_BUILD_DIR = $$(BUILD_DIR)

unix {
    target.path = /usr/lib

    # 设置输出目录
    isEmpty(_BUILD_DIR){
        DESTDIR = $$PWD/../build/linux
    } else {
        DESTDIR = $$(BUILD_DIR)/linux
    }

} # unix
!isEmpty(target.path): INSTALLS += target


win32 {
win32-msvc {

    # 设置输出目录
    isEmpty(_BUILD_DIR){
        DESTDIR = $$PWD/../build/windows
    } else {
        DESTDIR = $$(BUILD_DIR)/windows
    }

    CONFIG(release, debug|release) {
    }

    CONFIG(debug, debug|release) {
        TARGET = $$join(TARGET,,,d)
    }

} # msvc
} # win

message('$$TARGET build on $$DESTDIR')
