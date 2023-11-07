/*
 *
 * Vulkan hardware capability viewer
 *
 * Copyright (C) 2016-2023 by Sascha Willems (www.saschawillems.de)
 *
 * This code is free software, you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 3 as published by the Free Software Foundation.
 *
 * Please review the following information to ensure the GNU Lesser
 * General Public License version 3 requirements will be met:
 * http://opensource.org/licenses/lgpl-3.0.html
 *
 * The code is distributed WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU LGPL 3.0 for more details.
 *
 */

#include "CustomFilterProxyModel.h"

CustomFilterProxyModel::CustomFilterProxyModel(QObject* parent) : QSortFilterProxyModel(parent)
{ 
};

bool CustomFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const
{
    QModelIndex parent = sourceParent;
    while (parent.parent().isValid()) {
        parent = parent.parent();
    }
    bool itemMatch = false;
    for (int i = 0; i < sourceModel()->columnCount(); i++) {
        QModelIndex index = sourceModel()->index(sourceRow, i, sourceParent);
        itemMatch |= sourceModel()->data(index).toString().contains(filterRegExp());
    }
    bool parentMatch = false;
    QString fr = this->filterRegExp().pattern();
    if (parent.isValid()) {
        parentMatch = parent.data().toString().contains(filterRegExp());
    }
    return (itemMatch || parentMatch);
}