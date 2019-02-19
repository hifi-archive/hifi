﻿//
//  AvatarDoctor.h
//
//
//  Created by Thijs Wenker on 02/12/2019.
//  Copyright 2019 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#pragma once
#ifndef hifi_AvatarDoctor_h
#define hifi_AvatarDoctor_h

#include <QUrl>
#include <QVector>
#include <QVariantMap>

struct AvatarDiagnosticResult {
    QString message;
    QUrl url;
};
Q_DECLARE_METATYPE(AvatarDiagnosticResult)
Q_DECLARE_METATYPE(QVector<AvatarDiagnosticResult>)

class AvatarDoctor : public QObject {
    Q_OBJECT
public:
    AvatarDoctor(QUrl avatarFSTFileUrl);

    Q_INVOKABLE void startDiagnosing();

    Q_INVOKABLE QVariantList getErrors() const;

signals:
    void complete(QVariantList errors);

private:
    QUrl _avatarFSTFileUrl;
    QVector<AvatarDiagnosticResult> _errors;

    int _externalTextureCount = 0;
    int _checkedTextureCount = 0;
    int _missingTextureCount = 0;
    int _unsupportedTextureCount = 0;

    bool _isDiagnosing = false;
};

#endif  // hifi_AvatarDoctor_h
