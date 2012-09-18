/***************************************************************************
 *   Rekover is a tool for your N9/N950 to track it if stolen              *
 *                                                                         *
 *   Copyright 2012 by Shantanu Tushar <shantanu@kde.org>                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include "getgeolocationcommand.h"

#include "abstractcommandsource.h"

#include <QDebug>

GetGeolocationCommand::GetGeolocationCommand(QObject *parent) :
    AbstractCommand(parent),
    m_geoInfoSource(QGeoPositionInfoSource::createDefaultSource(this))
{
    connect(m_geoInfoSource, SIGNAL(positionUpdated(QGeoPositionInfo)), SLOT(positionUpdated(QGeoPositionInfo)));
    if (m_geoInfoSource) {
        qDebug() << "Geo Position Info Source created successfully";
    } else {
        qDebug() << "Failed to create Geo Position Info Source";
    }
}

void GetGeolocationCommand::processCommandImpl(const QStringList &commandLine)
{
    m_geoInfoSource->startUpdates();
}

QStringList GetGeolocationCommand::supportedCommands() const
{
    return QStringList() << "getgeolocation";
}

void GetGeolocationCommand::positionUpdated(const QGeoPositionInfo &update)
{
    qDebug() << "GOT POSITION";
    if (!update.isValid()) {
        m_geoInfoSource->requestUpdate();
        return;
    }

    qDebug() << "GOT POSITION VALID";
    m_geoInfoSource->stopUpdates();
    QString response;
    response.append(update.timestamp().toString());
    response.append(" ");
    response.append(update.coordinate().toString());
    qDebug() << "GOT POSITION " << response;

    sendResponse(response);
}
