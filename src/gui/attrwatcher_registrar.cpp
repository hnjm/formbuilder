/**************************************************************************************************
 *                                                                                                *
 *    Project:  NextGIS Formbuilder                                                               *
 *    Authors:  Mikhail Gusev, gusevmihs@gmail.com                                                *
 *              Copyright (C) 2014-2019 NextGIS                                                   *
 *                                                                                                *
 *    This program is free software: you can redistribute it and/or modify it under the terms     *
 *    of the GNU General Public License as published by the Free Software Foundation, either      *
 *    version 2 of the License, or (at your option) any later version.                            *
 *                                                                                                *
 *    This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;   *
 *    without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   *
 *    See the GNU General Public License for more details.                                        *
 *                                                                                                *
 *    You should have received a copy of the GNU General Public License along with this program.  *
 *    If not, see http://www.gnu.org/licenses/.                                                   *
 *                                                                                                *
 **************************************************************************************************/

#include "attrwatcher_registrar.h"

using namespace Fb;
using namespace Gui;


QMap<Core::AttrInputType, AttrWatcherFct*> AttrWatcherRegistrar::attr_watchers;

void AttrWatcherRegistrar::add (Core::AttrInputType input_type, AttrWatcherFct *watcher_fct)
{
    if (attr_watchers.contains(input_type))
    {
        //qDebug
        return;
    }
    attr_watchers.insert(input_type, watcher_fct);
}

const AttrWatcherFct *AttrWatcherRegistrar::get (Core::AttrInputType input_type)
{
    if (!attr_watchers.contains(input_type))
    {
        //qDebug
        return nullptr;
    }
    return attr_watchers.value(input_type);
}
