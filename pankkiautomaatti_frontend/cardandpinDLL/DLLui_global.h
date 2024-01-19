#ifndef DLLUI_GLOBAL_H
#define DLLUI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DLLUI_LIBRARY)
#  define DLLUI_EXPORT Q_DECL_EXPORT
#else
#  define DLLUI_EXPORT Q_DECL_IMPORT
#endif

#endif // DLLUI_GLOBAL_H
