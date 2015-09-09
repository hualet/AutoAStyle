#ifndef AUTOASTYLE_H
#define AUTOASTYLE_H

#include "autoastyle_global.h"

#include <extensionsystem/iplugin.h>

namespace AutoAStyle {
namespace Internal {

class AutoAStylePlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "AutoAStyle.json")

public:
    AutoAStylePlugin();
    ~AutoAStylePlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private slots:
    void documentUpdated();
};

} // namespace Internal
} // namespace AutoAStyle

#endif // AUTOASTYLE_H

