# Add more folders to ship with the application, here
folder_01.source = qml/NetworkSim
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    model.cpp \
    node.cpp \
    packet.cpp \
    link.cpp \
    graph.cpp \
    floodingRT.cpp

PRECOMPILED_HEADER += stdafx.h

# Installation path
# target.path =

OTHER_FILES += \
    qml/NetworkSim/Menu.qml \
    qml/NetworkSim/ActionBar.qml \
    qml/NetworkSim/Packet.qml \
    qml/NetworkSim/RoutingTable.qml \
    qml/NetworkSim/PressHoldNodeMenu.qml \
    qml/NetworkSim/Nodes.qml \
    android/AndroidManifest.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

HEADERS += \
    model.h \
    node.h \
    packet.h \
    link.h \
    stdafx.h \
    graph.h \
    floodingRT.h

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

RESOURCES += \
    resources.qrc

