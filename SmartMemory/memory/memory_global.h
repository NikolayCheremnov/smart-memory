#ifndef MEMORY_GLOBAL_H
#define MEMORY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MEMORY_LIBRARY)
#  define MEMORY_EXPORT Q_DECL_EXPORT
#else
#  define MEMORY_EXPORT Q_DECL_IMPORT
#endif

#endif // MEMORY_GLOBAL_H
