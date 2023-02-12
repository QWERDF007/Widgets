QT += widgets

TEMPLATE = lib
DEFINES += WIDGETS_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cvgraphicsview.cpp

HEADERS += \
    cvgraphicsview.h \
    widgets_global.h


# 设置输出文件名
TARGET = widgets

# Default rules for deployment.
unix {
    target.path = /usr/lib
    # 设置输出目录
    DESTDIR = $$PWD/../build/linux
}
!isEmpty(target.path): INSTALLS += target


win32 {
win32-msvc {

    # 设置输出目录
    DESTDIR = $$PWD/../build/windows

    CONFIG(release, debug|release) {
    }

    CONFIG(debug, debug|release) {
        TARGET = $$join(TARGET,,,d)
    }

} # msvc
} # win
