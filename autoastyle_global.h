#ifndef AUTOASTYLE_GLOBAL_H
#define AUTOASTYLE_GLOBAL_H

#include <QtGlobal>

#if defined(AUTOASTYLE_LIBRARY)
#  define AUTOASTYLESHARED_EXPORT Q_DECL_EXPORT
#else
#  define AUTOASTYLESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // AUTOASTYLE_GLOBAL_H

