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

#include "stubcommandsource.h"

#include <QtCore/QTimer>

#include <QDebug>

StubCommandSource::StubCommandSource(QObject *parent) :
    AbstractCommandSource(parent)
{
    QTimer::singleShot(2000, this, SLOT(createFakeCommand()));
}

void StubCommandSource::createFakeCommand()
{
    qDebug() << "CREATING FAKE COMMAND";
    emit newCommand("getgeolocation", "0");
}

void StubCommandSource::sendResponseImpl(const QString &response, const QString &incidentId)
{
    qDebug() << "STUB " << incidentId << " " << response;
}
