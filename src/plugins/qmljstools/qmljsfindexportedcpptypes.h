/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2011 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (info@qt.nokia.com)
**
**
** GNU Lesser General Public License Usage
**
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** Other Usage
**
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
** If you have questions regarding the use of this file, please contact
** Nokia at info@qt.nokia.com.
**
**************************************************************************/

#ifndef QMLJSTOOLS_QMLJSFINDEXPORTEDCPPTYPES_H
#define QMLJSTOOLS_QMLJSFINDEXPORTEDCPPTYPES_H

#include <cplusplus/CppDocument.h>
#include <languageutils/fakemetaobject.h>

#include <QtCore/QCoreApplication>
#include <QtCore/QMap>

namespace QmlJSTools {

class FindExportedCppTypes
{
    Q_DECLARE_TR_FUNCTIONS(FindExportedCppTypes)
public:
    FindExportedCppTypes(const CPlusPlus::Snapshot &snapshot);

    // document must have a valid source and ast for the duration of the call
    void operator()(const CPlusPlus::Document::Ptr &document);

    QList<LanguageUtils::FakeMetaObject::ConstPtr> exportedTypes() const;
    QMap<QString, QString> contextProperties() const;

    static bool maybeExportsTypes(const CPlusPlus::Document::Ptr &document);

private:
    CPlusPlus::Snapshot m_snapshot;
    QList<LanguageUtils::FakeMetaObject::ConstPtr> m_exportedTypes;
    QMap<QString, QString> m_contextProperties;
};

} // namespace QmlJSTools

#endif // QMLJSTOOLS_QMLJSFINDEXPORTEDCPPTYPES_H
