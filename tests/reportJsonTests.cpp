/* Copyright (c) 2026, Sascha Willems
 *
 * SPDX-License-Identifier: GPL-3.0-only
 *
 */

#include "../reportJson.h"

#include <QJsonDocument>

#include <cstdlib>
#include <iostream>
#include <limits>

static void check(bool condition, const char* message)
{
    if (!condition) {
        std::cerr << message << '\n';
        std::exit(EXIT_FAILURE);
    }
}

int main()
{
    const qulonglong unsignedValues[] = {
        0ULL, 9007199254740991ULL, 9007199254740992ULL,
        9007199254740993ULL, 9223372036854775807ULL,
        9223372036854775808ULL, 18446744073709551615ULL
    };
    for (qulonglong value : unsignedValues) {
        const QJsonValue json = reportJsonValue(QVariant::fromValue(value));
        check(json.isString() && json.toString() == QString::number(value), "unsigned 64-bit value lost precision");
    }

    const unsigned long nativeValue = std::numeric_limits<unsigned long>::max();
    const QJsonValue nativeJson = reportJsonValue(QVariant::fromValue(nativeValue));
    if (sizeof(unsigned long) == sizeof(quint64)) {
        check(nativeJson.isString() && nativeJson.toString() == QString::number(nativeValue), "64-bit unsigned long lost precision");
    } else {
        check(nativeJson.isDouble() && nativeJson.toInteger() == nativeValue, "32-bit unsigned long changed type or value");
    }

    const qlonglong signedValue = std::numeric_limits<qlonglong>::max();
    const QVariantMap source {
        { "signed", QVariant::fromValue(signedValue) },
        { "uint32", QVariant::fromValue(std::numeric_limits<unsigned int>::max()) },
        { "boolean", true },
        { "float", 1.5 },
        { "hex", "0xffffffffffffffff" },
        { "nested", QVariantList {
            QVariant::fromValue(std::numeric_limits<qulonglong>::max()),
            QVariantMap { { "value", QVariant::fromValue(9223372036854775808ULL) } },
            QVariantList { 1, 2, 3 }
        } }
    };
    const QJsonObject result = reportJsonObject(source);
    check(result["signed"].isDouble() && result["signed"].toInteger() == signedValue, "signed 64-bit value changed");
    check(result["uint32"].isDouble() && result["uint32"].toInteger() == 4294967295LL, "32-bit unsigned value changed");
    check(result["boolean"].isBool() && result["boolean"].toBool(), "boolean changed");
    check(result["float"].isDouble() && result["float"].toDouble() == 1.5, "float changed");
    check(result["hex"].toString() == "0xffffffffffffffff", "hex string changed");
    const QJsonArray nested = result["nested"].toArray();
    check(nested[0].toString() == "18446744073709551615", "array value lost precision");
    check(nested[1].toObject()["value"].toString() == "9223372036854775808", "nested map value lost precision");
    check(nested[2].toArray()[0].isDouble() && nested[2].toArray()[0].toInt() == 1, "ordinary array value changed");
    const QJsonObject roundTrip = QJsonDocument::fromJson(QJsonDocument(result).toJson()).object();
    check(roundTrip["nested"].toArray()[0].toString() == "18446744073709551615", "JSON round trip lost precision");
    return EXIT_SUCCESS;
}
