/*
 * This file is part of harbour-parkingchaos.
 * SPDX-FileCopyrightText: 2020-2022  Mirian Margiani
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <QtQuick>
#include <auroraapp.h>
#include "requires_defines.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(Aurora::Application::application(argc, argv));
    app->setOrganizationName("moe.smoothie");
    app->setApplicationName("parkingchaos");

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    view->rootContext()->setContextProperty("APP_VERSION", QString(APP_VERSION));
    view->rootContext()->setContextProperty("APP_RELEASE", QString(APP_RELEASE));
    view->rootContext()->setContextProperty("DATA_DIRECTORY", Aurora::Application::pathTo("data"));

    view->engine()->addImportPath(Aurora::Application::pathTo("qml/modules").toString());
    view->setSource(Aurora::Application::pathToMainQml());
    view->show();
    
    return app->exec();
}
