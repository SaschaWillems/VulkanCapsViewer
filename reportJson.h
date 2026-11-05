/* Copyright (c) 2026, Sascha Willems
 *
 * SPDX-License-Identifier: GPL-3.0-only
 *
 */

#ifndef REPORTJSON_H
#define REPORTJSON_H

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QMetaType>
#include <QVariant>

inline QJsonValue reportJsonValue(const QVariant& value);

inline QJsonObject reportJsonObject(const QVariantMap& values)
{
    QJsonObject result;
    for (auto it = values.cbegin(); it != values.cend(); ++it) {
        result.insert(it.key(), reportJsonValue(it.value()));
    }
    return result;
}

inline QJsonArray reportJsonArray(const QVariantList& values)
{
    QJsonArray result;
    for (const QVariant& value : values) {
        result.append(reportJsonValue(value));
    }
    return result;
}

inline QJsonValue reportJsonValue(const QVariant& value)
{
    const QMetaType type = value.metaType();
    // Due to JSON limitations, we store large values as string
    if (type.id() == QMetaType::ULongLong || (type.id() == QMetaType::ULong && type.sizeOf() == sizeof(quint64))) {
        return value.toString();
    }
    if (type.id() == QMetaType::QVariantMap) {
        return reportJsonObject(value.toMap());
    }
    if (type.id() == QMetaType::QVariantList) {
        return reportJsonArray(value.toList());
    }
    return QJsonValue::fromVariant(value);
}

#endif // REPORTJSON_H
