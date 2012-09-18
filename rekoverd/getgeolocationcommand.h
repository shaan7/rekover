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

#ifndef GETGEOLOCATIONCOMMAND_H
#define GETGEOLOCATIONCOMMAND_H

#include "abstractcommand.h"

#include <QtLocation/QGeoPositionInfoSource>

QTM_USE_NAMESPACE

class GetGeolocationCommand : public AbstractCommand
{
    Q_OBJECT
public:
    explicit GetGeolocationCommand(QObject *parent = 0);
    QStringList supportedCommands() const;

public slots:
    void processCommandImpl(const QStringList &commandLine);

private slots:
    void positionUpdated(const QGeoPositionInfo &update);

private:
    QGeoPositionInfoSource *m_geoInfoSource;
};

#endif // GETGEOLOCATIONCOMMAND_H
