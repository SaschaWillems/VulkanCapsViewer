/* Copyright (c) 2026, Sascha Willems
 *
 * SPDX-License-Identifier: GPL-3.0-only
 *
 */

#include "../vulkanDeviceInfo.h"

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
    VulkanDeviceInfo device{};
    const qulonglong max = (std::numeric_limits<qulonglong>::max)();
    device.core11Properties["maxMemoryAllocationSize"] = QString::number(max);
    device.core12Properties["maxTimelineSemaphoreValueDifference"] = QString::number(max);
    device.core13Properties["storageTexelBufferOffsetAlignmentBytes"] = QVariant::fromValue(max);
    device.core13Properties["uniformTexelBufferOffsetAlignmentBytes"] = QVariant::fromValue(max);
    device.core13Properties["maxBufferSize"] = QString::number(max);
    device.core14Properties["ordinaryValue"] = 42u;
    device.limits["bufferImageGranularity"] = "0xffffffffffffffff";
    device.properties2.emplace_back("maxMemoryAllocationSize", QVariant::fromValue(max), "VK_KHR_maintenance3");
    device.properties2.emplace_back("values", QVariantList{ QVariant::fromValue(max), 42u }, "test");

    const QJsonObject report = QJsonDocument::fromJson(QJsonDocument(device.toJson("test", "")).toJson()).object();
    for (const char* name : { "storageTexelBufferOffsetAlignmentBytes", "uniformTexelBufferOffsetAlignmentBytes", "maxBufferSize" }) {
        check(report["core13"].toObject()["properties"].toObject()[name].toString() == "18446744073709551615", "core 1.3 property lost precision");
    }
    check(report["core11"].toObject()["properties"].toObject()["maxMemoryAllocationSize"].toString() == "18446744073709551615", "core 1.1 property changed");
    check(report["core12"].toObject()["properties"].toObject()["maxTimelineSemaphoreValueDifference"].toString() == "18446744073709551615", "core 1.2 property changed");
    check(report["core14"].toObject()["properties"].toObject()["ordinaryValue"].toInt() == 42, "ordinary core property changed");
    check(report["properties"].toObject()["limits"].toObject()["bufferImageGranularity"].toString() == "0xffffffffffffffff", "hex limit changed");
    const QJsonArray extensions = report["extended"].toObject()["deviceproperties2"].toArray();
    check(extensions[0].toObject()["value"].toString() == "18446744073709551615", "extension scalar lost precision");
    const QJsonArray values = extensions[1].toObject()["value"].toArray();
    check(values[0].toString() == "18446744073709551615" && values[1].toInt() == 42, "extension array value changed");
    return EXIT_SUCCESS;
}
