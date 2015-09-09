#include "autoastyleplugin.h"
#include "autoastyleconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <texteditor/texteditor.h>
#include <texteditor/textdocument.h>
#include <coreplugin/coreconstants.h>
#include <cpptools/cppmodelmanager.h>
#include <utils/fileutils.h>

#include <QString>
#include <QProcess>
#include <QDebug>

#include <QtPlugin>

using namespace AutoAStyle::Internal;

AutoAStylePlugin::AutoAStylePlugin()


{
    // Create your members
}

AutoAStylePlugin::~AutoAStylePlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool AutoAStylePlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    CppTools::CppModelManager *modelManager = CppTools::CppModelManager::instance();
    connect(modelManager, &CppTools::CppModelManager::documentUpdated, this, &AutoAStylePlugin::documentUpdated);

    return true;
}

void AutoAStylePlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag AutoAStylePlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

void AutoAStylePlugin::documentUpdated()
{
    TextEditor::TextEditorWidget *widget = TextEditor::TextEditorWidget::currentTextEditorWidget();
    Utils::FileName fileName = widget->textDocument()->filePath();

    QProcess::startDetached(QString::fromLatin1("astyle %1").arg(fileName.toString()));
}
