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
    floodingRT.cpp \
    routingtable.cpp \
    algorithm_interface.cpp \
    dvrRT.cpp \
    lsrt.cpp \
    listviewRT.cpp \
    dynamiclist_xmlparser_itemsdata.cpp

PRECOMPILED_HEADER += stdafx.h

# Installation path
# target.path =

OTHER_FILES += \
    qml/NetworkSim/ActionBar.qml \
    qml/NetworkSim/Packet.qml \
    qml/NetworkSim/RoutingTable.qml \
    qml/NetworkSim/PressHoldNodeMenu.qml \
    qml/NetworkSim/Nodes.qml \
    android/AndroidManifest.xml \
    qml/NetworkSim/FloodingRTItem.qml \
    qml/NetworkSim/Menu1.qml \
    XMLlistingItem.qml \
    qml/NetworkSim/DVRroutingTable.qml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

HEADERS += \
    model.h \
    node.h \
    packet.h \
    link.h \
    stdafx.h \
    graph.h \
    floodingRT.h \
    routingtable.h\
    algorithm_interface.h\
    dvrRT.h \
    lsrt.h \
    listviewRT.h \
    dynamiclist_xmlparser_itemsdata.h

# Please do not modify the following two lines. Required for deployment.
include(qtquick2controlsapplicationviewer/qtquick2controlsapplicationviewer.pri)
qtcAddDeployment()

RESOURCES += \
    resources.qrc

