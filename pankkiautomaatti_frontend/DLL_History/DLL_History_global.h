#ifndef DLL_HISTORY_GLOBAL_H
#define DLL_HISTORY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DLL_HISTORY_LIBRARY)
#  define DLL_HISTORY_EXPORT Q_DECL_EXPORT
#else
#  define DLL_HISTORY_EXPORT Q_DECL_IMPORT
#endif

#endif // DLL_HISTORY_GLOBAL_H
