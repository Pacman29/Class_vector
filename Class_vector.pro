TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11
QMAKE_CFLAGS += -std=c++11

SOURCES += \
    main.cpp \
    _Geometric_vector.cpp \
    _iterator_vector.cpp

HEADERS += \
    _iterator_vector_base.h \
    _iteration_er.h \
    _geometric_vector.h \
    Geometric_vector.h \
    _error.h \
    _base_g_vector.h \
    _Iterator.h \
    iterator_random.h

