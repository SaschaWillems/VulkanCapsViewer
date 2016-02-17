/*
*
* Vulkan hardware capability viewer
*
* Custom sort filter proxy model
*
* Copyright (C) 2015 by Sascha Willems (www.saschawillems.de)
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

#include "treeproxyfilter.h"

TreeProxyFilter::TreeProxyFilter(QObject *parent) : QSortFilterProxyModel(parent)
{
}

bool TreeProxyFilter::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
	if (!filterRegExp().isEmpty())
	{
		QModelIndex index = sourceModel()->index(sourceRow, this->filterKeyColumn(), sourceParent);
		if (index.isValid())
		{
			for (int i = 0; i < sourceModel()->rowCount(index); ++i)
			{
				if (filterAcceptsRow(i, index))
				{
					return true;
				}
			}
			QString key = sourceModel()->data(index, filterRole()).toString();
			return key.contains(filterRegExp());
		}
	}
	return QSortFilterProxyModel::filterAcceptsRow(sourceRow, sourceParent);
}

bool TreeProxyFilter::filterAcceptsRowSelf(int sourceRow, const QModelIndex &sourceParent) const
{
	return QSortFilterProxyModel::filterAcceptsRow(sourceRow, sourceParent);
}

bool TreeProxyFilter::hasAcceptedChildren(int sourceRow, const QModelIndex &sourceParent) const
{
	QModelIndex item = sourceModel()->index(sourceRow, 0, sourceParent);
	if (!item.isValid()) 
	{
		return false;
	}
    return true;
}
